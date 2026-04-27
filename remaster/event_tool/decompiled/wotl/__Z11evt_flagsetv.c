// __Z11evt_flagsetv @ 0x19538C (44 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall evt_flagset()
{
  int v1; // [sp+0h] [bp-8h] BYREF
  int v2; // [sp+4h] [bp-4h] BYREF

  evt_get_flgdt(&v2, &v1);
  return Wwrite_eventflag(v2, v1);
}

