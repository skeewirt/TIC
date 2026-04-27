// __Z8evt_flagv @ 0x1956E8 (72 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall evt_flag()
{
  int result; // r0
  int v1; // [sp+0h] [bp-8h] BYREF
  int v2; // [sp+4h] [bp-4h] BYREF

  evt_get_flgdt(&v2, &v1);
  result = Wread_eventflag(v2);
  if ( result != v1 )
    event_inf |= 2u;
  return result;
}

