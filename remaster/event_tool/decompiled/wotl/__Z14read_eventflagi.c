// __Z14read_eventflagi @ 0x5FDC0 (148 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall read_eventflag(int a1)
{
  int v2; // r8
  int v3; // r6
  char eventflag; // r0
  int result; // r0

  v2 = *evtworkptr;
  hook_read_eventflag(evtworkptr);
  if ( a1 == 34 )
  {
    v3 = read_eventflag(36) & 1;
    eventflag = read_eventflag(35);
    write_eventflag(34, ((eventflag & 7) << 12) + (v3 << 15));
  }
  calcformula(190, 0, 0, 0);
  calcformula(177, 0, a1, 0);
  result = *evtworkptr;
  *evtworkptr = v2;
  return result;
}

