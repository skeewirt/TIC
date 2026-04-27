// __Z17disp_scrollwindowv @ 0x6F23C (6884 bytes)
// WotL iOS - debug symbols

int __fastcall disp_scrollwindow()
{
  char *v0; // r10
  int Input1; // r0
  int v2; // r6
  __int16 *v3; // r11
  int v4; // r8
  __int16 v5; // r1
  int v6; // r2
  int TPage; // r0
  int v8; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  char *v12; // r4
  int v13; // r0
  __int16 v14; // r3
  __int16 v15; // r3
  __int16 v16; // r3
  __int16 v17; // r1
  __int16 v18; // r3
  char *v19; // r0
  int v20; // r2
  int v21; // r1
  int v22; // r1
  __int16 v23; // lr
  int v24; // r2
  __int16 v25; // r0
  bool v26; // zf
  __int16 v27; // r3
  char *v28; // r5
  int v29; // r3
  int v30; // r3
  bool v31; // zf
  __int16 v32; // r1
  __int16 v33; // r0
  int v34; // r2
  bool v35; // zf
  int v36; // r4
  void *v37; // r1
  int v38; // r3
  int v39; // r1
  int v40; // r3
  int v41; // r6
  int v42; // r4
  unsigned int v43; // r1
  unsigned int v44; // r0
  int v45; // r0
  int v46; // r2
  __int16 v47; // r0
  __int16 v48; // r3
  __int16 v49; // r0
  int j; // r1
  __int16 *v51; // r2
  void *v52; // r1
  __int16 *v53; // r0
  int v54; // r2
  int v55; // r3
  char *v56; // r2
  char *v57; // r0
  unsigned int v58; // r4
  __int16 v59; // r3
  int v60; // r3
  int v61; // r2
  int v62; // r0
  bool v63; // zf
  int v64; // r4
  int v65; // r0
  int result; // r0
  char *v67; // [sp+28h] [bp-360h]
  char *v68; // [sp+54h] [bp-334h]
  int v69; // [sp+58h] [bp-330h]
  int v70; // [sp+5Ch] [bp-32Ch]
  int v71; // [sp+60h] [bp-328h]
  char v72; // [sp+64h] [bp-324h]
  int v73; // [sp+68h] [bp-320h]
  int v74; // [sp+6Ch] [bp-31Ch]
  int v75; // [sp+70h] [bp-318h]
  int v76; // [sp+74h] [bp-314h]
  int v77; // [sp+78h] [bp-310h]
  __int16 *v78; // [sp+7Ch] [bp-30Ch]
  int i; // [sp+80h] [bp-308h]
  int v80; // [sp+84h] [bp-304h]
  int v81; // [sp+88h] [bp-300h]
  int v82; // [sp+90h] [bp-2F8h]
  __int16 *v83; // [sp+94h] [bp-2F4h]
  _BYTE v84[18]; // [sp+98h] [bp-2F0h] BYREF
  __int16 v85; // [sp+AAh] [bp-2DEh]
  _BYTE v86[24]; // [sp+28Ch] [bp-FCh] BYREF
  _BYTE v87[24]; // [sp+2A4h] [bp-E4h] BYREF
  _BYTE v88[24]; // [sp+2BCh] [bp-CCh] BYREF
  _BYTE v89[24]; // [sp+2D4h] [bp-B4h] BYREF
  _BYTE v90[20]; // [sp+2ECh] [bp-9Ch] BYREF
  _BYTE v91[24]; // [sp+304h] [bp-84h] BYREF
  _WORD v92[2]; // [sp+31Ch] [bp-6Ch] BYREF
  __int16 v93; // [sp+320h] [bp-68h]
  __int16 v94; // [sp+322h] [bp-66h]
  __int16 v95; // [sp+324h] [bp-64h]
  __int16 v96; // [sp+326h] [bp-62h]
  _WORD v97[4]; // [sp+328h] [bp-60h] BYREF
  __int16 v98; // [sp+330h] [bp-58h] BYREF
  __int16 v99; // [sp+332h] [bp-56h]
  __int16 v100; // [sp+334h] [bp-54h]
  __int16 v101; // [sp+336h] [bp-52h]
  __int16 v102; // [sp+338h] [bp-50h] BYREF
  __int16 v103; // [sp+33Ah] [bp-4Eh]
  __int16 v104; // [sp+33Ch] [bp-4Ch]
  __int16 v105; // [sp+33Eh] [bp-4Ah]
  _WORD v106[4]; // [sp+340h] [bp-48h] BYREF
  __int16 v107; // [sp+348h] [bp-40h] BYREF
  __int16 v108; // [sp+34Ah] [bp-3Eh]
  __int16 v109; // [sp+34Ch] [bp-3Ch]
  __int16 v110; // [sp+34Eh] [bp-3Ah]
  int v111; // [sp+350h] [bp-38h] BYREF
  int v112; // [sp+354h] [bp-34h] BYREF
  int v113; // [sp+358h] [bp-30h] BYREF
  int v114; // [sp+35Ch] [bp-2Ch] BYREF
  int v115; // [sp+360h] [bp-28h] BYREF
  int v116; // [sp+364h] [bp-24h] BYREF
  int v117; // [sp+368h] [bp-20h] BYREF
  __int16 v118; // [sp+36Eh] [bp-1Ah] BYREF

  TRACE_Dummy("---- disp_scrollwindow\n");
  if ( turndispflag )
    v0 = (char *)EffectLoadAddress + 4096;
  else
    v0 = (char *)(ablk + 904);
  ++turndispflag;
  v118 = 0;
  Input1 = asmGetInput1();
  v2 = 0;
  v3 = *(__int16 **)(Input1 + 48);
  v4 = Input1;
  *(_WORD *)(Input1 + 14) = 16 * *v3 + 28;
  *(_WORD *)(Input1 + 6) = 16 * *v3 + 28;
  *(_WORD *)(Input1 + 22) = 16 * *v3 + 28;
  v92[0] = 264 - *(_WORD *)(Input1 + 4);
  v92[1] = 254;
  v95 = 8;
  v96 = 12;
  v5 = *(_WORD *)(Input1 + 4) - 8;
  v93 = v5;
  v94 = *(_WORD *)(Input1 + 14) - 26;
  v6 = v92[0] + 3;
  if ( v92[0] >= 0 )
    v6 = v92[0];
  v102 = *(_WORD *)Input1 + (v6 >> 2);
  v103 = (*(_WORD *)(Input1 + 2) & 0xFF00) + 254;
  v105 = 2;
  v104 = v5 / 4;
  ClearImage(&v102, 0, 0, 0);
  v106[1] = 128;
  v106[0] = 0;
  v106[3] = 128;
  v106[2] = 256;
  *((_DWORD *)v0 + 80) = v90;
  *((_DWORD *)v0 + 81) = v88;
  *((_DWORD *)v0 + 82) = v86;
  multiwindow_packetinit(&v107, v4, v0 + 192);
  *((_DWORD *)v0 + 197) = v91;
  *((_DWORD *)v0 + 198) = v89;
  *((_DWORD *)v0 + 199) = v87;
  multiwindow_packetinit(&v107, v4, v0 + 660);
  TPage = GetTPage(0, 0, 960, 256);
  SetDrawMode(v0 + 404, 0, 0, TPage, &fullround);
  v8 = GetTPage(0, 0, 960, 256);
  SetDrawMode(v0 + 160, 0, 0, v8, &fullround);
  v9 = *((_DWORD *)v0 + 41);
  v10 = *((_DWORD *)v0 + 42);
  v11 = *((_DWORD *)v0 + 43);
  v12 = v0;
  *((_DWORD *)v0 + 44) = *((_DWORD *)v0 + 40);
  *((_DWORD *)v0 + 45) = v9;
  *((_DWORD *)v0 + 46) = v10;
  *((_DWORD *)v0 + 47) = v11;
  v13 = GetTPage(0, 0, *(_WORD *)v4 & 0xFFC0, *(_WORD *)(v4 + 2) & 0xFF00);
  SetDrawMode(v0 + 144, 1, 0, v13, v106);
  do
  {
    initsprt(&v0[24 * v2 + 24]);
    *((_WORD *)v12 + 23) = 16;
    *((_WORD *)v12 + 22) = 8;
    v12[40] = 8 * (v2 + 27);
    *((_WORD *)v12 + 21) = 32124;
    v12[41] = 0;
    *((_WORD *)v12 + 18) = *(_WORD *)(v4 + 8) + *(_WORD *)(v4 + 12) - 15;
    v14 = *(_WORD *)(v4 + 10) + 16 + (*(_WORD *)(v4 + 14) - 50) * v2++;
    *((_WORD *)v12 + 19) = v14;
    v12 += 24;
  }
  while ( v2 != 2 );
  initsprt(v0 + 120);
  *((_WORD *)v0 + 70) = 8;
  v0[136] = 16;
  *((_WORD *)v0 + 71) = 8;
  *((_WORD *)v0 + 69) = 32124;
  v0[137] = 16;
  initsprt(v0);
  bgput(v0, v4, v4 + 8, v92);
  initsprtfield(v0 + 72, 2, 31804);
  v0[88] = -24;
  v0[112] = -24;
  v15 = *((_WORD *)v0 + 18);
  *((_WORD *)v0 + 47) = 12;
  *((_WORD *)v0 + 42) = v15 - 1;
  v16 = *((_WORD *)v0 + 19);
  v0[113] = 12;
  v17 = *((_WORD *)v0 + 30);
  *((_WORD *)v0 + 43) = v16 + 3;
  v18 = *((_WORD *)v0 + 31);
  *((_WORD *)v0 + 54) = v17;
  *((_WORD *)v0 + 58) = 4;
  *((_WORD *)v0 + 59) = 4;
  *((_WORD *)v0 + 46) = 6;
  *((_WORD *)v0 + 55) = v18 + 14;
  v0[89] = 0;
  extend_systemframe(*(__int16 *)(v4 + 4), *(__int16 *)(v4 + 6), &v107, 2);
  if ( turndispflag == 2 )
  {
    v19 = (char *)EffectLoadAddress + 0x2000;
  }
  else
  {
    StoreImage(&scrollrsvR, &emp);
    v19 = (char *)allocatememorywait(*(__int16 *)(v4 + 6) * *(__int16 *)(v4 + 4) / 2);
  }
  v68 = v19;
  asmClearBuffer(v19, v94 * v93 / 2);
  v117 = v3[20];
  if ( v117 > v3[1] )
    v117 = v3[1];
  v82 = *(__int16 *)(v4 + 56) - v117;
  if ( v82 >= *v3 )
  {
    v117 = 0;
    v82 = 0;
  }
  scrollinit(v4, &v117, v68);
  v108 = 128;
  v20 = v92[0] + 3;
  if ( v92[0] >= 0 )
    v20 = v92[0];
  v107 = *(_WORD *)v4 + (v20 >> 2);
  v109 = v93 / 4;
  v110 = v94;
  PSX_LoadImage(&v107, v68);
  memcpy(v0 + 468, v0, 0x1D4u);
  *((_DWORD *)v0 + 80) = v90;
  *((_DWORD *)v0 + 81) = v88;
  *((_DWORD *)v0 + 82) = v86;
  *((_DWORD *)v0 + 197) = v91;
  *((_DWORD *)v0 + 198) = v89;
  *((_DWORD *)v0 + 199) = v87;
  LoadImage_menuData();
  v21 = current_flame;
  v74 = 1;
  if ( current_flame >= 2 )
    v21 = 2;
  v80 = v21;
  v69 = 0;
  v70 = 0;
  v71 = 0;
  v73 = 0;
  v75 = 0;
  v76 = 0;
  v77 = 0;
  v72 = 0;
  for ( i = 0; ; i += v80 )
  {
    if ( !v77 && v69 > 7 )
    {
      xpLibGetOffset(&v111, &v112);
      v22 = *v3;
      v23 = *(_WORD *)(v4 + 8) + v111;
      v24 = (unsigned __int16)v3[1];
      v25 = *(_WORD *)(v4 + 10) + v112 + 15;
      v26 = v24 == 0;
      v27 = *(_WORD *)(v4 + 12) - 8;
      if ( !v3[1] )
        v24 = *v3;
      if ( !v26 )
        v24 = v22 + (__int16)v24;
      if ( *(_DWORD *)(v4 + 60) == 2 )
        iOS_CMenuTouch::init((iOS_CMenuTouch *)v84, v22, v24, 1, v23, v25, v27 - 6, 16, 0);
      else
        iOS_CMenuTouch::init((iOS_CMenuTouch *)v84, v22, v24, 0, v23, v25, v27 - 6, 16, 0);
      iOS_CMenuTouch::setDispOffset((iOS_CMenuTouch *)v84, -v111, -v112);
      v77 = 1;
    }
    v28 = &v0[468 * (v69 & 1)];
    SetSemiTrans(v28, 1);
    if ( !iOSTutoCheck() )
      pad = 0;
    if ( checkkeyok() )
    {
      if ( v77 )
      {
        v112 = v82;
        v111 = v117;
        switch ( iOS_CMenuTouch::exec((iOS_CMenuTouch *)v84, &v111, &v112, nullptr) )
        {
          case 2:
            TRACE_Dummy("IOS_MENU_TOUCH_RESULT_OK!\n");
            iOS_setV2Icon(87, 0x2000);
            v29 = turndispflag;
            goto LABEL_41;
          case 3:
            v30 = pad | 0x1000;
            goto LABEL_38;
          case 4:
            v30 = pad | 0x4000;
LABEL_38:
            pad = v30;
            break;
          case 5:
            pad |= 0x8000u;
            iOS_setV2Icon(87, 128);
            v29 = turndispflag;
            goto LABEL_41;
          case 6:
            pad |= 0x2000u;
            iOS_setV2Icon(87, 32);
            v29 = turndispflag;
LABEL_41:
            if ( v29 == 2 )
              iOS_setV2Icon(87, 0x4000);
            break;
          case 7:
            v31 = v112 == v82;
            if ( v112 == v82 )
              v31 = v117 == v111;
            if ( !v31 )
            {
              v117 = v111;
              v82 = v112;
              soundf = 3;
            }
            break;
          default:
            break;
        }
      }
    }
    else if ( v77 )
    {
      iOS_CMenuTouch::setDispAssist((iOS_CMenuTouch *)v84, 0);
    }
    if ( !iOSTutoCheck() )
      v76 = pad;
    if ( v77 )
    {
      xpLibGetOffset(&v111, &v112);
      iOS_CMenuTouch::getCursorPosLeft((iOS_CMenuTouch *)v84, &v113, &v114);
      iOS_CMenuTouch::getCursorPosRight((iOS_CMenuTouch *)v84, &v115, &v116);
      if ( (pad & 0x8000) != 0 )
      {
        xpLibGetOffset(&v116, &v115);
        iOS_CMenuTouch::getCursorPosLeft((iOS_CMenuTouch *)v84, &v114, &v113);
        RENDER_TO_SCREEN(v116 + v114, v115 + v113, &v112, &v111);
        v32 = v111;
        v33 = v112 + 2;
        v34 = 8;
LABEL_54:
        iOSYajiEffectSetTGA(v33, v32, v34);
        goto LABEL_55;
      }
      if ( (pad & 0x2000) != 0 )
      {
        xpLibGetOffset(&v116, &v115);
        iOS_CMenuTouch::getCursorPosRight((iOS_CMenuTouch *)v84, &v114, &v113);
        RENDER_TO_SCREEN(v116 + v114, v115 + v113, &v112, &v111);
        v34 = 9;
        v32 = v111;
        v33 = v112 + 4;
        goto LABEL_54;
      }
    }
LABEL_55:
    if ( v71 || !checkkeyok() )
    {
      asmTaskEntry();
      if ( v69 )
        goto LABEL_128;
    }
    else
    {
      if ( v69 )
      {
        v35 = v3[5] == 0;
        if ( !v3[5] )
          v35 = v3[6] == 0;
        if ( v35 )
        {
          if ( (pad & 0xA000) != 0 )
            v118 ^= 1u;
          *((_DWORD *)v3 + 6) = &v118;
        }
        else if ( (pad & 0xA000) != 0
               && turndispflag == 1
               && v3[6] != 2
               && *(_WORD *)(2 * *(__int16 *)(v4 + 56) + *((_DWORD *)v3 + 4)) != 28672 )
        {
          asmTaskEntry();
          soundf = 3;
          task_create(asmtasknumber - 1, (void (__fastcall *)())makeabilityturntbl);
          send_taskparamater(asmtasknumber - 1, combase + 3328, 0, 0);
          v36 = 0;
          while ( asmGetActiveTask(asmtasknumber - 1) )
          {
            if ( v36 % 30 > 23 )
              v37 = &unk_CFD480;
            else
              v37 = &unk_CFD460;
            PSX_LoadImage(&scrollrsvR, v37);
            asmTaskEntry();
            ++v36;
          }
          PSX_LoadImage(&scrollrsvR, &unk_CFD4A0);
        }
        if ( (pad & 0x1000) != 0 && ((padnow & 0x80) == 0 || tutorialstartf) )
        {
          TRACE_Dummy("disp_scrollwindow PADRleft %x:%x:%d\n", pad & 0x1000, padnow, (unsigned __int16)tutorialstartf);
          if ( v82 )
          {
            --v82;
            soundf = 3;
LABEL_223:
            asmTaskEntry();
            goto LABEL_128;
          }
          if ( !v117 )
          {
            if ( !v3[1] )
            {
              v39 = *v3 - 1;
              soundf = 3;
              v82 = v39;
            }
            goto LABEL_223;
          }
          soundf = 3;
          v108 = *(_WORD *)(v4 + 2) + ((16 * v72 - 16) & 0x7F);
          v38 = -1;
        }
        else
        {
          if ( (pad & 0x4000) == 0 || (padnow & 0x80) != 0 && !tutorialstartf )
          {
            v73 = 0;
            goto LABEL_223;
          }
          TRACE_Dummy("disp_scrollwindow PADRdown %x:%08x:%x:%d\n", pad, &pad, padnow, (unsigned __int16)tutorialstartf);
          v40 = *v3;
          if ( v40 - 1 != v82 )
          {
            ++v82;
            soundf = 3;
            goto LABEL_223;
          }
          if ( v3[1] == v117 )
          {
            if ( v3[1] )
            {
              v82 = v40 - 1;
            }
            else
            {
              v82 = 0;
              soundf = 3;
            }
            goto LABEL_223;
          }
          soundf = 3;
          v108 = *(_WORD *)(v4 + 2) + ((16 * (v72 + (unsigned __int8)*v3)) & 0x7F);
          v38 = 1;
        }
        v71 = v38;
        v110 = 16;
        v108 += 128;
        v68 = (char *)allocatememorywait(8 * v93);
        asmClearBuffer(v68, 8 * v93);
        v78 = v3;
        dword_274E78 = v93;
        v83 = v3;
        v81 = 0;
        while ( 1 )
        {
          v41 = v82 + v117 + v71;
          loadcdst(v83[2], 0);
          if ( v83[5] != 2 )
            kanjicolor = *(__int16 *)(2 * v41 + *((_DWORD *)v78 + 7));
          dword_274E7C = 0;
          if ( kanjicolor == 4 )
            dword_274E7C = 1145324612;
          v42 = (unsigned __int16)v83[5];
          if ( !v83[5] )
          {
            statuskanjiprint(*(__int16 *)(*((_DWORD *)v78 + 4) + 2 * v41), (unsigned int)v68, (unsigned int)&cdst);
            kanjicolor = *(__int16 *)(2 * v41 + *((_DWORD *)v78 + 7));
            if ( !*((_DWORD *)&asmtaskframe + 256 * asmtasknumber + 3) || (*(_BYTE *)(v41 + ablk + 656) & 1) == 0 )
              goto LABEL_120;
            loadcdst(v83[2] + 80, v42);
            v43 = (unsigned int)v68;
            v44 = 20616;
LABEL_118:
            statuskanjiprint(v44, v43, (unsigned int)&cdst);
            goto LABEL_120;
          }
          if ( v42 == 1 )
          {
            statusfigprint10(*(__int16 *)(2 * v41 + *((_DWORD *)v78 + 4)), 2, v68, &cdst);
            goto LABEL_120;
          }
          if ( (__int16)v42 != 3 )
            goto LABEL_120;
          if ( v81 == 2 )
            break;
          if ( v81 == 1 )
          {
            if ( v3[7] == 2 )
              break;
            v45 = 2 * v41;
            v46 = *((_DWORD *)v78 + 4);
          }
          else
          {
            v45 = 2 * v41;
            v46 = *((_DWORD *)v78 + 4);
          }
LABEL_115:
          v47 = *(_WORD *)(v45 + v46);
          if ( (v47 & 0x7FF) != 0 )
          {
            if ( (v47 & 0x7FFu) <= 0x63 )
            {
              statusfigprint16(v47, 2, v68, &cdst);
              goto LABEL_120;
            }
            v43 = (unsigned int)v68;
            kanjicolor = 0;
            v44 = 20637;
            cdst += 3;
            goto LABEL_118;
          }
LABEL_120:
          v26 = v81++ == 2;
          ++v83;
          v78 += 2;
          if ( v26 )
          {
            kanjicolor = 0;
            dword_274E7C = 0;
            PSX_LoadImage(&v107, v68);
            v102 = v107;
            v103 = (unsigned __int8)(v108 - 2) + (v108 & 0xFF00);
            v105 = 2;
            v104 = v109;
            ClearImage(&v102, 0, 0, 0);
            asmTaskEntry();
            v75 = 1;
            goto LABEL_128;
          }
        }
        v45 = 2 * v41;
        v46 = *((_DWORD *)v78 + 4);
        if ( *(unsigned __int16 *)(2 * v41 + v46) <= 1u && (unsigned __int8)(*(_BYTE *)(v41 + ablk + 820) - 1) > 0xFDu )
        {
          word_274E72 += 2;
          statusnowprint(v68, &cdst);
          goto LABEL_120;
        }
        goto LABEL_115;
      }
      asmTaskEntry();
    }
    v51 = (__int16 *)&emp;
    for ( j = 0; j != 16; ++j )
    {
      v48 = *v51;
      v51[16] = *v51;
      v51[32] = v48;
      v51[48] = v48;
      v51[64] = v48;
      if ( (unsigned int)(j - 4) > 3 )
      {
        if ( j > 7 )
          v51[64] = v51[56];
      }
      else
      {
        v49 = *(v51 - 4);
        v51[32] = 0;
        v51[16] = v49;
      }
      ++v51;
    }
LABEL_128:
    if ( turndispflag == 1 )
    {
      if ( v69 % 30 > 23 )
        v52 = &unk_CFD4C0;
      else
        v52 = &unk_CFD4A0;
      PSX_LoadImage(&scrollrsvR, v52);
    }
    pad |= v76;
    if ( v74 )
      disposememory(v68);
    if ( v71 || !checkkeyok() )
    {
      v74 = 0;
      goto LABEL_160;
    }
    v53 = *(__int16 **)(v4 + 48);
    v54 = v92[0] + 3;
    if ( v92[0] >= 0 )
      v54 = v92[0];
    v98 = *(_WORD *)v4 + (v54 >> 2);
    v99 = 128;
    v100 = v93 / 4;
    v101 = v94;
    if ( !tutorialstartf && ((padnow & 0x80) != 0 || *((_DWORD *)asmtaskframeptr + 256 * asmtasknumber + 24)) )
    {
      if ( (pad & 0x1000) != 0 && v117 )
      {
        v55 = v117 - *v53;
        if ( v55 < 0 )
          v55 = 0;
        v117 = v55;
        soundf = 3;
        goto LABEL_154;
      }
      if ( (pad & 0x4000) != 0 && v117 != v53[1] )
      {
        v117 += *v53;
        if ( v117 > v53[1] )
          v117 = v53[1];
        soundf = 3;
        goto LABEL_154;
      }
      v56 = (char *)asmtaskframeptr + 1024 * asmtasknumber;
      if ( *((_DWORD *)v56 + 24) )
      {
        *((_DWORD *)v56 + 24) = 0;
LABEL_154:
        if ( turndispflag == 2 )
          v57 = (char *)EffectLoadAddress + 0x2000;
        else
          v57 = (char *)allocatememorywait(*(__int16 *)(v4 + 6) * *(__int16 *)(v4 + 4) / 2);
        v68 = v57;
        asmClearBuffer(v57, *(__int16 *)(v4 + 6) * *(__int16 *)(v4 + 4) / 2);
        scrollinit(v4, &v117, v68);
        PSX_LoadImage(&v98, v68);
        v97[0] = v98;
        v97[1] = (unsigned __int8)(v99 - 2) + (v99 & 0xFF00);
        v97[3] = 2;
        v97[2] = v100;
        ClearImage(v97, 0, 0, 0);
        v72 = 0;
        goto LABEL_159;
      }
    }
    v68 = nullptr;
LABEL_159:
    v74 = (int)v68;
    ClearImage(&v102, 0, 0, 0);
LABEL_160:
    *(_WORD *)(v4 + 56) = v82 + v117;
    v3[20] = v117;
    if ( !iOS_getV2Icon(133) || allgrayf )
      v58 = 0;
    else
      v58 = ((unsigned int)pad >> 8) & 1;
    if ( multiwindow_break((unsigned int *)&pad) )
      break;
    if ( v58 && iOS_getV2Icon(133) && allgrayf == 1 )
      iOS_setV2Icon(2, 0);
    v67 = v28 + 192;
    multiwindow_packetcolor(v28 + 192);
    multiwindow_loadcolor2(*((_DWORD *)v28 + 80));
    multiwindow_loadcolor2(*((_DWORD *)v28 + 81));
    multiwindow_loadcolor2(*((_DWORD *)v28 + 82));
    if ( asmGetActiveF() || allgrayf == 1 )
      v59 = 32637;
    else
      v59 = 32764;
    *((_WORD *)v28 + 9) = v59;
    multiwindow_packetanm(v4, v67, v69, v82);
    if ( v3[1] && !asmGetActiveF() )
    {
      v60 = v117;
      if ( v117 )
      {
        addlocalprim(v28 + 24);
        addlocalprim(v28 + 72);
        v60 = v117;
      }
      if ( v3[1] != v60 )
      {
        addlocalprim(v28 + 48);
        addlocalprim(v28 + 96);
      }
      v61 = *((__int16 *)v28 + 23);
      v62 = *((__int16 *)v28 + 31);
      *((_WORD *)v28 + 66) = *((_WORD *)v28 + 18);
      *((_WORD *)v28 + 67) = v61
                           + *((_WORD *)v28 + 19)
                           - 2
                           + *(__int16 *)(v4 + 56) * (v62 - (v61 + *((__int16 *)v28 + 19))) / (v3[1] + *v3);
      addlocalprim(v28 + 120);
    }
    addlocalprim(v28 + 176);
    if ( v77 && checkkeyok() )
    {
      iOS_CMenuTouch::setYLine((iOS_CMenuTouch *)v84, v82);
      iOS_CMenuTouch::drawMenuAssist((iOS_CMenuTouch *)v84, v82, (int *)eventot);
    }
    v63 = turndispflag == 1;
    if ( turndispflag <= 1 )
      v63 = v71 == 0;
    if ( v63 )
      multiwindow_keyright(v4, v82);
    multiwindow_keydown(v4);
    if ( v80 == 1 )
    {
      if ( (padframe & 1) != 0 )
        goto LABEL_195;
    }
    else if ( v80 != 2 )
    {
      goto LABEL_195;
    }
    if ( v73 >= (unsigned __int8)scroll2_delay )
      v70 += 2 * (unsigned __int8)scroll2_speed * v71;
    else
      v70 += 2 * (unsigned __int8)scroll1_speed * v71;
LABEL_195:
    if ( (unsigned int)(v70 + 15) > 0x1E )
    {
      v117 += v71;
      if ( padframe >= (unsigned __int8)keyrept1_delay / v80 )
        pad |= padnow & 0x5000;
      v72 += v71;
      disposememory(v68);
      v70 = 0;
      v71 = 0;
      v75 = 0;
    }
    v28[17] = (v70 - 2 + 16 * v72) & 0x7F;
    if ( i <= 11 )
    {
      bgput(v28, v4, v4 + 8, v92);
      multiwindow_packetextend(v4, v28, i);
    }
    if ( !v3[6] && v118 == 1 )
    {
      *((_WORD *)v28 + 130) += *(_WORD *)(*(_DWORD *)(v4 + 48) + 6);
      *((_WORD *)v28 + 142) += *(_WORD *)(*(_DWORD *)(v4 + 48) + 6);
    }
    *((_WORD *)v28 + 131) += 4;
    *((_WORD *)v28 + 143) += 4;
    v64 = v85;
    if ( !v85 && *(_DWORD *)(v4 + 60) )
    {
      *((_WORD *)v28 + 133) = 0x4000;
      addlocalprim(v28 + 248);
      v65 = GetTPage(1, v64, v64, v64);
      SetDrawMode(v28 + 388, v64, v64, v65, v64);
      addlocalprim(v28 + 388);
    }
    if ( *(__int16 *)(v4 + 44) > 4 )
    {
      addlocalprim(*((_DWORD *)v28 + 80));
      addlocalprim(*((_DWORD *)v28 + 81));
      if ( *((_DWORD *)&asmtaskframe + 256 * asmtasknumber + 3) )
        addlocalprim(*((_DWORD *)v28 + 82));
    }
    v73 += v80;
    addlocalprim(v28 + 296);
    addlocalprim(v28 + 404);
    addlocalprim(v28 + 160);
    addlocalprim(v28);
    addlocalprim(v28 + 144);
    addlocalprim(v28 + 208);
    addlocalprim(v28 + 224);
    addlocalprim(v67);
    ++v69;
  }
  iOS_setV2Icon(133, 0);
  if ( turndispflag != 2 )
    PSX_LoadImage(&scrollrsvR, &emp);
  if ( v75 )
    disposememory(v68);
  asmTaskEntry();
  --turndispflag;
  result = asmGetInput2();
  if ( !result )
    task_killmyself();
  return result;
}

