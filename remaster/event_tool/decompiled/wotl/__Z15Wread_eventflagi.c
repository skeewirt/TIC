// __Z15Wread_eventflagi @ 0x48214 (148 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall Wread_eventflag(int a1)
{
  int v2; // r8
  int v3; // r6
  char v4; // r0
  int result; // r0

  v2 = *wevtworkptr;
  hook_read_eventflag(wevtworkptr);
  if ( a1 == 34 )
  {
    v3 = Wread_eventflag(36) & 1;
    v4 = Wread_eventflag(35);
    Wwrite_eventflag(34, ((v4 & 7) << 12) + (v3 << 15));
  }
  Wcalcformula(190, 0, 0, 0);
  Wcalcformula(177, 0, a1, 0);
  result = *wevtworkptr;
  *wevtworkptr = v2;
  return result;
}

