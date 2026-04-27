// __ZL14ScrollNameFuncPh @ 0x10FEC0 (2012 bytes)
// WotL iOS - debug symbols

unsigned __int8 *__fastcall ScrollNameFunc(unsigned __int8 *a1)
{
  unsigned __int8 *v1; // r8
  unsigned __int16 v2; // r4
  int v3; // r4
  int v4; // r5
  __int16 v5; // r10
  int v6; // r11
  int v7; // r0
  int v8; // r0
  int v9; // r4
  __int16 v10; // r3
  int v11; // r2
  char *v12; // r3
  int v13; // r2
  int v14; // r3
  int v15; // r10
  int v16; // r5
  int v17; // r6
  int v18; // r4
  int v19; // r0
  int v20; // r1
  int v21; // r6
  unsigned __int8 *v22; // r11
  int v23; // r10
  int j; // r4
  int v25; // r1
  int v27; // [sp+2Ch] [bp-38h]
  signed __int8 v28; // [sp+30h] [bp-34h]
  int v29; // [sp+34h] [bp-30h]
  int i; // [sp+38h] [bp-2Ch]
  __int16 v31; // [sp+3Ch] [bp-28h] BYREF
  __int16 v32; // [sp+3Eh] [bp-26h]
  __int16 v33; // [sp+40h] [bp-24h]
  __int16 v34; // [sp+42h] [bp-22h]
  _WORD v35[2]; // [sp+44h] [bp-20h] BYREF
  _DWORD (__fastcall *v36)(unsigned __int8 *); // [sp+48h] [bp-1Ch]

  v1 = a1;
  v2 = OtNum;
  if ( LineTotal <= 0 )
  {
    v3 = 1;
    v4 = a1[4] + 2;
    do
    {
      ++v3;
      v1 = (unsigned __int8 *)FuncSkip(v1);
    }
    while ( v3 != v4 );
    return v1;
  }
  v5 = (unsigned __int8)(GetFrameRate() / 2);
  ScrollState = 1;
  if ( WinFlag )
    scroll_init(v1);
  v6 = v2;
  v27 = (unsigned __int16)RefPos;
  if ( !scroll_type )
  {
    v7 = PageSkipChk();
    if ( !v7 )
    {
      if ( iOS_ScrollTest == 1 )
      {
        iOS_ScrollTest = 0;
        RefPos = RefLine;
        if ( RefLine <= 0 )
          goto LABEL_21;
        scroll_type = -1;
        v8 = pmes;
        if ( !pmes )
          goto LABEL_22;
        ScrollNameFunc(unsigned char *)::meslist = *(_WORD *)(2 * RefLine + mes - 2);
        v31 = 576;
        v32 = 288;
        v33 = length;
        v34 = Space;
      }
      else
      {
        if ( iOS_ScrollTest != 2 )
        {
          ScrollNameFunc(unsigned char *)::scroll_count = 0;
          goto LABEL_21;
        }
        iOS_ScrollTest = 0;
        RefPos = RefLine + MaxLine - 1;
        if ( RefPos >= LineTotal - 1 )
          goto LABEL_21;
        scroll_type = 1;
        v8 = pmes;
        if ( !pmes )
          goto LABEL_32;
        ScrollNameFunc(unsigned char *)::meslist = *(_WORD *)(2 * RefPos + mes + 2);
        v31 = 576;
        v34 = Space;
        v32 = Space * MaxLine + 304;
        v33 = length;
      }
      MakeTextureMessage(v8, &ScrollNameFunc(unsigned char *)::meslist, &v31, 0);
      goto LABEL_21;
    }
    if ( v7 != 2 )
      PageSkip(v7, v1);
  }
LABEL_21:
  if ( (scroll_type & 0x80) == 0 )
  {
    if ( !scroll_type )
      goto LABEL_38;
LABEL_32:
    if ( (unsigned __int16)ScrollNameFunc(unsigned char *)::scroll_count < (unsigned int)(unsigned __int8)scroll2_delay )
    {
      ScrollNameFunc(unsigned char *)::scroll_count += v5;
      v12 = &scroll1_speed;
    }
    else
    {
      v12 = &scroll2_speed;
    }
    ScrollFlag += (unsigned __int8)*v12 * v5;
    if ( ScrollFlag > 23 )
    {
      ScrollFlag = 0;
      scroll_type = 0;
      ++RefLine;
      ++RefPos;
      if ( pmes )
      {
        v31 = 576;
        v32 = Space + 304;
        v33 = length;
        v34 = MaxLine * Space;
        DrawMove(&v31, 576, 304, v2 - 1);
        goto LABEL_38;
      }
      goto LABEL_51;
    }
LABEL_38:
    if ( pmes )
    {
      v28 = v1[7];
      v13 = (char)v1[8];
      v29 = MaxLine;
      v14 = (unsigned __int16)ScrollFlag;
      if ( ScrollFlag )
      {
        if ( ScrollFlag >= 0 )
        {
          v6 = v13 - ScrollFlag;
          v14 = 0;
        }
        v29 = MaxLine + 1;
        if ( ScrollFlag < 0 )
        {
          v6 = v13 - 24 - ScrollFlag;
          v14 = -Space;
        }
      }
      else
      {
        v6 = (char)v1[8];
      }
      v15 = v14 + 48;
      for ( i = 0; v29 > i; ++i )
      {
        v16 = 0;
        v17 = 0;
        v18 = 0;
        while ( 1 )
        {
          v19 = v18 + v28;
          v18 += 13;
          if ( v16 >= (unsigned __int8)moji_total )
            break;
          v17 += 6;
          ++v16;
          DrawFT4RGB2(v19, v6);
        }
        v6 += 24;
        v15 += 16;
      }
    }
    goto LABEL_51;
  }
LABEL_22:
  if ( (unsigned __int16)ScrollNameFunc(unsigned char *)::scroll_count < (unsigned int)(unsigned __int8)scroll2_delay )
  {
    ScrollNameFunc(unsigned char *)::scroll_count += v5;
    ScrollFlag -= (unsigned __int8)scroll1_speed * v5;
  }
  else
  {
    ScrollFlag -= v5 * (unsigned __int8)scroll2_speed;
  }
  if ( ScrollFlag > -24 )
    goto LABEL_38;
  ScrollFlag = 0;
  scroll_type = 0;
  RefLine = --RefPos;
  if ( pmes )
  {
    v9 = 0;
    while ( v9 < MaxLine )
    {
      v31 = 576;
      v34 = Space;
      v10 = (v9 - 1) * Space;
      v11 = Space * v9++;
      v32 = v10 + 304;
      v33 = length;
      DrawMove(&v31, 576, v11 + 304, v6 - 1);
    }
    goto LABEL_38;
  }
LABEL_51:
  if ( v1[2] && iOS_dispCursor_window_unitlist )
  {
    v35[0] = (char)v1[7] - v1[11];
    v35[1] = (char)v1[8] + Space * (RefPos - RefLine);
    CursolFunc(v35, &ScrollNameFunc(unsigned char *)::time, (unsigned __int8)window_type);
  }
  v20 = v1[1];
  v21 = 0;
  ScrollCount = 0;
  v22 = &v1[v20];
  v1 += v20;
  v23 = MaxLine + 1;
  if ( !ScrollFlag )
    v23 = MaxLine;
  while ( v21 < v23 && (v21 + RefLine <= LineTotal - 1 || ScrollFlag) )
  {
    v1 = v22;
    for ( j = 0; j < RetuTotal; ++j )
    {
      v36 = DrawFunc[*v1];
      v1 = (unsigned __int8 *)v36(v1);
    }
    ++v21;
    ++ScrollCount;
  }
  ScrollState = 0;
  v25 = RefPos - v27;
  if ( v25 < 0 )
    v25 = v27 - RefPos;
  if ( v25 == 1 )
  {
    TRACE_Dummy("SysSnd %d %d:%d\n", 1775, (unsigned __int16)v27, RefPos);
    SysSnd = 3;
  }
  return v1;
}

