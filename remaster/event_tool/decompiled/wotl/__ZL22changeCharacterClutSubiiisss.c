// __ZL22changeCharacterClutSubiiisss @ 0x159E84 (304 bytes)
// WotL iOS - debug symbols

int __fastcall changeCharacterClutSub(int a1, int a2, unsigned int a3, __int16 a4, __int16 a5, __int16 a6)
{
  int result; // r0
  int v9; // r5
  int mapstp; // r4
  unsigned int v11; // r3
  _WORD v14[4]; // [sp+18h] [bp-20h] BYREF

  result = searchAnimationByID(a3);
  v9 = result;
  if ( result )
  {
    setAnimationRealVector(v14, result);
    mapstp = get_mapstp(v14[0] / 28, v14[2] / 28, *(unsigned __int8 *)(v9 + 126));
    requestChangeClut(a1, a2, 3u, a3, 0, a4, a5, a6);
    if ( mapstp
      && (v11 = *(unsigned __int8 *)(mapstp + 6), (v11 & 0xE0) != 0)
      && *(__int16 *)(v9 + 66) >= (int)(-12 * (*(unsigned __int8 *)(mapstp + 5) + (v11 >> 5))) )
    {
      return requestChangeClut(a1, a2, 4u, a3, 0, a4, a5, a6);
    }
    else
    {
      return requestChangeClut(a1, a2, 4u, a3, 0, -a4, -a5, -a6);
    }
  }
  return result;
}

