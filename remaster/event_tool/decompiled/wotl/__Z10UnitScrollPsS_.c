// __Z10UnitScrollPsS_ @ 0x1047E8 (196 bytes)
// WotL iOS - debug symbols

__int16 *__fastcall UnitScroll(__int16 *result, __int16 *a2)
{
  __int16 v2; // r3
  int v3; // r3
  __int16 v4; // r3
  __int16 v5; // r3
  __int16 v6; // r3

  v2 = *result;
  if ( *result )
  {
    if ( *result < 0 )
    {
      v4 = v2 - 4;
      *result = v4;
      if ( v4 > -60 )
        return result;
      *result = 0;
      v5 = *a2 - 60;
    }
    else
    {
      v6 = v2 + 4;
      *result = v6;
      if ( v6 <= 59 )
        return result;
      *result = 0;
      v5 = *a2 + 60;
    }
    *a2 = v5;
  }
  else
  {
    v3 = CurChr / 5 - *a2 / -60;
    if ( v3 >= 0 )
    {
      if ( v3 > 2 )
        *result = -4;
    }
    else
    {
      *result = 4;
    }
  }
  return result;
}

