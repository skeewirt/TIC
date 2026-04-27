// __ZL16check_eventstartv @ 0x61364 (1300 bytes)
// WotL iOS - debug symbols

int __fastcall check_eventstart()
{
  unsigned int v0; // r2
  __int16 *i; // r6
  signed int v2; // r10
  int v3; // r8
  int v4; // r4
  int v5; // r0
  int v6; // r0
  unsigned __int16 *v7; // r0
  int v8; // r0
  int eventflag; // r0
  unsigned __int8 *bwp; // r0
  int v11; // r3
  int v12; // r5
  int v13; // r0
  int v14; // r2
  unsigned __int8 *v15; // r0
  unsigned int v16; // r4
  int BattleWorkIDFromAnimation; // r0
  unsigned __int8 *v18; // r5
  int v19; // r3
  bool v20; // zf
  int v21; // r2
  _BOOL4 v22; // r3
  int v23; // r3
  bool v24; // zf
  int MoviePlayFlg__Fv; // r0
  int MovieEventNum; // r4
  int v28; // [sp+4h] [bp-24h]
  int v29; // [sp+8h] [bp-20h]
  int v30; // [sp+Ch] [bp-1Ch]

  v0 = eventrequireix[0];
  v28 = 0;
LABEL_3:
  for ( i = (__int16 *)((char *)&eventrequirebuf + ((v0 + (v0 >> 31)) & 0xFFFFFFFE)); ; i += checkcodesize[*i] + 1 )
  {
    v2 = i[1];
    v3 = i[2];
    v30 = i[3];
    v29 = i[4];
    v4 = *i;
    switch ( v4 )
    {
      case 1:
        if ( v3 != read_eventflag(v2) )
          goto LABEL_65;
        continue;
      case 2:
        v5 = i[1];
        goto LABEL_51;
      case 3:
        v6 = i[1];
        goto LABEL_45;
    }
    if ( (unsigned int)(v4 - 4) <= 6 )
    {
      v7 = (unsigned __int16 *)sercheventchrptr(v2);
      if ( v7 != (unsigned __int16 *)-1 )
      {
        switch ( v4 )
        {
          case 4:
            continue;
          case 5:
            v8 = v7[24];
            break;
          case 6:
            eventflag = v7[24];
            goto LABEL_46;
          case 7:
            v8 = 100 * v7[24] / (v7[25] + 1);
            break;
          case 8:
            eventflag = 100 * v7[24] / (v7[25] + 1);
            goto LABEL_46;
          case 9:
            v8 = v7[26];
            break;
          default:
            eventflag = v7[26];
            goto LABEL_46;
        }
LABEL_52:
        if ( v3 > v8 )
          goto LABEL_65;
        continue;
      }
    }
    if ( v4 != 11 )
      break;
    if ( atchr == 255 )
      goto LABEL_65;
    bwp = (unsigned __int8 *)get_bwp(atchr);
    v11 = bwp[385];
    if ( v2 != v11 && ((unsigned __int8)(v11 - 120) > 4u || v2 != *bwp || (unsigned int)v2 > 0x49 || !v2) )
    {
LABEL_96:
      if ( ++v28 == 16 )
        return 0;
      v0 = eventrequireix[v28];
      if ( !eventrequireix[v28] )
        return 0;
      goto LABEL_3;
    }
LABEL_111:
    ;
  }
  switch ( v4 )
  {
    case 13:
      v12 = 1;
      while ( 1 )
      {
        v13 = sercheventchrptr(v12);
        if ( v13 != -1 )
          break;
LABEL_36:
        if ( ++v12 == 4 )
          goto LABEL_65;
      }
      v14 = 0;
      while ( v2 != *(unsigned __int16 *)(v13 + v14 + 26) )
      {
        v14 += 2;
        if ( v14 == 14 )
          goto LABEL_36;
      }
      goto LABEL_111;
    case 14:
      v5 = 44;
      goto LABEL_51;
    case 15:
      v6 = 44;
      goto LABEL_45;
    case 16:
      if ( v2 > read_eventflag(46) )
        goto LABEL_111;
      if ( v2 != read_eventflag(46) )
        break;
      v6 = 47;
LABEL_45:
      eventflag = read_eventflag(v6);
LABEL_46:
      if ( v3 < eventflag )
        break;
      goto LABEL_111;
    case 17:
      if ( v2 < read_eventflag(46) )
        goto LABEL_111;
      if ( v2 != read_eventflag(46) )
        break;
      v5 = 47;
LABEL_51:
      v8 = read_eventflag(v5);
      goto LABEL_52;
    case 18:
      if ( v2 > read_eventflag(98) )
        goto LABEL_96;
      goto LABEL_111;
    case 19:
      if ( v2 < read_eventflag(98) )
        goto LABEL_96;
      goto LABEL_111;
    case 22:
      if ( check_game_cont() )
        goto LABEL_96;
      goto LABEL_111;
    case 24:
      v15 = (unsigned __int8 *)sercheventchrptr(v2);
      if ( v15 == (unsigned __int8 *)-1 || v3 != v15[79] || v30 != v15[80] || v29 != v15[81] >> 7 )
        goto LABEL_96;
      goto LABEL_111;
  }
LABEL_65:
  if ( v4 == 37 )
  {
    v16 = 0;
    while ( 1 )
    {
      if ( checkAnimationExist(v16) )
      {
        BattleWorkIDFromAnimation = getBattleWorkIDFromAnimation(v16);
        if ( BattleWorkIDFromAnimation != -1 )
        {
          v18 = (unsigned __int8 *)get_bwp(BattleWorkIDFromAnimation);
          if ( (char)pspNetGetBattleModeFlag() == 2 )
          {
            v19 = v18[79];
            v20 = v3 == v19;
            if ( v3 == v19 )
              v20 = v30 == v18[80];
            if ( v20 && v29 == v18[81] >> 7 && (v18[98] & 1) == 0 )
            {
              v21 = v18[478] & 0x30;
              v22 = v2 == 3 && v21 != 0;
              if ( v22 || !(v2 | v21) )
                goto LABEL_111;
            }
          }
          else
          {
            v23 = v18[79];
            v24 = v3 == v23;
            if ( v3 == v23 )
              v24 = v30 == v18[80];
            if ( v24 && v29 == v18[81] >> 7 && v2 == v18[4] )
              goto LABEL_111;
          }
        }
      }
      if ( ++v16 == 21 )
        goto LABEL_96;
    }
  }
  if ( v4 != 25 )
    goto LABEL_96;
  write_eventflag(39, v2);
  TRACE_Dummy("Next EventNo.%3d\n", v2);
  MoviePlayFlg__Fv = getMoviePlayFlg__Fv();
  TRACE_Dummy("%d == %d\n", MoviePlayFlg__Fv, 6);
  hook_NextEventSet();
  if ( getMoviePlayFlg__Fv() == 6 )
  {
    MovieEventNum = getMovieEventNum(v2);
    if ( MovieEventNum != -1 )
    {
      get_gEventMovieNo();
      iOS_InitMovie(MovieEventNum);
      if ( get_gEventMovieNo() == 4 )
      {
        stopAllEffect();
        stopMusic();
      }
    }
  }
  return 1;
}

