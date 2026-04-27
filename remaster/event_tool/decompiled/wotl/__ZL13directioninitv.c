// __ZL13directioninitv @ 0x5D7C0 (128 bytes)
// WotL iOS - debug symbols

unsigned int __fastcall directioninit()
{
  int v0; // r5
  _BYTE *i; // r4
  unsigned int result; // r0
  int v3; // r3

  v0 = 0;
  for ( i = eventdirec; ; i += 7 )
  {
    i[4] = 0;
    i[6] = 0;
    result = checkAnimationExist(v0);
    if ( result )
    {
      result = getAnimationDirection16(v0);
      i[5] = result;
    }
    else
    {
      i[5] = -1;
    }
    v3 = 2 * v0++;
    *(_WORD *)((char *)&movestopanm + v3) = 0;
    *(_WORD *)((char *)&movestoprsv + v3) = 0;
    if ( v0 == 21 )
      break;
  }
  return result;
}

