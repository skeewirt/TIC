// __ZL10ScrollFuncPh_1 @ 0xE18F0 (2860 bytes)
// WotL iOS - debug symbols

unsigned __int8 *__fastcall ScrollFunc(unsigned __int8 *a1)
{
  unsigned __int8 *v1; // r6
  unsigned __int16 v2; // r5
  int v3; // r2
  int v4; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r3
  __int16 v9; // r5
  int v10; // r0
  int v11; // r11
  __int16 v12; // r8
  int v13; // r12
  __int16 v14; // r2
  __int16 v15; // r3
  __int16 v16; // r3
  int v17; // r4
  __int16 v18; // r3
  int v19; // r2
  __int16 v20; // r3
  int v21; // r8
  int v22; // r1
  __int16 v23; // r3
  int v24; // r2
  __int16 v25; // r3
  int v26; // r4
  int v27; // r0
  int v28; // r1
  int v29; // r8
  unsigned __int8 *v30; // r11
  int v31; // r10
  int i; // r4
  int v34; // [sp+10h] [bp-34h]
  __int16 v35; // [sp+14h] [bp-30h]
  int v36; // [sp+18h] [bp-2Ch]
  __int16 v37; // [sp+1Ch] [bp-28h]
  __int16 v38; // [sp+20h] [bp-24h] BYREF
  __int16 v39; // [sp+22h] [bp-22h]
  __int16 v40; // [sp+24h] [bp-20h]
  __int16 v41; // [sp+26h] [bp-1Eh]
  _WORD v42[2]; // [sp+28h] [bp-1Ch] BYREF

  v1 = a1;
  v2 = jOtNum;
  if ( jFrameRate )
    v35 = (unsigned __int8)jFrameRate;
  else
    v35 = 1;
  if ( jLineTotal <= 0 )
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
        goto LABEL_11;
      }
      v7 = 1;
LABEL_13:
      while ( v7-- != 0 )
        v1 += v1[1];
      if ( ++v3 == v4 )
        return v1;
    }
    v6 = v1[4];
LABEL_11:
    v7 = v6 + 1;
    goto LABEL_13;
  }
  ScrollState = 1;
  v34 = (unsigned __int16)jRefPos;
  if ( WinFlag )
    scroll_init(a1);
  v36 = v2;
  v9 = scroll_type;
  if ( !scroll_type )
  {
    v10 = PageSkipChk();
    if ( v10 )
    {
      if ( v10 != 2 )
      {
        v11 = (unsigned __int16)jRefLine;
        v37 = jRefPos;
        v12 = jRefLine;
        if ( v10 == -1 )
        {
          jRefLine -= v1[6];
          if ( jRefLine < 0 )
            jRefLine = v9;
        }
        else if ( v10 == 1 )
        {
          jRefLine += v1[6];
          v13 = v1[6];
          if ( jLineTotal - 1 - jRefLine < v13 )
            jRefLine = jLineTotal - v13;
        }
        jRefPos = jRefLine;
        scroll_init(v1);
        jRefPos = jRefLine + v37 - v12;
        if ( jRefPos >= jLineTotal )
          jRefPos = jLineTotal - 1;
        if ( v11 != (unsigned __int16)jRefLine )
          jSysSnd = 3;
      }
      goto LABEL_51;
    }
    if ( (pad & 0x10001000) != 0 )
    {
      if ( jRefLine == jRefPos )
      {
        if ( jRefLine <= 0 )
          goto LABEL_51;
        scroll_type = -1;
        if ( !pmes )
          goto LABEL_52;
        v14 = *(_WORD *)(2 * jRefLine + mes - 2);
        v39 = 32;
        ScrollFunc(unsigned char *)::meslist = v14;
        v38 = 256;
        v40 = length;
        v41 = Space;
LABEL_45:
        jMakeTextureMessage();
        goto LABEL_51;
      }
      if ( (pad & 0x1000) == 0 )
        goto LABEL_51;
      v15 = jRefPos - 1;
    }
    else
    {
      if ( (pad & 0x40004000) == 0 )
      {
        ScrollFunc(unsigned char *)::scroll_count = 0;
        goto LABEL_51;
      }
      if ( jRefLine + MaxLine - 1 == jRefPos )
      {
        if ( jRefPos >= jLineTotal - 1 )
          goto LABEL_51;
        scroll_type = 1;
        if ( !pmes )
          goto LABEL_62;
        ScrollFunc(unsigned char *)::meslist = *(_WORD *)(2 * jRefPos + mes + 2);
        v38 = 256;
        v41 = Space;
        v39 = Space * MaxLine + 48;
        v40 = length;
        goto LABEL_45;
      }
      if ( jRefPos >= jLineTotal - 1 || (pad & 0x4000) == 0 )
        goto LABEL_51;
      v15 = jRefPos + 1;
    }
    jRefPos = v15;
  }
LABEL_51:
  if ( (scroll_type & 0x80) == 0 )
  {
    if ( !scroll_type )
      goto LABEL_68;
LABEL_62:
    if ( (unsigned __int16)ScrollFunc(unsigned char *)::scroll_count < (unsigned int)(unsigned __int8)scroll2_delay )
    {
      ScrollFunc(unsigned char *)::scroll_count += v35;
      v20 = jScrollFlag + (unsigned __int8)scroll1_speed * v35;
    }
    else
    {
      v20 = jScrollFlag + v35 * (unsigned __int8)scroll2_speed;
    }
    jScrollFlag = v20;
    if ( v20 >= Space )
    {
      jScrollFlag = 0;
      scroll_type = 0;
      ++jRefLine;
      ++jRefPos;
      if ( pmes )
      {
        v38 = 256;
        v39 = Space + 48;
        v40 = length;
        v41 = MaxLine * Space;
        jDrawMove(&v38, 256, 48, v36 - 1);
        goto LABEL_68;
      }
      goto LABEL_72;
    }
LABEL_68:
    if ( pmes )
    {
      v38 = v1[7];
      if ( jScrollFlag )
      {
        v39 = v1[8] - 5;
        v40 = 4 * length;
        v41 = MaxLine * Space + 10;
        jDrawFT4RGB(
          &v38,
          0,
          jScrollFlag + 43,
          0,
          ThruFlag,
          (unsigned __int16)jmy_tpage,
          (unsigned __int16)jletter_clut,
          jOtNum);
      }
      else
      {
        v39 = v1[8];
        v40 = 4 * length;
        v41 = MaxLine * Space;
        jDrawFT4RGB(
          &v38,
          jScrollFlag,
          48,
          jScrollFlag,
          ThruFlag,
          (unsigned __int16)jmy_tpage,
          (unsigned __int16)jletter_clut,
          jOtNum);
      }
    }
    goto LABEL_72;
  }
LABEL_52:
  if ( (unsigned __int16)ScrollFunc(unsigned char *)::scroll_count < (unsigned int)(unsigned __int8)scroll2_delay )
  {
    ScrollFunc(unsigned char *)::scroll_count += v35;
    v16 = jScrollFlag - (unsigned __int8)scroll1_speed * v35;
  }
  else
  {
    v16 = jScrollFlag - v35 * (unsigned __int8)scroll2_speed;
  }
  jScrollFlag = v16;
  if ( v16 > -Space )
    goto LABEL_68;
  jScrollFlag = 0;
  scroll_type = 0;
  jRefLine = --jRefPos;
  if ( pmes )
  {
    v17 = 0;
    while ( v17 < MaxLine )
    {
      v38 = 256;
      v41 = Space;
      v18 = (v17 - 1) * Space;
      v19 = Space * v17++;
      v39 = v18 + 48;
      v40 = length;
      jDrawMove(&v38, 256, v19 + 48, v36 - 1);
    }
    goto LABEL_68;
  }
LABEL_72:
  v21 = (unsigned __int8)window_type;
  if ( !window_type )
  {
    v22 = jRefLine;
    if ( jRefLine )
    {
      v38 = arrowx;
      v23 = v1[12];
      v40 = 8;
      v41 = 16;
      v39 = v23;
      jDrawFT4RGB(
        &v38,
        216,
        (unsigned __int8)window_type,
        (unsigned __int8)window_type,
        ThruFlag,
        (unsigned __int16)jsys_tpage,
        (unsigned __int16)jsys_clut5,
        30);
      v22 = jRefLine;
    }
    v24 = MaxLine;
    if ( v22 < jLineTotal - MaxLine )
    {
      v38 = arrowx;
      v25 = v1[13];
      v41 = 16;
      v39 = v25;
      v40 = 8;
      jDrawFT4RGB(&v38, 224, v21, v21, ThruFlag, (unsigned __int16)jsys_tpage, (unsigned __int16)jsys_clut5, 30);
      v24 = MaxLine;
    }
    if ( v24 < jLineTotal )
    {
      v26 = v1[12] + 15;
      v27 = jRefPos * (v1[13] - 5 - v26) / (jLineTotal - 1);
      v38 = arrowx;
      v39 = v27 + v26;
      v40 = 8;
      v41 = 8;
      jDrawFT4RGB(&v38, 16, 16, v21, ThruFlag, (unsigned __int16)jsys_tpage, (unsigned __int16)jsys_clut5, jOtNum);
    }
    if ( v1[2] && disp_cursor )
    {
      v42[0] = v1[7] - v1[11];
      v42[1] = v1[8] + Space * (jRefPos - jRefLine);
      jCursolFunc(v42, &ScrollFunc(unsigned char *)::time, (unsigned __int8)window_type);
    }
  }
  v28 = v1[1];
  v29 = 0;
  jScrollCount = 0;
  v30 = &v1[v28];
  v1 += v28;
  v31 = MaxLine + 1;
  if ( !jScrollFlag )
    v31 = MaxLine;
  while ( v29 < v31 && (v29 + jRefLine <= jLineTotal - 1 || jScrollFlag) )
  {
    v1 = v30;
    for ( i = 0; i < RetuTotal; ++i )
      v1 = (unsigned __int8 *)DrawFunc[*v1](v1);
    ++v29;
    ++jScrollCount;
  }
  ScrollState = 0;
  if ( v34 != jRefPos )
    jSysSnd = 3;
  return v1;
}

