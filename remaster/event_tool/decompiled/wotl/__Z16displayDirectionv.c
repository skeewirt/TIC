// __Z16displayDirectionv @ 0x134970 (176 bytes)
// WotL iOS - debug symbols

int __fastcall displayDirection()
{
  __int16 *v0; // r4
  int OTptrZ; // r0
  __int16 v3; // [sp+0h] [bp-14h] BYREF
  __int16 v4; // [sp+2h] [bp-12h]
  __int16 v5; // [sp+4h] [bp-10h]
  _BYTE v6[8]; // [sp+8h] [bp-Ch] BYREF

  v0 = (__int16 *)searchCurrentAnimation();
  setShortVector(v6, v0[32], v0[33], v0[34]);
  setPanelPriority(v0 + 32, &v3);
  v4 -= 48;
  OTptrZ = ASHURA_getOTptrZ((dword_12B1750 + (v5 * word_12B1744 + v3 * word_12B1740 + word_12B1742 * v4) / 4096) / 4);
  return drawDirection(v6, OTptrZ);
}

