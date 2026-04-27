// j___minievent @ 0x140224170 (542 bytes)

__int64 sub_140223F80()
{
  int v0; // edx
  int v1; // r8d
  unsigned int v2; // r9d
  unsigned __int16 *v3; // r11
  int v4; // r10d

  v0 = (unsigned __int8)xmmword_14077D210;
  v1 = WORD2(xmmword_14077D210);
  LODWORD(xmmword_142FCCF38) = (unsigned __int8)xmmword_14077D210;
  v2 = BYTE2(xmmword_14077D210);
  if ( (unsigned __int8)xmmword_14077D210 == 18 || (xmmword_14077D210 & 0xFE) == 0xFE )
    return v0 | (((v1 << 8) | (unsigned int)(unsigned __int8)v2) << 8);
  v3 = (unsigned __int16 *)&unk_1407D6CA0;
  v4 = 0;
  while ( dword_14077CD0C != *v3 )
  {
    ++v4;
    v3 += 8;
    if ( (__int64)v3 >= (__int64)&unk_1407D6E90 )
      goto LABEL_16;
  }
  if ( (unsigned __int8)xmmword_14077D210 == 255 )
  {
    v0 = **((unsigned __int8 **)&unk_1407D6CA0 + 2 * v4 + 1);
  }
  else
  {
    if ( dword_14077CD0C == 105 )
    {
      v0 = dword_140D3A524;
      WORD6(xmmword_142FCCF38) = dword_140D3A518;
    }
    else
    {
      if ( dword_14077CD0C != 25 && dword_14077CD0C < 100 )
      {
        v0 = *(unsigned __int8 *)(*((_QWORD *)&unk_1407D6CA0 + 2 * v4 + 1) + (unsigned __int8)xmmword_14077D210 + 1LL);
        goto LABEL_16;
      }
      v0 = *(unsigned __int8 *)(*((_QWORD *)&unk_1407D6CA0 + 2 * v4 + 1) + BYTE2(xmmword_14077D210) + 1LL);
    }
    v2 = 65534;
  }
LABEL_16:
  if ( v4 == 31 )
  {
    v0 = 7;
  }
  else
  {
    if ( v4 >= 16 )
    {
      if ( v0 == 5 || v0 == 6 )
        BYTE14(xmmword_142FCCF38) = v0;
    }
    else
    {
      dword_142FCCF30 = v0;
    }
    if ( v0 == 1 )
    {
      byte_142FC930B = 1;
    }
    else if ( v0 == 12 )
    {
      if ( v2 > 2 )
        v0 = v2 + 13;
      else
        v0 = WORD2(xmmword_14077D210) + 10 + 2 * v2;
      LOBYTE(v2) = -2;
      dword_142FCCF30 = v0;
      v1 = 65534;
      LODWORD(xmmword_142FCCF38) = v0;
      return v0 | (((v1 << 8) | (unsigned int)(unsigned __int8)v2) << 8);
    }
  }
  LODWORD(xmmword_142FCCF38) = v0;
  if ( (v2 & 0xFE) != 0xFE )
  {
    v2 = *((unsigned __int8 *)&qword_140D3A3F0 + BYTE2(xmmword_14077D210));
    if ( v2 - 5 <= 0xB || v2 >= 0x13 )
    {
      if ( v2 != 188 || dword_142FCCF50 )
      {
        if ( WORD2(xmmword_14077D210) < 0x52u )
          v1 = *(_WORD *)(qword_141844568 + 2LL * WORD2(xmmword_14077D210)) & 0x1FF;
      }
      else
      {
        v1 = 0;
      }
    }
    else
    {
      v1 = 65534;
      WORD3(xmmword_142FCCF38) = 0;
    }
    BYTE5(xmmword_142FCCF38) = v2;
    dword_142FCAF4C = v2;
    if ( v1 != 65534 )
    {
      if ( v2 == 6 || v2 - 19 <= 1 )
        WORD6(xmmword_142FCCF38) = v1;
      else
        WORD3(xmmword_142FCCF38) = v1;
      dword_1407D6144 = v1;
    }
  }
  return v0 | (((v1 << 8) | (unsigned int)(unsigned __int8)v2) << 8);
}

