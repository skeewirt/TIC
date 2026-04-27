// __ZL10ScrollFuncPh_0 @ 0xDB318 (2924 bytes)
// WotL iOS - debug symbols

unsigned __int8 *__fastcall ScrollFunc(unsigned __int8 *a1)
{
  unsigned __int8 *v1; // r6
  unsigned __int16 v2; // r4
  int v3; // r2
  int v4; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r3
  __int16 v9; // r4
  int v10; // r0
  __int16 v11; // r3
  __int16 v12; // r11
  int v13; // r10
  __int16 v14; // r8
  int v15; // r12
  int v16; // r0
  __int16 v17; // r2
  __int16 v18; // r0
  char *v19; // r3
  bool v20; // zf
  int v21; // r4
  __int16 v22; // r3
  int v23; // r2
  char *v24; // r3
  int v25; // r8
  int v26; // r1
  __int16 v27; // r3
  int v28; // r2
  __int16 v29; // r3
  int v30; // r4
  int v31; // r0
  int v32; // r1
  int v33; // r8
  unsigned __int8 *v34; // r11
  int v35; // r10
  int i; // r4
  int v38; // [sp+10h] [bp-2Ch]
  int v39; // [sp+14h] [bp-28h]
  __int16 v40; // [sp+18h] [bp-24h] BYREF
  __int16 v41; // [sp+1Ah] [bp-22h]
  __int16 v42; // [sp+1Ch] [bp-20h]
  __int16 v43; // [sp+1Eh] [bp-1Eh]
  _WORD v44[2]; // [sp+20h] [bp-1Ch] BYREF

  v1 = a1;
  v2 = eOtNum;
  if ( eLineTotal <= 0 )
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
  ScrollState = 1;
  v38 = (unsigned __int16)eRefPos;
  if ( WinFlag )
    scroll_init(a1);
  v39 = v2;
  v9 = scroll_type;
  if ( !scroll_type )
  {
    v10 = PageSkipChk();
    v11 = v10;
    if ( v10 )
    {
      if ( v10 != 2 )
      {
        v12 = eRefPos;
        v13 = (unsigned __int16)eRefLine;
        v14 = eRefLine;
        if ( v10 == -1 )
        {
          eRefLine -= v1[6];
          if ( eRefLine < 0 )
            eRefLine = v9;
        }
        else if ( v10 == 1 )
        {
          eRefLine += v1[6];
          v15 = v1[6];
          if ( eLineTotal - 1 - eRefLine < v15 )
            eRefLine = eLineTotal - v15;
        }
        eRefPos = eRefLine;
        scroll_init(v1);
        eRefPos = eRefLine + v12 - v14;
        if ( eRefPos >= eLineTotal )
          eRefPos = eLineTotal - 1;
        if ( v13 != (unsigned __int16)eRefLine )
          eSysSnd = 3;
      }
      goto LABEL_49;
    }
    if ( (pad & 0x10001000) != 0 )
    {
      v16 = (unsigned __int16)eRefPos;
      if ( eRefLine == eRefPos )
      {
        if ( eRefLine <= 0 )
          goto LABEL_49;
        scroll_type = -1;
        if ( !pmes )
          goto LABEL_50;
        v17 = *(_WORD *)(2 * eRefLine + mes - 2);
        v41 = 32;
        ScrollFunc(unsigned char *)::meslist = v17;
        v40 = 256;
        v42 = length;
        v43 = Space;
LABEL_42:
        eMakeTextureMessage();
        goto LABEL_49;
      }
      if ( (pad & 0x1000) == 0 )
        goto LABEL_49;
      --eRefPos;
      if ( ((v16 - 1) & 0x8000) == 0 )
        goto LABEL_49;
    }
    else
    {
      if ( (pad & 0x40004000) == 0 )
      {
        ScrollFunc(unsigned char *)::scroll_count = 0;
        goto LABEL_49;
      }
      v18 = eRefPos;
      if ( eRefLine + MaxLine - 1 == eRefPos )
      {
        if ( eRefPos >= eLineTotal - 1 )
          goto LABEL_49;
        scroll_type = 1;
        if ( !pmes )
          goto LABEL_62;
        ScrollFunc(unsigned char *)::meslist = *(_WORD *)(2 * eRefPos + mes + 2);
        v40 = 256;
        v43 = Space;
        v41 = Space * MaxLine + 48;
        v42 = length;
        goto LABEL_42;
      }
      if ( eRefPos >= eLineTotal - 1 )
        goto LABEL_49;
      if ( (pad & 0x4000) == 0 )
        goto LABEL_49;
      ++eRefPos;
      if ( (__int16)(v18 + 1) < eLineTotal )
        goto LABEL_49;
      v11 = eLineTotal - 1;
    }
    eRefPos = v11;
  }
LABEL_49:
  if ( (scroll_type & 0x80) == 0 )
  {
    if ( !scroll_type )
      goto LABEL_70;
LABEL_62:
    if ( (unsigned __int16)ScrollFunc(unsigned char *)::scroll_count < (unsigned int)(unsigned __int8)scroll2_delay )
    {
      ScrollFunc(unsigned char *)::scroll_count += 2;
      v24 = &scroll1_speed;
    }
    else
    {
      v24 = &scroll2_speed;
    }
    eScrollFlag += 2 * (unsigned __int8)*v24;
    if ( eScrollFlag >= Space )
    {
      eScrollFlag = 0;
      scroll_type = 0;
      ++eRefLine;
      if ( ++eRefPos >= eLineTotal )
      {
        eRefPos = eLineTotal - 1;
        eRefLine = eLineTotal - MaxLine;
      }
      if ( !pmes )
        goto LABEL_74;
      v40 = 256;
      v41 = Space + 48;
      v42 = length;
      v43 = MaxLine * Space;
      eDrawMove(&v40, 256, 48, v39 - 1);
    }
    goto LABEL_70;
  }
LABEL_50:
  if ( (unsigned __int16)ScrollFunc(unsigned char *)::scroll_count < (unsigned int)(unsigned __int8)scroll2_delay )
  {
    ScrollFunc(unsigned char *)::scroll_count += 2;
    v19 = &scroll1_speed;
  }
  else
  {
    v19 = &scroll2_speed;
  }
  eScrollFlag -= 2 * (unsigned __int8)*v19;
  if ( eScrollFlag <= -Space )
  {
    eScrollFlag = 0;
    scroll_type = 0;
    v20 = (--eRefPos & 0x8000) == 0;
    eRefLine = eRefPos;
    if ( !v20 )
    {
      eRefPos = 0;
      eRefLine = 0;
    }
    if ( !pmes )
      goto LABEL_74;
    v21 = 0;
    while ( v21 < MaxLine )
    {
      v40 = 256;
      v43 = Space;
      v22 = (v21 - 1) * Space;
      v23 = Space * v21++;
      v41 = v22 + 48;
      v42 = length;
      eDrawMove(&v40, 256, v23 + 48, v39 - 1);
    }
  }
LABEL_70:
  if ( pmes )
  {
    v40 = v1[7];
    if ( eScrollFlag )
    {
      v41 = v1[8] - 5;
      v42 = 4 * length;
      v43 = MaxLine * Space + 10;
      eDrawFT4RGB(
        &v40,
        0,
        eScrollFlag + 43,
        0,
        ThruFlag,
        (unsigned __int16)emy_tpage,
        (unsigned __int16)eletter_clut,
        eOtNum);
    }
    else
    {
      v41 = v1[8];
      v42 = 4 * length;
      v43 = MaxLine * Space;
      eDrawFT4RGB(
        &v40,
        eScrollFlag,
        48,
        eScrollFlag,
        ThruFlag,
        (unsigned __int16)emy_tpage,
        (unsigned __int16)eletter_clut,
        eOtNum);
    }
  }
LABEL_74:
  v25 = (unsigned __int8)window_type;
  if ( !window_type )
  {
    v26 = eRefLine;
    if ( eRefLine )
    {
      v40 = arrowx;
      v27 = v1[12];
      v42 = 8;
      v41 = v27;
      v43 = 16;
      eDrawFT4RGB(
        &v40,
        216,
        (unsigned __int8)window_type,
        (unsigned __int8)window_type,
        ThruFlag,
        (unsigned __int16)esys_tpage,
        (unsigned __int16)esys_clut5,
        eOtNum);
      v26 = eRefLine;
    }
    v28 = MaxLine;
    if ( v26 < eLineTotal - MaxLine )
    {
      v40 = arrowx;
      v29 = v1[13];
      v43 = 16;
      v42 = 8;
      v41 = v29;
      eDrawFT4RGB(&v40, 224, v25, v25, ThruFlag, (unsigned __int16)esys_tpage, (unsigned __int16)esys_clut5, eOtNum);
      v28 = MaxLine;
    }
    if ( v28 < eLineTotal )
    {
      v30 = v1[12] + 15;
      v31 = eRefPos * (v1[13] - 5 - v30) / (eLineTotal - 1);
      v40 = arrowx;
      v42 = 8;
      v43 = 8;
      v41 = v31 + v30;
      eDrawFT4RGB(&v40, 16, 16, v25, ThruFlag, (unsigned __int16)esys_tpage, (unsigned __int16)esys_clut5, eOtNum);
    }
  }
  if ( v1[2] && iOS_dispCursor_window_equip )
  {
    v44[0] = v1[7] - v1[11];
    v44[1] = v1[8] + Space * (eRefPos - eRefLine);
    eCursolFunc(v44, &ScrollFunc(unsigned char *)::time, (unsigned __int8)window_type);
  }
  v32 = v1[1];
  v33 = 0;
  eScrollCount = 0;
  v34 = &v1[v32];
  v1 += v32;
  v35 = MaxLine + 1;
  if ( !eScrollFlag )
    v35 = MaxLine;
  while ( v33 < v35 && (v33 + eRefLine <= eLineTotal - 1 || eScrollFlag) )
  {
    v1 = v34;
    for ( i = 0; i < RetuTotal; ++i )
      v1 = (unsigned __int8 *)DrawFunc[*v1](v1);
    ++v33;
    ++eScrollCount;
  }
  ScrollState = 0;
  if ( v38 != eRefPos )
    eSysSnd = 3;
  return v1;
}

