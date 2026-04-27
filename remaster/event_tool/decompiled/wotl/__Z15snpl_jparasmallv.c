// __Z15snpl_jparasmallv @ 0x1A73F4 (116 bytes)
// WotL iOS - debug symbols

int *__fastcall snpl_jparasmall()
{
  int v0; // r2
  int *result; // r0

  v0 = word_12FBAF6 + dword_12FBB18;
  if ( v0 <= 0xFFFF )
  {
    if ( v0 < 0 )
      goto LABEL_6;
  }
  else
  {
    v0 = 0xFFFF;
  }
  result = &snpl_copy;
  if ( v0 > (int)((unsigned int)(dword_12FBAEC << 8) >> 16) )
  {
    word_12FBAF2 = HIBYTE(dword_12FBAEC);
    word_12FBAF0 |= 2u;
    return result;
  }
LABEL_6:
  word_12FBAF0 |= 4u;
  return result;
}

