// __ZL11scroll_initPh @ 0xCA110 (580 bytes)
// WotL iOS - debug symbols

int __fastcall scroll_init(int result)
{
  int v1; // r3
  int v2; // r4
  int v3; // r0
  unsigned int v4; // r6
  int v5; // r0
  int v6; // r12
  int i; // r1
  int v8; // r2
  _BYTE v9[40]; // [sp+0h] [bp-3Ch] BYREF
  __int16 v10; // [sp+28h] [bp-14h] BYREF
  __int16 v11; // [sp+2Ah] [bp-12h]
  __int16 v12; // [sp+2Ch] [bp-10h]
  __int16 v13; // [sp+2Eh] [bp-Eh]
  _WORD vars0[10]; // [sp+30h] [bp-Ch] BYREF

  while ( 1 )
  {
    v1 = *(unsigned __int8 *)result;
    if ( v1 == 16 )
      break;
    if ( v1 == 28 )
      return result;
    result += *(unsigned __int8 *)(result + 1);
  }
  RetuTotal = *(unsigned __int8 *)(result + 4);
  Space = *(unsigned __int8 *)(result + 5);
  v2 = *(unsigned __int8 *)(result + 6);
  MaxLine = *(unsigned __int8 *)(result + 6);
  moji_space = *(_BYTE *)(result + 9);
  v3 = *(unsigned __int8 *)(result + 10);
  moji_total = v3;
  v4 = ((unsigned int)(unsigned __int8)moji_space * v3) >> 2;
  length = v4;
  result = (__int16)v2;
  if ( bRefPos >= bLineTotal )
    bRefPos = bLineTotal - 1;
  if ( bRefPos - bRefLine >= v2 || bRefPos < bRefLine )
    bRefLine = bRefPos;
  if ( (__int16)v2 <= bLineTotal )
  {
    if ( (__int16)v2 > bLineTotal - bRefLine )
      bRefLine = bLineTotal - v2;
  }
  else
  {
    bRefLine = 0;
  }
  if ( bLineTotal <= bRefPos )
    bRefPos = bLineTotal - 1;
  if ( pmes )
  {
    v10 = 256;
    v13 = 16 * v2;
    v12 = v4;
    v11 = 48;
    ClearImage(&v10, 0, 0, 0);
    v5 = 0;
    v6 = MaxLine;
    for ( i = 2 * bRefLine + mes; ; *(_WORD *)&v9[v8] = *(_WORD *)(i - 2) )
    {
      i += 2;
      if ( v5 >= v6 )
        break;
      v8 = 2 * v5++;
    }
    vars0[v5 - 24] = -1;
    v11 = 48;
    v10 = 256;
    v12 = length;
    v13 = Space;
    result = bMakeTextureMessage(pmes, v9, &v10, 0);
  }
  scroll_type = 0;
  WinFlag = 0;
  return result;
}

