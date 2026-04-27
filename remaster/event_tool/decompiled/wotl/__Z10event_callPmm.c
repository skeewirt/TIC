// __Z10event_callPmm @ 0x6CC54 (4900 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall event_call(unsigned int *a1, int a2)
{
  int v4; // r4
  int v5; // r0
  __int16 v6; // r4
  int v7; // r2
  int v9; // r0
  int v10; // r4
  int v11; // r0
  unsigned int v12; // r0
  int v13; // r4
  int i; // r5
  int v15; // r4
  int v16; // r0
  __int16 v17; // r6
  int v18; // r4
  int v19; // r0
  unsigned int v20; // r5
  unsigned int v21; // r11
  char *v22; // r4
  int v23; // r6
  int v24; // r8
  int v25; // r0
  __int16 v26; // r10
  int AnimationDirection16; // r0
  int v28; // r2
  int v29; // r12
  char v30; // r3
  char v31; // r1
  int v32; // lr
  bool v33; // cc
  char v34; // r1
  int v35; // r0
  bool v36; // cc
  char v37; // r3
  int v38; // r3
  char v39; // r0
  int v40; // r0
  int eventflag; // r0
  int v42; // r0
  int v43; // r0
  char v44; // r3
  int v45; // r1
  int EventStatus; // r6
  int MoviePlayFlg__Fv; // r5
  int gEventMovieNo; // r0
  int v49; // r3
  int v50; // r6
  int v51; // r5
  int v52; // r0
  int v53; // r6
  int v54; // r5
  int v55; // r0
  int v56; // r0
  int v57; // r6
  int v58; // r5
  int v59; // r0
  int v60; // r4
  _WORD v61[4]; // [sp+8h] [bp-20h] BYREF

  ablk = BattleWork;
  if ( torideflag )
  {
    DrawSync(0);
    v61[0] = 0;
    v61[1] = 240 * (gTheFlame & 1);
    v61[2] = 256;
    v61[3] = 240;
    PSX_LoadImage(v61, FileLoadAddress);
  }
  eventot = (int)a1;
  fade_eventlocal((char *)&itemp + 36 * globalframe, localfadef);
  recieve_scroll();
  drawmessagepolygons();
  if ( endf )
  {
    v4 = 1;
    while ( !asmGetActiveTask(v4) )
    {
      if ( ++v4 == 17 )
      {
        v5 = jumpeventornot();
        v6 = v5;
        if ( !v5 )
        {
          endf = 0;
          stoprequest = 0;
          return 0;
        }
        if ( read_eventflag(508) )
        {
          endf = 0;
          write_eventflag(508, 0);
        }
        else
        {
          if ( read_eventflag(39) == 327 )
            return 19;
          write_eventflag(39, (unsigned __int8)v6 + ((unsigned __int16)(v6 & 0xC00) >> 2));
          v7 = (v6 & 0xF300) >> 8;
          endf = 0;
          stoprequest = 0;
          if ( (v6 & 0xF300) != 0x8000 )
          {
            switch ( v7 )
            {
              case 129:
                return 10;
              case 130:
                return 11;
              case 131:
                return 12;
            }
            write_eventflag(39, 0);
            write_eventflag(50, 0);
            gMapDebug = 4;
          }
        }
        return 9;
      }
    }
    endf = 0;
  }
  if ( pspBattleCheckFlg(4u) )
    v9 = pspBattleDataPadGet();
  else
    v9 = a2;
  makepad(v9);
  if ( tutorialstartf == 2 )
  {
    pad_tutorial = pad;
    tutorial_padwrite(&pad);
    pad_org = pad;
    write_eventflag(42, 0);
  }
  if ( (unsigned __int16)mapwf > 2u )
    mapwf = 0;
  if ( (unsigned __int16)mapwf2 > 2u )
  {
    mapwf2 = 0;
    changeready = 1;
  }
  mapf = -1;
  weatherf = -1;
  daytimef = -1;
  mapf2 = -1;
  mapfadef = 0;
  modelanmf = 0;
  vramanmf = 0;
  effectf = -1;
  evtmemloadf = -1;
  evtvramloadf = -1;
  evtvramfreef = -1;
  evtmemfreef = -1;
  evtnormon_f = -1;
  evtnormoff_f = -1;
  soundf = -1;
  musicf = -1;
  evtmusicf = -1;
  evtmusicdispose = -1;
  fademusicf = -1;
  if ( read_eventflag(508) )
  {
    v10 = (unsigned __int16)tutorialbreak;
    if ( !tutorialbreak && tutorialornot() && iOS_getV2Icon(82) )
    {
      iOS_setV2Icon(82, v10);
      tutorialbreak = 1;
      iOS_setV2Icon(8, 2);
      iOS_setV2Icon(79, v10);
      callSoundEffect(113);
    }
  }
  if ( read_eventflag(508) && !bravebreak && !tutorialornot() && (pad & 0x800) != 0 )
  {
    if ( getMoviePlayFlg__Fv() != 6 || gBraveMovieFlg )
    {
      if ( getMoviePlayFlg__Fv() != 6 && get_gEventMovieNo() != 5 )
      {
        bravebreak = 1;
LABEL_44:
        iOS_setV2Icon(7, 0);
        goto LABEL_45;
      }
    }
    else
    {
      bravebreak = 1;
      callSoundEffect(113);
    }
    if ( !bravebreak )
      goto LABEL_45;
    goto LABEL_44;
  }
LABEL_45:
  if ( exeoverlay == 3 )
  {
    v11 = BattleJobStts(word_27B28E, 0);
    jobsttsot = v11;
    if ( !v11 )
    {
      exeoverlay = 0;
      goto LABEL_53;
    }
    AddPrims(eventot, v11, v11 + 504);
  }
  if ( exeoverlay == 4 )
  {
    v12 = BattleEquip(word_27B28E, (int *)(eventot + 8));
    jobsttsot = v12;
    if ( v12 > 1 )
      AddPrims(eventot, v12, v12 + 504);
    else
      exeoverlay = 0;
  }
LABEL_53:
  if ( !tutorialornot() && pad != 256 && pad )
    stophelp = 5;
  v13 = 2;
  byte_CF79E9 = asmGetActiveTask(1);
  do
  {
    *((_BYTE *)&taskcompare + v13) = asmGetActiveTask(v13);
    ++v13;
  }
  while ( v13 != 16 );
  asmTaskEntry();
  for ( i = 1; i != 16; ++i )
  {
    v15 = *((unsigned __int8 *)&taskcompare + i);
    if ( v15 != asmGetActiveTask(i) )
      stophelp = 5;
  }
  if ( stophelp )
    --stophelp;
  theSvectordst = *((_WORD *)evtworkptr + 58);
  word_CFABF2 = *((_WORD *)evtworkptr + 60);
  word_CFABF4 = *((_WORD *)evtworkptr + 62);
  if ( word_CFABF4 == -1 )
    word_CFABF4 = 0;
  setMapAngle(&theSvectordst);
  theVector = evtworkptr[32];
  dword_CFABFC = evtworkptr[32];
  dword_CFAC00 = evtworkptr[32];
  setMapScale(&theVector);
  theVector = evtworkptr[26];
  dword_CFABFC = ((unsigned __int16)eventshakef << 12) + evtworkptr[27];
  dword_CFAC00 = evtworkptr[28];
  setMapScrollXYZ(&theVector);
  ++totalcount;
  globalframe = ((_BYTE)globalframe + 1) & 1;
  if ( stophelp2 )
    --stophelp2;
  if ( loadf )
    return 0;
  if ( exeoverlay != 1 )
  {
    if ( exeoverlay != 2 )
    {
      if ( exeoverlay == 5 )
      {
        changeflame(1);
        v18 = gTheFlame;
        write_eventflag(81, 1);
        v19 = pspEndSaveFlg;
        if ( pspEndSaveFlg )
          v19 = 1;
        BattleCardAccess(v19);
        gTheFlame = v18;
        exeoverlay = 0;
      }
      goto LABEL_78;
    }
    changeflame(1);
    v16 = BattleUnitList(nullptr, nullptr);
    v17 = v16;
    setCurrentPanel(v16);
    word_27B28E = v17;
  }
  exeoverlay = 0;
LABEL_78:
  load_overlay();
  if ( loaddata )
  {
    if ( loaddataflg )
    {
      asmfunction = fileReadCheck;
      if ( !asm_function(1u, 0, 0, 0, 0, 0) )
      {
        loaddataflg = 0;
        loaddata = 0;
      }
    }
    else
    {
      asmfunction = fileReadRequest;
      loaddataflg = asm_function(3u, loaddataseq[loaddata], loaddatalen[loaddata], loaddataadr, 0, 0) == 0;
    }
  }
  v20 = 0;
  v21 = 0;
  v22 = (char *)&unk_CF7907;
  v23 = 0;
  do
  {
    if ( !checkAnimationExist(v20) )
    {
      *(_WORD *)((char *)&movestoprsv + v23) = 0;
      *(_WORD *)((char *)&movestopanm + v23) = 0;
      goto LABEL_126;
    }
    if ( *(_WORD *)((char *)&movestopanm + v23) )
    {
      v25 = checkCharacterMove(v20);
      v26 = v25;
      if ( v25 || !*(_WORD *)((char *)&movestoprsv + v23) )
      {
        v24 = 0;
      }
      else
      {
        requestanimationlocal(v20, *(unsigned __int16 *)((char *)&movestopanm + v23));
        *(_WORD *)((char *)&movestopanm + v23) = 0;
        v24 = 1;
        *(v22 - 4) = *(v22 - 5) - 2;
      }
      *(_WORD *)((char *)&movestoprsv + v23) = v26;
    }
    else
    {
      v24 = *(unsigned __int16 *)((char *)&movestopanm + v23);
    }
    AnimationDirection16 = getAnimationDirection16(v20);
    v28 = AnimationDirection16;
    if ( *(v22 - 3) )
    {
      v29 = *(v22 - 7);
      if ( AnimationDirection16 == v29 )
      {
        *(v22 - 3) = 0;
        TRACE_Dummy("        DIREC END ID:%d %4d\n", v20, AnimationDirection16);
        goto LABEL_126;
      }
      v30 = *(v22 - 4) + 1;
      *(v22 - 4) = v30;
      v31 = v30;
      if ( !v24 )
      {
        if ( v29 == (((_BYTE)AnimationDirection16 + 1) & 0xF) || (((_BYTE)AnimationDirection16 - 1) & 0xF) == v29 )
        {
          v32 = *(v22 - 5) - 1;
          v33 = v30 < v32;
          if ( v30 < v32 )
          {
            *(v22 - 4) = v30 + 1;
            v31 = v30 + 1;
            v33 = (char)(v30 + 1) < v32;
          }
          if ( !v33 )
            goto LABEL_109;
          *(v22 - 4) = v31 + 1;
          v34 = v31 + 1;
          if ( v34 >= v32 )
            goto LABEL_109;
LABEL_108:
          *(v22 - 4) = v34 + 1;
          goto LABEL_109;
        }
        v35 = *(v22 - 5);
        v36 = v35 <= v30;
        if ( v35 > v30 )
        {
          *(v22 - 4) = v30 + 1;
          v31 = v30 + 1;
          v36 = v35 <= (char)(v30 + 1);
        }
        if ( !v36 )
        {
          *(v22 - 4) = v31 + 1;
          v34 = v31 + 1;
          if ( v35 > v34 )
            goto LABEL_108;
        }
      }
LABEL_109:
      v37 = *(v22 - 1);
      if ( v37 )
      {
        *(v22 - 1) = v37 - 1;
        if ( !v24 )
          *(v22 - 1) = v37 - 4;
        if ( *(v22 - 1) < 0 )
          *(v22 - 1) = 0;
        goto LABEL_126;
      }
      if ( *(v22 - 4) < *(v22 - 5) )
        goto LABEL_126;
      *(v22 - 4) = v37;
      v38 = (unsigned __int8)*(v22 - 6);
      if ( *(v22 - 6) )
      {
        if ( v38 != 1 )
        {
          if ( (char)v38 != 2 )
          {
LABEL_124:
            requestdirectionlocal(v20, v21);
            goto LABEL_126;
          }
          goto LABEL_122;
        }
      }
      else if ( ((v29 - v28) & 0xF) > ((v28 - v29) & 0xF) )
      {
LABEL_122:
        v39 = v28 + 15;
        goto LABEL_123;
      }
      v39 = v28 + 1;
LABEL_123:
      v21 = v39 & 0xF;
      goto LABEL_124;
    }
LABEL_126:
    ++v20;
    v22 += 7;
    v23 += 2;
  }
  while ( v20 != 21 );
  if ( mapf != -1 )
    eventMapJump(mapf, 16);
  if ( mapf2 != -1 )
    eventMapJump2(mapf2, 16);
  if ( mapfadef )
    eventMapFadeIn(mapfadef);
  if ( modelanmf )
  {
    startModelAnimation((unsigned __int16)modelanmno, (unsigned __int16)word_1200E86);
    modelanmcheckf = 1;
  }
  if ( vramanmf )
  {
    startVRAMAnimation((unsigned __int16)vramanmno, (unsigned __int16)word_1200E8A);
    vramanmcheckf = 1;
  }
  if ( modelanmcheckf )
    modelanmcheckf = checkModelAnimation((unsigned __int16)modelanmno);
  if ( vramanmcheckf )
    vramanmcheckf = checkVRAMAnimation((unsigned __int16)vramanmno);
  if ( clutloadf )
    clutloadf = ASHURA_EVENT_CLUT_LOAD(3);
  if ( mapwf == 1 )
  {
    v40 = eventMapRewrite();
LABEL_147:
    if ( !v40 )
      ++mapwf;
  }
  else if ( mapwf == 2 )
  {
    v40 = eventMapRewriteWait();
    goto LABEL_147;
  }
  if ( mapwf2 == 1 )
  {
    if ( !changeready )
    {
      eventflag = read_eventflag(51);
      ASHURA_GNS_Garage(eventflag, 0x99u);
      ++mapwf2;
    }
  }
  else if ( mapwf2 == 2 )
  {
    v42 = read_eventflag(51);
    if ( ASHURA_GNS_Garage(v42, 0x9Cu) == 155 )
      ++mapwf2;
  }
  if ( changeready == 2 )
  {
    changeready = 3;
    ASHURA_Control(0x9Au, 1u, 1, 1);
  }
  else if ( changeready == 3 )
  {
    v43 = read_eventflag(51);
    if ( !ASHURA_GNS_Garage(v43, 0x76u) )
      changeready = 0;
  }
  v44 = weatherf;
  if ( weatherf != -1 )
  {
    if ( (weatherf & 0xF00) != 0 )
    {
      weatherf &= 0xFu;
      if ( (gMapInfo & 1) != 0 )
        weatherf = (v44 & 0xF) + 5;
      ASHURA_FALL(weathercnvtbl[2 * weatherf]);
    }
    else
    {
      weatherf = -1;
    }
  }
  if ( daytimef != -1 )
  {
    write_eventflag(36, daytimef);
    ASHURA_FALL(-117);
  }
  if ( effectf != -1 )
  {
    v45 = word_274ECC;
    if ( word_274ECC != 2 )
      v45 = 0;
    callEventEffect(effectf, v45, (void *)(unsigned __int16)effectcaster);
  }
  if ( anmloadf )
    anmloadf = loadNewAnimation();
  if ( evtmemloadf >= 0 )
    loadEventAnimation(evtmemloadf, (unsigned __int8 *)evtmemloadadr);
  if ( evtvramloadf >= 0 )
    activateEventAnimation(evtvramloadf);
  if ( evtvramfreef >= 0 )
    inactivateEventAnimation(evtvramfreef);
  if ( evtmemfreef >= 0 )
    disposeEventAnimation(evtmemfreef);
  if ( evtnormon_f >= 0 )
    activateCompressedAnimation((unsigned __int16)(evtnormon_f & 0xFF00) >> 8, (unsigned __int8)evtnormon_f);
  if ( evtnormoff_f >= 0 )
    inactivateCompressedAnimation(evtnormoff_f);
  if ( soundf != -1 )
  {
    EventStatus = getEventStatus();
    MoviePlayFlg__Fv = getMoviePlayFlg__Fv();
    gEventMovieNo = get_gEventMovieNo();
    if ( ScriptCut__Fiii(EventStatus, MoviePlayFlg__Fv, gEventMovieNo) )
      callSystemSound(soundf);
  }
  if ( evtmusicf >= 0 )
  {
    inactivateMusic();
    v49 = (unsigned __int16)music_sw ^ 1;
    music_sw ^= 1u;
    if ( v49 )
    {
      if ( lastbgm2 )
      {
        v53 = getEventStatus();
        v54 = getMoviePlayFlg__Fv();
        v55 = get_gEventMovieNo();
        if ( ScriptCut__Fiii(v53, v54, v55) )
        {
LABEL_196:
          v56 = cnvvol((unsigned __int16)evtmusicpara);
          activateMusic((unsigned __int16)music_sw + 1, v56, 4 * (unsigned __int16)word_1200E80);
        }
      }
    }
    else if ( lastbgm1 )
    {
      v50 = getEventStatus();
      v51 = getMoviePlayFlg__Fv();
      v52 = get_gEventMovieNo();
      if ( ScriptCut__Fiii(v50, v51, v52) )
        goto LABEL_196;
    }
  }
  if ( evtmusicdispose >= 0 )
  {
    inactivateMusic();
    disposeMusic(evtmusicdispose);
  }
  if ( musicf != -1 )
  {
    stopMusic();
    v57 = getEventStatus();
    v58 = getMoviePlayFlg__Fv();
    v59 = get_gEventMovieNo();
    if ( ScriptCut__Fiii(v57, v58, v59) )
      callMusic(musicf);
  }
  if ( fademusicf != -1 )
    fadeMusic((unsigned __int16)fademusicf, 4 * ((unsigned int)(16 * fademusicf) >> 20));
  if ( tutorialstartf == 1 )
    return 1;
  if ( tutorialstartf != 2 )
  {
    v60 = 1;
    while ( !asmGetActiveTask(v60) )
    {
      if ( ++v60 == 17 )
      {
        endf = 1;
        return 1;
      }
    }
    return 1;
  }
  return 0;
}

