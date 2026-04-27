// __Z16Wwrite_eventflagii @ 0x48538 (120 bytes)
// WotL iOS - debug symbols, no obfuscation

int *__fastcall Wwrite_eventflag(int a1, int a2)
{
  int v3; // r5
  int v4; // r8
  int *result; // r0

  v3 = a2;
  if ( a2 < 0 )
    v3 = (unsigned __int8)a2;
  v4 = *wevtworkptr;
  hook_write_eventflag(wevtworkptr);
  if ( a1 == 44 && v3 >= 99999999 )
    v3 = 99999999;
  Wcalcformula(190, a1, 0, 0);
  Wcalcformula(176, a1, v3, 0);
  result = wevtworkptr;
  *wevtworkptr = v4;
  return result;
}

