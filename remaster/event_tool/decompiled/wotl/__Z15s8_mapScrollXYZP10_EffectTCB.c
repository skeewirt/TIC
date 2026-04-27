// __Z15s8_mapScrollXYZP10_EffectTCB @ 0x165018 (96 bytes)
// WotL iOS - debug symbols

int __fastcall s8_mapScrollXYZ(int a1)
{
  __int16 *v2; // r3
  _DWORD v4[4]; // [sp+0h] [bp-14h] BYREF

  v2 = (__int16 *)(*(__int16 *)(a1 + 6) + *(_DWORD *)(a1 + 8));
  v4[0] = v2[1] << 12;
  v4[1] = v2[2] << 12;
  v4[2] = v2[3] << 12;
  setMapScrollXYZ(v4);
  *(_WORD *)(a1 + 6) += 8;
  return 1;
}

