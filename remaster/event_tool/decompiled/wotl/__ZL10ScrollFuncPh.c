// __ZL10ScrollFuncPh @ 0xCC130 (2852 bytes)
// WotL iOS - debug symbols

unsigned __int8 *__fastcall ScrollFunc(unsigned __int8 *a1)
{
  unsigned __int8 *v1; // r6
  unsigned __int16 v2; // r4
  int v3; // r1
  int v4; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r3
  unsigned __int8 FrameRate; // r0
  __int16 v10; // r11
  __int16 v11; // r5
  int v12; // r0
  __int16 v13; // r10
  int v14; // r12
  __int16 v15; // r2
  __int16 v16; // r3
  __int16 v17; // r2
  int v18; // r4
  __int16 v19; // r3
  int v20; // r2
  char *v21; // r3
  int v22; // r8
  int v23; // r1
  __int16 v24; // r3
  int v25; // r2
  __int16 v26; // r3
  int v27; // r4
  int v28; // r0
  int v29; // r1
  int v30; // r8
  unsigned __int8 *v31; // r11
  int v32; // r10
  int i; // r4
  int v35; // [sp+10h] [bp-34h]
  int v36; // [sp+14h] [bp-30h]
  __int16 v37; // [sp+18h] [bp-2Ch]
  int v38; // [sp+1Ch] [bp-28h]
  __int16 v39; // [sp+20h] [bp-24h] BYREF
  __int16 v40; // [sp+22h] [bp-22h]
  __int16 v41; // [sp+24h] [bp-20h]
  __int16 v42; // [sp+26h] [bp-1Eh]
  _WORD v43[2]; // [sp+28h] [bp-1Ch] BYREF

  v1 = a1;
  v2 = OtNum;
  if ( bLineTotal <= 0 )
  {
    v3 = 0;
    v4 = a1[4] + 1;
    while ( 1 )
    {
      v5 = *v1;
      if ( v5 == 1 )
        break;
      if ( v5 == 2 )
      {
        v6 = v1[4] + v1[5];
        goto LABEL_8;
      }
      v7 = 1;
LABEL_10:
      while ( v7-- != 0 )
        v1 += v1[1];
      if ( ++v3 == v4 )
        return v1;
    }
    v6 = v1[4];
LABEL_8:
    v7 = v6 + 1;
    goto LABEL_10;
  }
  FrameRate = bGetFrameRate();
  ScrollState = 1;
  v10 = FrameRate;
  if ( WinFlag )
    scroll_init(v1);
  v36 = v2;
  v11 = scroll_type;
  v35 = (unsigned __int16)bRefPos;
  if ( !scroll_type )
  {
    v12 = PageSkipChk();
    if ( v12 )
    {
      if ( v12 != 2 )
      {
        v37 = bRefPos;
        v38 = (unsigned __int16)bRefLine;
        v13 = bRefLine;
        if ( v12 == -1 )
        {
          bRefLine -= v1[6];
          if ( bRefLine < 0 )
            bRefLine = v11;
        }
        else if ( v12 == 1 )
        {
          bRefLine += v1[6];
          v14 = v1[6];
          if ( bLineTotal - 1 - bRefLine < v14 )
            bRefLine = bLineTotal - v14;
        }
        bRefPos = bRefLine;
        scroll_init(v1);
        bRefPos = bRefLine + v37 - v13;
        if ( bRefPos >= bLineTotal )
          bRefPos = bLineTotal - 1;
        if ( v38 != (unsigned __int16)bRefLine )
          bSysSnd = 3;
      }
      goto LABEL_48;
    }
    if ( (pad & 0x10001000) != 0 )
    {
      if ( bRefLine == bRefPos )
      {
        if ( bRefLine <= 0 )
          goto LABEL_48;
        scroll_type = -1;
        if ( !pmes )
          goto LABEL_49;
        v15 = *(_WORD *)(2 * bRefLine + mes - 2);
        v39 = 256;
        ScrollFunc(unsigned char *)::meslist = v15;
        v40 = 32;
        v41 = length;
        v42 = Space;
LABEL_42:
        bMakeTextureMessage();
        goto LABEL_48;
      }
      if ( (pad & 0x1000) == 0 )
        goto LABEL_48;
      v16 = bRefPos - 1;
    }
    else
    {
      if ( (pad & 0x40004000) == 0 )
      {
        ScrollFunc(unsigned char *)::scroll_count = 0;
        goto LABEL_48;
      }
      if ( bRefLine + MaxLine - 1 == bRefPos )
      {
        if ( bRefPos >= bLineTotal - 1 )
          goto LABEL_48;
        scroll_type = 1;
        if ( !pmes )
          goto LABEL_59;
        v17 = *(_WORD *)(2 * bRefPos + mes + 2);
        v39 = 256;
        ScrollFunc(unsigned char *)::meslist = v17;
        v42 = Space;
        v40 = Space * MaxLine + 48;
        v41 = length;
        goto LABEL_42;
      }
      if ( bRefPos >= bLineTotal - 1 || (pad & 0x4000) == 0 )
        goto LABEL_48;
      v16 = bRefPos + 1;
    }
    bRefPos = v16;
  }
LABEL_48:
  if ( (scroll_type & 0x80) == 0 )
  {
    if ( !scroll_type )
      goto LABEL_65;
LABEL_59:
    if ( (unsigned __int16)ScrollFunc(unsigned char *)::scroll_count < (unsigned int)(unsigned __int8)scroll2_delay )
    {
      ScrollFunc(unsigned char *)::scroll_count += v10;
      v21 = &scroll1_speed;
    }
    else
    {
      v21 = &scroll2_speed;
    }
    bScrollFlag += (unsigned __int8)*v21 * v10;
    if ( bScrollFlag >= Space )
    {
      bScrollFlag = 0;
      scroll_type = 0;
      ++bRefLine;
      ++bRefPos;
      if ( pmes )
      {
        v39 = 256;
        v40 = Space + 48;
        v41 = length;
        v42 = MaxLine * Space;
        bDrawMove(&v39, 256, 48, v2 - 1);
        goto LABEL_65;
      }
      goto LABEL_69;
    }
LABEL_65:
    if ( pmes )
    {
      v39 = v1[7];
      if ( bScrollFlag )
      {
        v40 = v1[8] - 5;
        v41 = 4 * length;
        v42 = MaxLine * Space + 10;
        bDrawFT4RGB(
          &v39,
          0,
          bScrollFlag + 43,
          0,
          ThruFlag,
          (unsigned __int16)bmy_tpage,
          (unsigned __int16)bletter_clut,
          OtNum);
      }
      else
      {
        v40 = v1[8];
        v41 = 4 * length;
        v42 = MaxLine * Space;
        bDrawFT4RGB(
          &v39,
          bScrollFlag,
          48,
          bScrollFlag,
          ThruFlag,
          (unsigned __int16)bmy_tpage,
          (unsigned __int16)bletter_clut,
          OtNum);
      }
    }
    goto LABEL_69;
  }
LABEL_49:
  if ( (unsigned __int16)ScrollFunc(unsigned char *)::scroll_count < (unsigned int)(unsigned __int8)scroll2_delay )
  {
    ScrollFunc(unsigned char *)::scroll_count += v10;
    bScrollFlag -= (unsigned __int8)scroll1_speed * v10;
  }
  else
  {
    bScrollFlag -= v10 * (unsigned __int8)scroll2_speed;
  }
  if ( bScrollFlag > -Space )
    goto LABEL_65;
  bScrollFlag = 0;
  scroll_type = 0;
  bRefLine = --bRefPos;
  if ( pmes )
  {
    v18 = 0;
    while ( v18 < MaxLine )
    {
      v39 = 256;
      v42 = Space;
      v19 = (v18 - 1) * Space;
      v20 = Space * v18++;
      v40 = v19 + 48;
      v41 = length;
      bDrawMove(&v39, 256, v20 + 48, v36 - 1);
    }
    goto LABEL_65;
  }
LABEL_69:
  v22 = (unsigned __int8)window_type;
  if ( !window_type )
  {
    v23 = bRefLine;
    if ( bRefLine )
    {
      v39 = arrowx;
      v24 = v1[12];
      v41 = 8;
      v40 = v24;
      v42 = 16;
      bDrawFT4RGB(
        &v39,
        216,
        (unsigned __int8)window_type,
        (unsigned __int8)window_type,
        ThruFlag,
        (unsigned __int16)bsys_tpage,
        (unsigned __int16)bsys_clut5,
        OtNum);
      v23 = bRefLine;
    }
    v25 = MaxLine;
    if ( v23 < bLineTotal - MaxLine )
    {
      v39 = arrowx;
      v26 = v1[13];
      v42 = 16;
      v41 = 8;
      v40 = v26;
      bDrawFT4RGB(&v39, 224, v22, v22, ThruFlag, (unsigned __int16)bsys_tpage, (unsigned __int16)bsys_clut5, OtNum);
      v25 = MaxLine;
    }
    if ( v25 < bLineTotal )
    {
      v27 = v1[12] + 15;
      v28 = bRefPos * (v1[13] - 5 - v27) / (bLineTotal - 1);
      v39 = arrowx;
      v41 = 8;
      v42 = 8;
      v40 = v28 + v27;
      bDrawFT4RGB(&v39, 16, 16, v22, ThruFlag, (unsigned __int16)bsys_tpage, (unsigned __int16)bsys_clut5, OtNum);
    }
  }
  if ( v1[2] && iOS_dispCursor_window )
  {
    v43[0] = v1[7] - v1[11];
    v43[1] = v1[8] + Space * (bRefPos - bRefLine);
    bCursolFunc(v43, &ScrollFunc(unsigned char *)::time, (unsigned __int8)window_type);
  }
  v29 = v1[1];
  v30 = 0;
  bScrollCount = 0;
  v31 = &v1[v29];
  v1 += v29;
  v32 = MaxLine + 1;
  if ( !bScrollFlag )
    v32 = MaxLine;
  while ( v30 < v32 && (v30 + bRefLine <= bLineTotal - 1 || bScrollFlag) )
  {
    v1 = v31;
    for ( i = 0; i < RetuTotal; ++i )
      v1 = (unsigned __int8 *)DrawFunc[*v1](v1);
    ++v30;
    ++bScrollCount;
  }
  ScrollState = 0;
  if ( v35 != bRefPos )
    bSysSnd = 3;
  return v1;
}

