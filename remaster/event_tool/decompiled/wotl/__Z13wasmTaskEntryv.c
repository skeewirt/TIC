// __Z13wasmTaskEntryv @ 0x2F860 (104 bytes)
// WotL iOS - debug symbols

int __fastcall wasmTaskEntry()
{
  char *v0; // r2

  v0 = (char *)wasmtaskframeptr + 1024 * wasmtasknumber;
  while ( ++wasmtasknumber != 16 )
  {
    v0 += 1024;
    if ( *((_DWORD *)v0 + 18) )
      goto LABEL_6;
  }
  wasmtasknumber = 0;
LABEL_6:
  tutorial_hookfunc();
  return TE_asmTaskEntry(0);
}

