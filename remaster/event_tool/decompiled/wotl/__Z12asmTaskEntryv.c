// __Z12asmTaskEntryv @ 0x2F508 (104 bytes)
// WotL iOS - debug symbols

int __fastcall asmTaskEntry()
{
  char *v0; // r2

  v0 = (char *)asmtaskframeptr + 1024 * asmtasknumber;
  while ( ++asmtasknumber != 16 )
  {
    v0 += 1024;
    if ( *((_DWORD *)v0 + 18) )
      goto LABEL_6;
  }
  asmtasknumber = 0;
LABEL_6:
  tutorial_hookfunc();
  return TE_asmTaskEntry(0);
}

