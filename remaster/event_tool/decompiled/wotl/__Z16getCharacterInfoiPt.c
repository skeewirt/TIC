// __Z16getCharacterInfoiPt @ 0x155C08 (244 bytes)
// WotL iOS - debug symbols

int __fastcall getCharacterInfo(unsigned __int16 a1, unsigned __int16 *a2)
{
  int result; // r0
  unsigned __int16 v4; // r3
  int v5; // r12
  int v6; // r2
  int v7; // r3
  bool v8; // zf

  result = searchAnimationByID(a1);
  if ( result )
  {
    *a2 = *(_WORD *)(result + 18);
    if ( (unsigned __int8)(*(_BYTE *)(result + 6) + 101) > 3u )
    {
      v5 = *(unsigned __int8 *)(result + 5);
      if ( (unsigned int)(v5 - 9) <= 5 )
      {
        v6 = *(unsigned __int16 *)(result + 16);
        v7 = ((v6 << 6) & 0x3C0) == 0x40 && (v6 & 0x10) != 0;
        v8 = v7 == 0;
        if ( v7 )
          LOWORD(v7) = v5 - 7;
        else
          a2[1] = v6;
        if ( v8 )
          goto LABEL_16;
        v4 = v6 | ((_WORD)v7 << 12);
      }
      else
      {
        v4 = *(_WORD *)(result + 16);
      }
    }
    else
    {
      v4 = 11;
    }
    a2[1] = v4;
LABEL_16:
    a2[2] = charTypeTable[4 * *(unsigned __int8 *)(result + 6) + 3];
    a2[3] = *(_WORD *)(result + 122);
    if ( *(_BYTE *)(result + 304) == 1 )
      return *(_DWORD *)(4 * *(unsigned __int16 *)(result + 488) + *(_DWORD *)(result + 508) + 840);
    else
      return *(_DWORD *)(4 * *(unsigned __int16 *)(result + 488) + *(_DWORD *)(result + 508) + 8);
  }
  return result;
}

