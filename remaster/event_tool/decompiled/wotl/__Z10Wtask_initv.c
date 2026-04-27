// __Z10Wtask_initv @ 0xA5190 (76 bytes)
// WotL iOS - debug symbols

_UNKNOWN **__fastcall Wtask_init()
{
  _UNKNOWN **result; // r0
  int i; // r3

  result = &wasmtaskframeptr;
  *(_DWORD *)wasmtaskframeptr = 0;
  for ( i = 4; i != 17408; i += 4 )
    *(_DWORD *)((char *)wasmtaskframeptr + i) = 0;
  wasmtasknumber = 0;
  *((_DWORD *)wasmtaskframeptr + 18) = 1;
  return result;
}

