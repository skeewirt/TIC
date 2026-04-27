"""
TIC Event Script Utilities v1.0
Phase 1 companion tools: diff, list, and modloader packaging.

Usage:
    python tic_event_tools.py diff event002.e event002_modified.e
    python tic_event_tools.py list [--messages message_map.json]
    python tic_event_tools.py pack event002.json -o MyMod/
"""
import struct, json, sys, os, argparse, shutil
sys.stdout.reconfigure(encoding='utf-8', errors='replace')

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, SCRIPT_DIR)

from tic_event_disasm import (
    load_opcode_names, disassemble_file, to_json, format_instruction,
    OPERAND_SIGS_ENHANCED, OPERAND_SIGS_CLASSIC
)

DEFAULT_TABLE = os.path.join(SCRIPT_DIR, 'opcode_table.json')
DEFAULT_SCRIPTS = os.path.join(SCRIPT_DIR, '..', '..', 'reference', 'event_scripts', 'script', 'enhanced')
DEFAULT_MESSAGES = os.path.join(SCRIPT_DIR, '..', '..', 'reference', 'message_map.json')


# ─────────────────────────────────────────────────────
# DIFF: Compare two event scripts instruction-by-instruction
# ─────────────────────────────────────────────────────
def cmd_diff(args):
    names, _, sizes_enhanced = load_opcode_names(args.table)
    sigs = OPERAND_SIGS_ENHANCED

    messages = None
    if args.messages and os.path.exists(args.messages):
        with open(args.messages, encoding='utf-8') as f:
            messages = json.load(f)

    instrs_a, end_a, data_a = disassemble_file(args.file_a, 'enhanced', names, sizes_enhanced, sigs, messages)
    instrs_b, end_b, data_b = disassemble_file(args.file_b, 'enhanced', names, sizes_enhanced, sigs, messages)

    fname_a = os.path.basename(args.file_a)
    fname_b = os.path.basename(args.file_b)

    # Binary-level comparison first
    if data_a == data_b:
        print(f"✅ {fname_a} and {fname_b} are byte-identical.")
        return

    print(f"--- {fname_a}  ({len(data_a)} bytes, {end_a} instructions)")
    print(f"+++ {fname_b}  ({len(data_b)} bytes, {end_b} instructions)")
    print()

    max_len = max(end_a, end_b)
    diff_count = 0

    for i in range(max_len):
        a = instrs_a[i] if i < end_a else None
        b = instrs_b[i] if i < end_b else None

        if a and b and a['raw'] == b['raw']:
            if args.context:
                # Show context lines (unchanged)
                pass
            continue

        diff_count += 1

        if a and not b:
            line_a = format_instruction(a, True)
            print(f"  #{i:3d}  - {line_a}")
        elif b and not a:
            line_b = format_instruction(b, True)
            print(f"  #{i:3d}  + {line_b}")
        else:
            line_a = format_instruction(a, True)
            line_b = format_instruction(b, True)
            print(f"  #{i:3d}  - {line_a}")
            print(f"  #{i:3d}  + {line_b}")

    # Size difference
    size_diff = len(data_b) - len(data_a)
    sign = '+' if size_diff > 0 else ''
    print(f"\n  {diff_count} instruction(s) changed, {sign}{size_diff} bytes")


# ─────────────────────────────────────────────────────
# LIST: Catalog all event scripts with metadata
# ─────────────────────────────────────────────────────
def cmd_list(args):
    names, _, sizes_enhanced = load_opcode_names(args.table)
    sigs = OPERAND_SIGS_ENHANCED

    messages = None
    if args.messages and os.path.exists(args.messages):
        with open(args.messages, encoding='utf-8') as f:
            messages = json.load(f)

    scripts_dir = args.scripts or DEFAULT_SCRIPTS
    files = sorted(f for f in os.listdir(scripts_dir) if f.endswith('.e'))

    if args.format == 'json':
        catalog = []

    # Header
    if args.format != 'json':
        print(f"{'Event':<14s} {'Bytes':>6s} {'Instrs':>6s} {'Msgs':>5s} {'First Dialogue'}")
        print(f"{'─'*14} {'─'*6} {'─'*6} {'─'*5} {'─'*50}")

    for fname in files:
        fpath = os.path.join(scripts_dir, fname)
        instrs, code_end, data = disassemble_file(fpath, 'enhanced', names, sizes_enhanced, sigs, messages)

        event_id = fname.replace('event', '').replace('.e', '')

        # Count dialogue instructions and find first message text
        msg_count = 0
        first_dialogue = ''
        has_camera = False
        has_movement = False
        has_branching = False

        for instr in instrs[:code_end]:
            op = instr['opcode']

            # Dialogue
            if op == 0x10:  # DisplayMessage
                msg_count += 1
                if not first_dialogue and instr.get('dialogue'):
                    first_dialogue = instr['dialogue']

            # Camera
            if op in (0x19, 0x73, 0x1D, 0x1E):
                has_camera = True

            # Movement
            if op in (0x28, 0x70):
                has_movement = True

            # Branching
            if op in (0xD0, 0xD1, 0xD3):
                has_branching = True

        if args.format == 'json':
            entry = {
                'event_id': int(event_id) if event_id.isdigit() else event_id,
                'file': fname,
                'size_bytes': len(data),
                'instructions': code_end,
                'dialogue_count': msg_count,
                'has_camera': has_camera,
                'has_movement': has_movement,
                'has_branching': has_branching,
            }
            if first_dialogue:
                entry['first_dialogue'] = first_dialogue
            catalog.append(entry)
        else:
            # Truncate dialogue for display
            diag_display = first_dialogue[:50] if first_dialogue else '—'
            print(f"{fname:<14s} {len(data):>6d} {code_end:>6d} {msg_count:>5d} {diag_display}")

    if args.format == 'json':
        if args.output:
            os.makedirs(os.path.dirname(args.output) or '.', exist_ok=True)
            with open(args.output, 'w', encoding='utf-8') as f:
                json.dump(catalog, f, indent=2, ensure_ascii=False)
            print(f"Wrote {len(catalog)} events to {args.output}")
        else:
            print(json.dumps(catalog, indent=2, ensure_ascii=False))
    else:
        # Summary
        total_msgs = sum(1 for f in files for _ in [None])  # placeholder
        print(f"\n  {len(files)} event scripts")


# ─────────────────────────────────────────────────────
# PACK: Package compiled events for the modloader
# ─────────────────────────────────────────────────────
def cmd_pack(args):
    from tic_event_asm import assemble, load_opcode_sigs

    opcode_sigs = load_opcode_sigs(args.table, 'enhanced')
    mod_name = args.mod_name or 'fftivc.events.mymod'

    # Collect input files
    if os.path.isfile(args.input):
        json_files = [args.input]
    elif os.path.isdir(args.input):
        json_files = sorted(
            os.path.join(args.input, f)
            for f in os.listdir(args.input)
            if f.endswith('.json')
        )
    else:
        print(f"ERROR: {args.input} not found", file=sys.stderr)
        return

    if not json_files:
        print("No .json files found.", file=sys.stderr)
        return

    # Build mod folder structure
    out_base = args.output or mod_name
    script_dir = os.path.join(out_base, 'FFTIVC', 'data', 'enhanced', 'script')
    os.makedirs(script_dir, exist_ok=True)

    compiled = 0
    for json_path in json_files:
        with open(json_path, 'r', encoding='utf-8') as f:
            event_json = json.load(f)

        binary = assemble(event_json, opcode_sigs)

        # Determine output filename
        source = event_json.get('source', os.path.basename(json_path))
        out_name = source.replace('.json', '.e') if source.endswith('.json') else source
        if not out_name.endswith('.e'):
            out_name += '.e'

        out_path = os.path.join(script_dir, out_name)
        with open(out_path, 'wb') as f:
            f.write(binary)
        compiled += 1

    # Create a minimal ModConfig.json if it doesn't exist
    config_path = os.path.join(out_base, 'ModConfig.json')
    if not os.path.exists(config_path):
        config = {
            "ModId": mod_name,
            "ModName": args.mod_name or "My Event Mod",
            "ModAuthor": "TIC Event Tools",
            "ModVersion": "1.0.0",
            "ModDescription": f"Custom event scripts ({compiled} events)",
            "ModDll": "",
            "ModIcon": "",
            "IsLibrary": False,
            "IsUniversalMod": False,
            "ModDependencies": ["fftivc.utility.modloader"],
            "OptionalDependencies": [],
            "SupportedAppId": ["fft_enhanced.exe"],
            "ProjectUrl": ""
        }
        with open(config_path, 'w', encoding='utf-8') as f:
            json.dump(config, f, indent=2)

    print(f"✅ Packaged {compiled} event(s) into: {out_base}/")
    print(f"   Scripts:    {script_dir}/")
    print(f"   ModConfig:  {config_path}")
    print(f"\n   To install: drag the '{os.path.basename(out_base)}' folder into Reloaded-II")


# ─────────────────────────────────────────────────────
# CLI ENTRY
# ─────────────────────────────────────────────────────
def main():
    parser = argparse.ArgumentParser(
        description='TIC Event Script Utilities',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  %(prog)s diff event002.e event002_mod.e
  %(prog)s list --messages reference/message_map.json
  %(prog)s list --format json -o event_catalog.json
  %(prog)s pack modified_events/ -o MyEventMod/
        """
    )
    sub = parser.add_subparsers(dest='command', help='Command to run')

    # ── diff ──
    p_diff = sub.add_parser('diff', help='Compare two event scripts')
    p_diff.add_argument('file_a', help='First .e file')
    p_diff.add_argument('file_b', help='Second .e file')
    p_diff.add_argument('--context', action='store_true', help='Show context lines')
    p_diff.add_argument('--messages', default=DEFAULT_MESSAGES)
    p_diff.add_argument('--table', default=DEFAULT_TABLE)

    # ── list ──
    p_list = sub.add_parser('list', help='List all event scripts with metadata')
    p_list.add_argument('--scripts', help='Path to event scripts directory')
    p_list.add_argument('--format', choices=['text', 'json'], default='text')
    p_list.add_argument('-o', '--output', help='Output file (for JSON format)')
    p_list.add_argument('--messages', default=DEFAULT_MESSAGES)
    p_list.add_argument('--table', default=DEFAULT_TABLE)

    # ── pack ──
    p_pack = sub.add_parser('pack', help='Package events for Reloaded-II modloader')
    p_pack.add_argument('input', help='Input .json file or directory of .json files')
    p_pack.add_argument('-o', '--output', help='Output mod folder')
    p_pack.add_argument('--mod-name', help='Mod identifier (e.g. fftivc.events.mymod)')
    p_pack.add_argument('--table', default=DEFAULT_TABLE)

    args = parser.parse_args()

    if args.command == 'diff':
        cmd_diff(args)
    elif args.command == 'list':
        cmd_list(args)
    elif args.command == 'pack':
        cmd_pack(args)
    else:
        parser.print_help()


if __name__ == '__main__':
    main()
