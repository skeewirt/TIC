// __ZL10ScrollFuncPh_2 @ 0x1107D4 (2592 bytes)
// WotL iOS - debug symbols

unsigned __int8 *__fastcall ScrollFunc(unsigned __int8 *a1)
{
  unsigned __int8 *v1; // r6
  unsigned __int16 v2; // r4
  int v3; // r4
  int v4; // r5
  int FrameRate; // r0
  __int16 v6; // r10
  int v7; // r11
  int v8; // r0
  __int16 v9; // r3
  __int16 v10; // r2
  int v11; // r4
  __int16 v12; // r3
  int v13; // r2
  char *v14; // r3
  int v15; // r8
  int v16; // r1
  __int16 v17; // r3
  int v18; // r2
  __int16 v19; // r3
  int v20; // r4
  int v21; // r0
  int v22; // r1
  int v23; // r8
  unsigned __int8 *v24; // r11
  int v25; // r10
  int i; // r4
  int v28; // [sp+14h] [bp-2Ch]
  __int16 v29; // [sp+18h] [bp-28h] BYREF
  __int16 v30; // [sp+1Ah] [bp-26h]
  __int16 v31; // [sp+1Ch] [bp-24h]
  __int16 v32; // [sp+1Eh] [bp-22h]
  _WORD v33[2]; // [sp+20h] [bp-20h] BYREF
  _DWORD (__fastcall *v34)(unsigned __int8 *); // [sp+24h] [bp-1Ch]

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
  FrameRate = GetFrameRate();
  ScrollState = 1;
  v6 = (unsigned __int8)(FrameRate / 2);
  if ( WinFlag )
    scroll_init(v1);
  v7 = v2;
  v28 = (unsigned __int16)RefPos;
  if ( !scroll_type )
  {
    v8 = PageSkipChk();
    if ( v8 )
    {
      if ( v8 != 2 )
        PageSkip(v8, v1);
      goto LABEL_30;
    }
    if ( (_pad & 0x10001000) != 0 )
    {
      if ( RefLine == RefPos )
      {
        if ( RefLine <= 0 )
          goto LABEL_30;
        scroll_type = -1;
        if ( !pmes )
          goto LABEL_31;
        ScrollFunc(unsigned char *)::meslist = *(_WORD *)(2 * RefLine + mes - 2);
        v29 = 576;
        v30 = 288;
        v31 = length;
        v32 = Space;
LABEL_24:
        MakeTextureMessage();
        goto LABEL_30;
      }
      if ( (_pad & 0x1000) == 0 )
        goto LABEL_30;
      v9 = RefPos - 1;
    }
    else
    {
      if ( (_pad & 0x40004000) == 0 )
      {
        ScrollFunc(unsigned char *)::scroll_count = 0;
        goto LABEL_30;
      }
      if ( RefLine + MaxLine - 1 == RefPos )
      {
        if ( RefPos >= LineTotal - 1 )
          goto LABEL_30;
        scroll_type = 1;
        if ( !pmes )
          goto LABEL_41;
        v10 = *(_WORD *)(2 * RefPos + mes + 2);
        v29 = 576;
        ScrollFunc(unsigned char *)::meslist = v10;
        v32 = Space;
        v30 = Space * MaxLine + 304;
        v31 = length;
        goto LABEL_24;
      }
      if ( RefPos >= LineTotal - 1 || (_pad & 0x4000) == 0 )
        goto LABEL_30;
      v9 = RefPos + 1;
    }
    RefPos = v9;
  }
LABEL_30:
  if ( (scroll_type & 0x80) == 0 )
  {
    if ( !scroll_type )
      goto LABEL_47;
LABEL_41:
    if ( (unsigned __int16)ScrollFunc(unsigned char *)::scroll_count < (unsigned int)(unsigned __int8)scroll2_delay )
    {
      ScrollFunc(unsigned char *)::scroll_count += v6;
      v14 = &scroll1_speed;
    }
    else
    {
      v14 = &scroll2_speed;
    }
    ScrollFlag += (unsigned __int8)*v14 * v6;
    if ( ScrollFlag >= Space )
    {
      ScrollFlag = 0;
      scroll_type = 0;
      ++RefLine;
      ++RefPos;
      if ( pmes )
      {
        v30 = Space + 304;
        v29 = 576;
        v31 = length;
        v32 = MaxLine * Space;
        DrawMove(&v29, 576, 304, v2 - 1);
        goto LABEL_47;
      }
      goto LABEL_51;
    }
LABEL_47:
    if ( pmes )
    {
      v29 = v1[7];
      if ( ScrollFlag )
      {
        v30 = v1[8] - 5;
        v31 = 4 * length;
        v32 = MaxLine * Space + 10;
        DrawFT4RGB(
          &v29,
          0,
          ScrollFlag + 43,
          0,
          ThruFlag,
          (unsigned __int16)my_tpage,
          (unsigned __int16)letter_clut,
          OtNum);
      }
      else
      {
        v30 = v1[8];
        v31 = 4 * length;
        v32 = MaxLine * Space;
        DrawFT4RGB(
          &v29,
          (unsigned __int16)ScrollFlag,
          48,
          (unsigned __int16)ScrollFlag,
          ThruFlag,
          (unsigned __int16)my_tpage,
          (unsigned __int16)letter_clut,
          OtNum);
      }
    }
    goto LABEL_51;
  }
LABEL_31:
  if ( (unsigned __int16)ScrollFunc(unsigned char *)::scroll_count < (unsigned int)(unsigned __int8)scroll2_delay )
  {
    ScrollFunc(unsigned char *)::scroll_count += v6;
    ScrollFlag -= (unsigned __int8)scroll1_speed * v6;
  }
  else
  {
    ScrollFlag -= v6 * (unsigned __int8)scroll2_speed;
  }
  if ( ScrollFlag > -Space )
    goto LABEL_47;
  ScrollFlag = 0;
  scroll_type = 0;
  RefLine = --RefPos;
  if ( pmes )
  {
    v11 = 0;
    while ( v11 < MaxLine )
    {
      v29 = 576;
      v32 = Space;
      v12 = (v11 - 1) * Space;
      v13 = Space * v11++;
      v30 = v12 + 304;
      v31 = length;
      DrawMove(&v29, 576, v13 + 304, v7 - 1);
    }
    goto LABEL_47;
  }
LABEL_51:
  v15 = (unsigned __int8)window_type;
  if ( !window_type )
  {
    v16 = RefLine;
    if ( RefLine )
    {
      v29 = arrowx;
      v17 = v1[12];
      v32 = 16;
      v30 = v17;
      v31 = 8;
      DrawFT4RGB(
        &v29,
        216,
        (unsigned __int8)window_type,
        (unsigned __int8)window_type,
        ThruFlag,
        (unsigned __int16)sys_tpage,
        (unsigned __int16)sys_clut5,
        OtNum);
      v16 = RefLine;
    }
    v18 = MaxLine;
    if ( v16 < LineTotal - MaxLine )
    {
      v29 = arrowx;
      v19 = v1[13];
      v32 = 16;
      v30 = v19;
      v31 = 8;
      DrawFT4RGB(&v29, 224, v15, v15, ThruFlag, (unsigned __int16)sys_tpage, (unsigned __int16)sys_clut5, OtNum);
      v18 = MaxLine;
    }
    if ( v18 < LineTotal )
    {
      v20 = v1[12] + 15;
      v21 = RefPos * (v1[13] - 5 - v20) / (LineTotal - 1);
      v29 = arrowx;
      v31 = 8;
      v32 = 8;
      v30 = v21 + v20;
      DrawFT4RGB(&v29, 16, 16, v15, ThruFlag, (unsigned __int16)sys_tpage, (unsigned __int16)sys_clut5, OtNum);
    }
  }
  if ( v1[2] && iOS_dispCursor_window_unitlist )
  {
    v33[0] = v1[7] - v1[11];
    v33[1] = v1[8] + Space * (RefPos - RefLine);
    CursolFunc(v33, &ScrollFunc(unsigned char *)::time, (unsigned __int8)window_type);
  }
  v22 = v1[1];
  v23 = 0;
  ScrollCount = 0;
  v24 = &v1[v22];
  v1 += v22;
  v25 = MaxLine + 1;
  if ( !ScrollFlag )
    v25 = MaxLine;
  while ( v23 < v25 && (v23 + RefLine <= LineTotal - 1 || ScrollFlag) )
  {
    v1 = v24;
    for ( i = 0; i < RetuTotal; ++i )
    {
      v34 = DrawFunc[*v1];
      v1 = (unsigned __int8 *)v34(v1);
    }
    ++v23;
    ++ScrollCount;
  }
  ScrollState = 0;
  if ( v28 != RefPos )
  {
    TRACE_Dummy("SysSnd %d\n", 1514);
    SysSnd = 3;
  }
  return v1;
}

