// __Z9task_initv @ 0x1D049C (76 bytes)
// WotL iOS - debug symbols

_UNKNOWN **__fastcall task_init()
{
  _UNKNOWN **result; // r0
  int i; // r3

  result = &asmtaskframeptr;
  *(_DWORD *)asmtaskframeptr = 0;
  for ( i = 4; i != 17408; i += 4 )
    *(_DWORD *)((char *)asmtaskframeptr + i) = 0;
  asmtasknumber = 0;
  *((_DWORD *)asmtaskframeptr + 18) = 1;
  return result;
}

