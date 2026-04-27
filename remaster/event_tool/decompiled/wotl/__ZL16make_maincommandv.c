// __ZL16make_maincommandv @ 0x4EB78 (116 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn make_maincommand()
{
  int Input1; // r0
  int v1; // r5
  int v2; // r6

  TRACE_Dummy("make_maincommand\n");
  Input1 = wasmGetInput1();
  v1 = 17 * word_271BAE;
  v2 = Input1;
  change_maincommand();
  *((_DWORD *)&asmtaskframe + 256 * wasmtasknumber + 1) = 1;
  Wdisp_selectwindow();
  iOS_v2menuSetType(0);
  cursv[v1] = *(_WORD *)(v2 + 56);
  Wtask_killmyself();
}

