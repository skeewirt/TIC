// __Z15write_eventflagii @ 0x601AC (120 bytes)
// WotL iOS - debug symbols, no obfuscation

int *__fastcall write_eventflag(int a1, int a2)
{
  int v3; // r5
  int v4; // r8
  int *result; // r0

  v3 = a2;
  if ( a2 < 0 )
    v3 = (unsigned __int8)a2;
  v4 = *evtworkptr;
  hook_write_eventflag(evtworkptr);
  if ( a1 == 44 && v3 >= 99999999 )
    v3 = 99999999;
  calcformula(190, a1, 0, 0);
  calcformula(176, a1, v3, 0);
  result = evtworkptr;
  *evtworkptr = v4;
  return result;
}

