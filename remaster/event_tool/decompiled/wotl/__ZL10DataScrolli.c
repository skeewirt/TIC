// __ZL10DataScrolli @ 0xB991C (200 bytes)
// WotL iOS - debug symbols

int __fastcall DataScroll(int result)
{
  __int16 v1; // r3
  __int16 v2; // r2
  __int16 v3; // r3

  v1 = scroll;
  if ( scroll )
  {
    if ( scroll < 0 )
    {
      scroll -= 14;
      if ( (__int16)(v1 - 14) > -56 )
        return result;
      scroll = 0;
      v3 = topy - 56;
    }
    else
    {
      scroll += 14;
      if ( (__int16)(v1 + 14) <= 55 )
        return result;
      scroll = 0;
      v3 = topy + 56;
    }
    topy = v3;
  }
  else
  {
    v2 = topdatano;
    if ( topdatano > result )
    {
      scroll = 14;
      --topdatano;
      --v2;
    }
    if ( result >= v2 + 4 )
    {
      scroll = -14;
      topdatano = v2 + 1;
    }
  }
  return result;
}

