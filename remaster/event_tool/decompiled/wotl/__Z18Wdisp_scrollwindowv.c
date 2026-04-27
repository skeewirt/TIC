// __Z18Wdisp_scrollwindowv @ 0x4C958 (6556 bytes)
// WotL iOS - debug symbols

int __fastcall Wdisp_scrollwindow()
{
  int Input1; // r8
  __int16 v1; // r1
  int v2; // r2
  char *v3; // r4
  int TPage; // r0
  int v5; // r0
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int v9; // r0
  int i; // r10
  __int16 v11; // r3
  char *v12; // r4
  __int16 v13; // r3
  __int16 v14; // r3
  __int16 v15; // r1
  __int16 v16; // r3
  int v17; // r2
  int v18; // r1
  int v19; // r11
  __int16 v20; // r12
  __int16 v21; // r0
  __int16 v22; // lr
  int v23; // r1
  int v24; // r2
  int v25; // r10
  int v26; // r3
  int v27; // r3
  bool v28; // zf
  __int16 v29; // r1
  __int16 v30; // r0
  int v31; // r2
  bool v32; // zf
  int v33; // r1
  int v34; // r5
  int v35; // r4
  unsigned int v36; // r1
  unsigned int v37; // r0
  int v38; // r0
  int v39; // r2
  __int16 v40; // r0
  __int16 *v41; // r0
  int v42; // r2
  int v43; // r3
  char *v44; // r2
  unsigned int v45; // r4
  int v46; // r5
  __int16 v47; // r3
  int v48; // r3
  int v49; // r5
  int v50; // r5
  int v51; // r6
  int v52; // r1
  int v53; // r0
  int v54; // r2
  bool v55; // zf
  char *v56; // r4
  int v57; // r5
  int v58; // r4
  char *v59; // r5
  int v60; // r0
  _DWORD *v61; // r4
  int v62; // r4
  int result; // r0
  int v64; // [sp+14h] [bp-378h]
  int v65; // [sp+4Ch] [bp-340h]
  char *v66; // [sp+54h] [bp-338h]
  __int16 *v67; // [sp+58h] [bp-334h]
  char *v68; // [sp+5Ch] [bp-330h]
  int v69; // [sp+60h] [bp-32Ch]
  int v70; // [sp+64h] [bp-328h]
  int v71; // [sp+68h] [bp-324h]
  int v72; // [sp+6Ch] [bp-320h]
  char v73; // [sp+70h] [bp-31Ch]
  int v74; // [sp+74h] [bp-318h]
  int v75; // [sp+78h] [bp-314h]
  int v76; // [sp+7Ch] [bp-310h]
  int v77; // [sp+80h] [bp-30Ch]
  int v78; // [sp+84h] [bp-308h]
  __int16 *v79; // [sp+88h] [bp-304h]
  int j; // [sp+8Ch] [bp-300h]
  int v81; // [sp+90h] [bp-2FCh]
  int v82; // [sp+94h] [bp-2F8h]
  __int16 *v83; // [sp+98h] [bp-2F4h]
  _BYTE v84[18]; // [sp+9Ch] [bp-2F0h] BYREF
  __int16 v85; // [sp+AEh] [bp-2DEh]
  _BYTE v86[24]; // [sp+290h] [bp-FCh] BYREF
  _BYTE v87[24]; // [sp+2A8h] [bp-E4h] BYREF
  _BYTE v88[24]; // [sp+2C0h] [bp-CCh] BYREF
  _BYTE v89[24]; // [sp+2D8h] [bp-B4h] BYREF
  _BYTE v90[16]; // [sp+2F0h] [bp-9Ch] BYREF
  _BYTE v91[24]; // [sp+308h] [bp-84h] BYREF
  _WORD v92[2]; // [sp+320h] [bp-6Ch] BYREF
  __int16 v93; // [sp+324h] [bp-68h]
  __int16 v94; // [sp+326h] [bp-66h]
  __int16 v95; // [sp+328h] [bp-64h]
  __int16 v96; // [sp+32Ah] [bp-62h]
  _WORD v97[4]; // [sp+32Ch] [bp-60h] BYREF
  __int16 v98; // [sp+334h] [bp-58h] BYREF
  __int16 v99; // [sp+336h] [bp-56h]
  __int16 v100; // [sp+338h] [bp-54h]
  __int16 v101; // [sp+33Ah] [bp-52h]
  __int16 v102; // [sp+33Ch] [bp-50h] BYREF
  __int16 v103; // [sp+33Eh] [bp-4Eh]
  __int16 v104; // [sp+340h] [bp-4Ch]
  __int16 v105; // [sp+342h] [bp-4Ah]
  _WORD v106[4]; // [sp+344h] [bp-48h] BYREF
  __int16 v107; // [sp+34Ch] [bp-40h] BYREF
  __int16 v108; // [sp+34Eh] [bp-3Eh]
  __int16 v109; // [sp+350h] [bp-3Ch]
  __int16 v110; // [sp+352h] [bp-3Ah]
  int v111; // [sp+354h] [bp-38h] BYREF
  int v112; // [sp+358h] [bp-34h] BYREF
  int v113; // [sp+35Ch] [bp-30h] BYREF
  int v114; // [sp+360h] [bp-2Ch] BYREF
  int v115; // [sp+364h] [bp-28h] BYREF
  int v116; // [sp+368h] [bp-24h] BYREF
  int v117; // [sp+36Ch] [bp-20h] BYREF
  __int16 v118; // [sp+372h] [bp-1Ah] BYREF

  TRACE_Dummy("---- disp_scrollwindow\n");
  v65 = wasmtasknumber;
  v118 = 0;
  Input1 = wasmGetInput1();
  v67 = *(__int16 **)(Input1 + 48);
  *(_WORD *)(Input1 + 14) = 16 * *v67 + 28;
  *(_WORD *)(Input1 + 6) = 16 * *v67 + 28;
  *(_WORD *)(Input1 + 22) = 16 * *v67 + 28;
  v92[0] = 264 - *(_WORD *)(Input1 + 4);
  v92[1] = 254;
  v95 = 8;
  v96 = 12;
  v1 = *(_WORD *)(Input1 + 4) - 8;
  v93 = v1;
  v94 = *(_WORD *)(Input1 + 14) - 26;
  v2 = v92[0] + 3;
  if ( v92[0] >= 0 )
    v2 = v92[0];
  v102 = *(_WORD *)Input1 + (v2 >> 2);
  v103 = (*(_WORD *)(Input1 + 2) & 0xFF00) + 254;
  v105 = 2;
  v104 = v1 / 4;
  ClearImage(&v102, 0, 0, 0);
  v106[1] = 128;
  v106[0] = 0;
  v106[3] = 128;
  v106[2] = 256;
  v3 = (char *)&scrollpr + 936 * v65;
  *((_DWORD *)v3 + 80) = v90;
  *((_DWORD *)v3 + 81) = v88;
  *((_DWORD *)v3 + 82) = v86;
  Wmultiwindow_packetinit(&v107, Input1, (char *)&scrollpr + 936 * v65 + 192);
  *((_DWORD *)v3 + 197) = v91;
  *((_DWORD *)v3 + 198) = v89;
  *((_DWORD *)v3 + 199) = v87;
  Wmultiwindow_packetinit(&v107, Input1, (char *)&scrollpr + 936 * v65 + 660);
  TPage = GetTPage(0, 0, 960, 256);
  SetDrawMode((char *)&scrollpr + 936 * v65 + 404, 0, 0, TPage, &fullround);
  v5 = GetTPage(0, 0, 960, 256);
  SetDrawMode((char *)&scrollpr + 936 * v65 + 160, 0, 0, v5, &fullround);
  v6 = *((_DWORD *)v3 + 41);
  v7 = *((_DWORD *)v3 + 42);
  v8 = *((_DWORD *)v3 + 43);
  *((_DWORD *)v3 + 44) = *((_DWORD *)v3 + 40);
  *((_DWORD *)v3 + 45) = v6;
  *((_DWORD *)v3 + 46) = v7;
  *((_DWORD *)v3 + 47) = v8;
  v9 = GetTPage(0, 0, *(_WORD *)Input1 & 0xFFC0, *(_WORD *)(Input1 + 2) & 0xFF00);
  SetDrawMode((char *)&scrollpr + 936 * v65 + 144, 1, 0, v9, v106);
  v64 = 936 * v65;
  for ( i = 0; i != 2; ++i )
  {
    Winitsprt((char *)&scrollpr + 24 * i + v64 + 24);
    *((_WORD *)v3 + 23) = 16;
    *((_WORD *)v3 + 22) = 8;
    v3[40] = 8 * (i + 27);
    *((_WORD *)v3 + 21) = 32124;
    v3[41] = 0;
    *((_WORD *)v3 + 18) = *(_WORD *)(Input1 + 8) + *(_WORD *)(Input1 + 12) - 15;
    v11 = *(_WORD *)(Input1 + 10) + 16 + (*(_WORD *)(Input1 + 14) - 50) * i;
    *((_WORD *)v3 + 19) = v11;
    v3 += 24;
  }
  v12 = (char *)&scrollpr + v64;
  Winitsprt((char *)&scrollpr + v64 + 120);
  *((_WORD *)v12 + 70) = 8;
  v12[136] = 16;
  *((_WORD *)v12 + 71) = 8;
  *((_WORD *)v12 + 69) = 32124;
  v12[137] = 16;
  Winitsprt((char *)&scrollpr + v64);
  Wbgput((char *)&scrollpr + v64, Input1, Input1 + 8, v92);
  Winitsprtfield((char *)&scrollpr + v64 + 72, 2, 31804);
  *((_WORD *)v12 + 46) = 6;
  v12[89] = 0;
  v13 = *(_WORD *)((char *)&scrollpr + v64 + 36);
  *((_WORD *)v12 + 47) = 12;
  *((_WORD *)v12 + 42) = v13 - 1;
  v14 = *(_WORD *)((char *)&scrollpr + v64 + 38);
  v12[113] = 12;
  v15 = *(_WORD *)((char *)&scrollpr + v64 + 60);
  *((_WORD *)v12 + 43) = v14 + 3;
  v16 = *(_WORD *)((char *)&scrollpr + v64 + 62);
  *((_WORD *)v12 + 54) = v15;
  *((_WORD *)v12 + 58) = 4;
  *((_WORD *)v12 + 59) = 4;
  *((_WORD *)v12 + 55) = v16 + 14;
  v12[88] = -24;
  v12[112] = -24;
  Wextend_systemframe(*(__int16 *)(Input1 + 4), *(__int16 *)(Input1 + 6), &v107, 2);
  v68 = (char *)Wallocatememorywait(*(__int16 *)(Input1 + 6) * *(__int16 *)(Input1 + 4) / 2);
  memset(v68, 0, v94 * v93 / 2);
  v117 = v67[20];
  if ( v117 > v67[1] )
    v117 = v67[1];
  v82 = *(__int16 *)(Input1 + 56) - v117;
  if ( v82 >= *v67 )
  {
    v117 = 0;
    v82 = 0;
  }
  scrollinit(Input1, &v117, v68);
  v108 = 128;
  v17 = v92[0] + 3;
  if ( v92[0] >= 0 )
    v17 = v92[0];
  v107 = *(_WORD *)Input1 + (v17 >> 2);
  v109 = v93 / 4;
  v110 = v94;
  PSX_LoadImage(&v107, v68);
  memcpy((char *)&scrollpr + v64 + 468, (char *)&scrollpr + v64, 0x1D4u);
  *((_DWORD *)v12 + 80) = v90;
  *((_DWORD *)v12 + 81) = v88;
  *((_DWORD *)v12 + 82) = v86;
  *((_DWORD *)v12 + 197) = v91;
  *((_DWORD *)v12 + 198) = v89;
  *((_DWORD *)v12 + 199) = v87;
  LoadImage_menuData();
  v18 = wcurrent_flame;
  v75 = 1;
  v19 = 936 * v65;
  if ( wcurrent_flame >= 2 )
    v18 = 2;
  v81 = v18;
  v69 = 0;
  v71 = 0;
  v72 = 0;
  v74 = 0;
  v76 = 0;
  v77 = 0;
  v78 = 0;
  v73 = 0;
  for ( j = 0; ; j += v81 )
  {
    if ( !v78 && v69 > 7 )
    {
      xpLibGetOffset(&v111, &v112);
      v111 += 46;
      --v112;
      v20 = *(_WORD *)(Input1 + 8) + v111;
      v21 = *(_WORD *)(Input1 + 10) + 15 + v112;
      v22 = *(_WORD *)(Input1 + 12) - 8;
      v23 = *v67;
      if ( v67[1] )
        v24 = v23 + v67[1];
      else
        v24 = *v67;
      if ( *(_DWORD *)(Input1 + 60) == 2 )
        iOS_CMenuTouch::init((iOS_CMenuTouch *)v84, v23, v24, 1, v20, v21, v22 - 6, 16, 0);
      else
        iOS_CMenuTouch::init((iOS_CMenuTouch *)v84, v23, v24, 0, v20, v21, v22 - 6, 16, 0);
      iOS_CMenuTouch::setDispOffset((iOS_CMenuTouch *)v84, -v111, -v112);
      v78 = 1;
    }
    v25 = v69 & 1;
    v66 = (char *)&scrollpr + 468 * v25 + v19;
    SetSemiTrans(v66, 1);
    if ( !iOSTutoCheck() )
      pad = 0;
    if ( Wcheckkeyok() )
    {
      if ( v78 )
      {
        v112 = v82;
        v111 = v117;
        switch ( iOS_CMenuTouch::exec((iOS_CMenuTouch *)v84, &v111, &v112, nullptr) )
        {
          case 2:
            TRACE_Dummy("IOS_MENU_TOUCH_RESULT_OK!\n");
            iOS_setV2Icon(87, 0x2000);
            v26 = wturndispflag;
            goto LABEL_34;
          case 3:
            v27 = pad | 0x1000;
            goto LABEL_31;
          case 4:
            v27 = pad | 0x4000;
LABEL_31:
            pad = v27;
            break;
          case 5:
            pad |= 0x8000u;
            iOS_setV2Icon(87, 128);
            v26 = wturndispflag;
            goto LABEL_34;
          case 6:
            pad |= 0x2000u;
            iOS_setV2Icon(87, 32);
            v26 = wturndispflag;
LABEL_34:
            if ( v26 == 2 )
              iOS_setV2Icon(87, 0x4000);
            break;
          case 7:
            v28 = v112 == v82;
            if ( v112 == v82 )
              v28 = v117 == v111;
            if ( !v28 )
            {
              v117 = v111;
              v82 = v112;
              wsoundf = 3;
            }
            break;
          default:
            break;
        }
      }
    }
    else if ( v78 )
    {
      iOS_CMenuTouch::setDispAssist((iOS_CMenuTouch *)v84, 0);
    }
    if ( !iOSTutoCheck() )
      v77 = pad;
    if ( v78 )
    {
      xpLibGetOffset(&v111, &v112);
      iOS_CMenuTouch::getCursorPosLeft((iOS_CMenuTouch *)v84, &v113, &v114);
      iOS_CMenuTouch::getCursorPosRight((iOS_CMenuTouch *)v84, &v115, &v116);
      if ( (pad & 0x8000) != 0 )
      {
        xpLibGetOffset(&v116, &v115);
        iOS_CMenuTouch::getCursorPosLeft((iOS_CMenuTouch *)v84, &v114, &v113);
        RENDER_TO_SCREEN(v116 + v114, v115 + v113, &v112, &v111);
        v29 = v111;
        v30 = v112 + 2;
        v31 = 8;
LABEL_47:
        iOSYajiEffectSetTGA(v30, v29, v31);
        goto LABEL_48;
      }
      if ( (pad & 0x2000) != 0 )
      {
        xpLibGetOffset(&v116, &v115);
        iOS_CMenuTouch::getCursorPosRight((iOS_CMenuTouch *)v84, &v114, &v113);
        RENDER_TO_SCREEN(v116 + v114, v115 + v113, &v112, &v111);
        v31 = 9;
        v29 = v111;
        v30 = v112 + 4;
        goto LABEL_47;
      }
    }
LABEL_48:
    if ( !v72 && Wcheckkeyok() && v69 )
    {
      v32 = v67[5] == 0;
      if ( !v67[5] )
        v32 = v67[6] == 0;
      if ( v32 )
      {
        if ( (pad & 0xA000) != 0 )
          v118 ^= 1u;
        *((_DWORD *)v67 + 6) = &v118;
      }
      if ( (pad & 0x1000) != 0 && ((padnow & 0x80) == 0 || wtutorialstartf) )
      {
        TRACE_Dummy("disp_scrollwindow PADRleft %x:%x:%d\n", pad & 0x1000, padnow, (unsigned __int16)wtutorialstartf);
        if ( v82 )
        {
          --v82;
          wsoundf = 3;
          goto LABEL_105;
        }
        if ( v117 )
        {
          wsoundf = 3;
          v108 = *(_WORD *)(Input1 + 2) + ((16 * v73 - 16) & 0x7F);
          v72 = -1;
          goto LABEL_77;
        }
        if ( !v67[1] )
        {
          v33 = *v67 - 1;
          wsoundf = 3;
          v82 = v33;
        }
      }
      else if ( (pad & 0x4000) != 0 && ((padnow & 0x80) == 0 || wtutorialstartf) )
      {
        TRACE_Dummy("disp_scrollwindow PADRdown %x:%08x:%x:%d\n", pad, &pad, padnow, (unsigned __int16)wtutorialstartf);
        if ( *v67 - 1 != v82 )
        {
          ++v82;
          wsoundf = 3;
          goto LABEL_105;
        }
        if ( v67[1] != v117 )
        {
          wsoundf = 3;
          v108 = *(_WORD *)(Input1 + 2) + ((16 * (v73 + (unsigned __int8)*v67)) & 0x7F);
          v72 = 1;
LABEL_77:
          v110 = 16;
          v108 += 128;
          v68 = (char *)Wallocatememorywait(8 * v93);
          memset(v68, 0, 8 * v93);
          dword_26C8F8 = v93;
          v83 = v67;
          v79 = v67;
          v70 = 0;
          while ( 2 )
          {
            v34 = v82 + v117 + v72;
            Wloadcdst(v83[2], 0);
            if ( v83[5] != 2 )
              wkanjicolor = *(__int16 *)(2 * v34 + *((_DWORD *)v79 + 7));
            dword_26C8FC = 0;
            if ( wkanjicolor == 4 )
              dword_26C8FC = 1145324612;
            v35 = (unsigned __int16)v83[5];
            if ( !v83[5] )
            {
              Wstatuskanjiprint(*(__int16 *)(*((_DWORD *)v79 + 4) + 2 * v34), (unsigned int)v68, (unsigned int)&wcdst);
              wkanjicolor = *(__int16 *)(2 * v34 + *((_DWORD *)v79 + 7));
              if ( *((_DWORD *)&asmtaskframe + 256 * wasmtasknumber + 3) && (*(_BYTE *)(v34 + ablk + 656) & 1) != 0 )
              {
                Wloadcdst(v83[2] + 80, v35);
                v36 = (unsigned int)v68;
                v37 = 20616;
                goto LABEL_100;
              }
              goto LABEL_102;
            }
            if ( v35 == 1 )
            {
              Wstatusfigprint10(*(__int16 *)(2 * v34 + *((_DWORD *)v79 + 4)), 2, v68, &wcdst);
              goto LABEL_102;
            }
            if ( (__int16)v35 == 3 )
            {
              if ( v70 == 2 )
                goto LABEL_92;
              if ( v70 == 1 )
              {
                if ( v67[7] == 2 )
                {
LABEL_92:
                  v38 = 2 * v34;
                  v39 = *((_DWORD *)v79 + 4);
                  if ( *(unsigned __int16 *)(2 * v34 + v39) <= 1u
                    && (unsigned __int8)(*(_BYTE *)(v34 + ablk + 820) - 1) > 0xFDu )
                  {
                    word_26C8F2 += 2;
                    Wstatusnowprint(v68, &wcdst);
                    goto LABEL_102;
                  }
                }
                else
                {
                  v38 = 2 * v34;
                  v39 = *((_DWORD *)v79 + 4);
                }
              }
              else
              {
                v38 = 2 * v34;
                v39 = *((_DWORD *)v79 + 4);
              }
              v40 = *(_WORD *)(v38 + v39);
              if ( (v40 & 0x7FF) != 0 )
              {
                if ( (v40 & 0x7FFu) <= 0x63 )
                {
                  Wstatusfigprint16(v40, 2, v68, &wcdst);
                }
                else
                {
                  v36 = (unsigned int)v68;
                  wkanjicolor = 0;
                  v37 = 20637;
                  wcdst += 3;
LABEL_100:
                  Wstatuskanjiprint(v37, v36, (unsigned int)&wcdst);
                }
              }
            }
LABEL_102:
            v28 = v70++ == 2;
            ++v83;
            v79 += 2;
            if ( v28 )
            {
              wkanjicolor = 0;
              dword_26C8FC = 0;
              PSX_LoadImage(&v107, v68);
              v102 = v107;
              v103 = (unsigned __int8)(v108 - 2) + (v108 & 0xFF00);
              v105 = 2;
              v104 = v109;
              ClearImage(&v102, 0, 0, 0);
              v76 = 1;
              goto LABEL_105;
            }
            continue;
          }
        }
        if ( v67[1] )
        {
          v82 = *v67 - 1;
        }
        else
        {
          v82 = 0;
          wsoundf = 3;
        }
      }
      else
      {
        v74 = 0;
      }
    }
LABEL_105:
    wasmTaskEntry();
    pad |= v77;
    if ( v75 )
      Wdisposememory(v68);
    if ( v72 || !Wcheckkeyok() )
    {
      v75 = 0;
      goto LABEL_129;
    }
    v41 = *(__int16 **)(Input1 + 48);
    v42 = v92[0] + 3;
    if ( v92[0] >= 0 )
      v42 = v92[0];
    v98 = *(_WORD *)Input1 + (v42 >> 2);
    v99 = 128;
    v100 = v93 / 4;
    v101 = v94;
    if ( wtutorialstartf || (padnow & 0x80) == 0 && !*((_DWORD *)wasmtaskframeptr + 256 * wasmtasknumber + 24) )
    {
LABEL_127:
      v68 = nullptr;
      goto LABEL_128;
    }
    if ( (pad & 0x1000) != 0 && v117 )
    {
      v43 = v117 - *v41;
      if ( v43 < 0 )
        v43 = 0;
      v117 = v43;
      wsoundf = 3;
    }
    else if ( (pad & 0x4000) == 0 || v117 == v41[1] )
    {
      v44 = (char *)wasmtaskframeptr + 1024 * wasmtasknumber;
      if ( !*((_DWORD *)v44 + 24) )
        goto LABEL_127;
      *((_DWORD *)v44 + 24) = 0;
    }
    else
    {
      v117 += *v41;
      if ( v117 > v41[1] )
        v117 = v41[1];
      wsoundf = 3;
    }
    v68 = (char *)Wallocatememorywait(*(__int16 *)(Input1 + 6) * *(__int16 *)(Input1 + 4) / 2);
    memset(v68, 0, *(__int16 *)(Input1 + 6) * *(__int16 *)(Input1 + 4) / 2);
    scrollinit(Input1, &v117, v68);
    PSX_LoadImage(&v98, v68);
    v97[0] = v98;
    v97[1] = (unsigned __int8)(v99 - 2) + (v99 & 0xFF00);
    v97[3] = 2;
    v97[2] = v100;
    ClearImage(v97, 0, 0, 0);
    v73 = 0;
LABEL_128:
    v75 = (int)v68;
    ClearImage(&v102, 0, 0, 0);
LABEL_129:
    *(_WORD *)(Input1 + 56) = v82 + v117;
    v67[20] = v117;
    if ( !iOS_getV2Icon(133) || wallgrayf )
      v45 = 0;
    else
      v45 = ((unsigned int)pad >> 8) & 1;
    if ( Wmultiwindow_break((unsigned int *)&pad) )
      break;
    if ( v45 && iOS_getV2Icon(133) && wallgrayf == 1 )
      iOS_setV2Icon(2, 0);
    v46 = v19 + 468 * v25;
    Wmultiwindow_packetcolor((char *)&scrollpr + v46 + 192);
    Wmultiwindow_loadcolor2(*(_DWORD *)((char *)&scrollpr + v46 + 320));
    Wmultiwindow_loadcolor2(*(_DWORD *)((char *)&scrollpr + v46 + 324));
    Wmultiwindow_loadcolor2(*(_DWORD *)((char *)&scrollpr + v46 + 328));
    if ( wasmGetActiveF() || wallgrayf == 1 )
      v47 = 32637;
    else
      v47 = 32764;
    *(_WORD *)((char *)&scrollpr + v46 + 18) = v47;
    Wmultiwindow_packetanm(Input1, (char *)&scrollpr + v46 + 192, v69, v82);
    if ( v67[1] && !wasmGetActiveF() )
    {
      v48 = v117;
      if ( v117 )
      {
        v49 = v19 + 468 * v25;
        Waddlocalprim((char *)&scrollpr + v49 + 24);
        Waddlocalprim((char *)&scrollpr + v49 + 72);
        v48 = v117;
      }
      if ( v67[1] != v48 )
      {
        v50 = v19 + 468 * v25;
        Waddlocalprim((char *)&scrollpr + v50 + 48);
        Waddlocalprim((char *)&scrollpr + v50 + 96);
      }
      v51 = v19 + 468 * v25;
      v52 = *(__int16 *)((char *)&scrollpr + v51 + 46);
      v53 = *(__int16 *)((char *)&scrollpr + v51 + 62);
      *(_WORD *)((char *)&scrollpr + v51 + 132) = *(_WORD *)((char *)&scrollpr + v51 + 36);
      v54 = v52 + *(__int16 *)((char *)&scrollpr + v51 + 38);
      *(_WORD *)((char *)&scrollpr + v51 + 134) = v54 - 2 + *(__int16 *)(Input1 + 56) * (v53 - v54) / (v67[1] + *v67);
      Waddlocalprim((char *)&scrollpr + v51 + 120);
    }
    Waddlocalprim((char *)&scrollpr + 468 * v25 + v19 + 176);
    if ( v78 && Wcheckkeyok() )
    {
      iOS_CMenuTouch::setYLine((iOS_CMenuTouch *)v84, v82);
      iOS_CMenuTouch::drawMenuAssist((iOS_CMenuTouch *)v84, v82, (int *)weventot);
    }
    v55 = wturndispflag == 1;
    if ( wturndispflag <= 1 )
      v55 = v72 == 0;
    if ( v55 )
      Wmultiwindow_keyright(Input1, v82);
    Wmultiwindow_keydown(Input1);
    if ( v81 == 1 )
    {
      if ( (padframe & 1) != 0 )
        goto LABEL_164;
    }
    else if ( v81 != 2 )
    {
      goto LABEL_164;
    }
    if ( v74 >= (unsigned __int8)scroll2_delay )
      v71 += 2 * (unsigned __int8)scroll2_speed * v72;
    else
      v71 += 2 * (unsigned __int8)scroll1_speed * v72;
LABEL_164:
    if ( (unsigned int)(v71 + 15) > 0x1E )
    {
      v117 += v72;
      if ( padframe >= (unsigned __int8)keyrept1_delay / v81 )
        pad |= padnow & 0x5000;
      v73 += v72;
      Wdisposememory(v68);
      v71 = 0;
      v72 = 0;
      v76 = 0;
    }
    v56 = (char *)&scrollpr + 468 * v25 + v19;
    v56[17] = (v71 - 2 + 16 * v73) & 0x7F;
    if ( j <= 11 )
    {
      Wbgput(v66, Input1, Input1 + 8, v92);
      Wmultiwindow_packetextend(Input1, v66, j);
    }
    if ( !v67[6] && v118 == 1 )
    {
      *((_WORD *)v56 + 130) += *(_WORD *)(*(_DWORD *)(Input1 + 48) + 6);
      *((_WORD *)v56 + 142) += *(_WORD *)(*(_DWORD *)(Input1 + 48) + 6);
    }
    v57 = v19 + 468 * v25;
    *(_WORD *)((char *)&scrollpr + v57 + 262) += 4;
    *(_WORD *)((char *)&scrollpr + v57 + 286) += 4;
    v58 = v85;
    if ( !v85 && *(_DWORD *)(Input1 + 60) )
    {
      *(_WORD *)((char *)&scrollpr + v57 + 266) = 0x4000;
      Waddlocalprim((char *)&scrollpr + v57 + 248);
      v59 = (char *)&scrollpr + v57 + 388;
      v60 = GetTPage(1, v58, v58, v58);
      SetDrawMode(v59, v58, v58, v60, v58);
      Waddlocalprim(v59);
    }
    if ( *(__int16 *)(Input1 + 44) > 4 )
    {
      v61 = (_DWORD *)((char *)&scrollpr + 468 * v25 + v19);
      Waddlocalprim(v61[80]);
      Waddlocalprim(v61[81]);
      if ( *((_DWORD *)&asmtaskframe + 256 * wasmtasknumber + 3) )
        Waddlocalprim(v61[82]);
    }
    v62 = v19 + 468 * v25;
    v74 += v81;
    Waddlocalprim((char *)&scrollpr + v62 + 296);
    Waddlocalprim((char *)&scrollpr + v62 + 404);
    Waddlocalprim((char *)&scrollpr + v62 + 160);
    Waddlocalprim(v66);
    Waddlocalprim((char *)&scrollpr + v62 + 144);
    Waddlocalprim((char *)&scrollpr + v62 + 208);
    Waddlocalprim((char *)&scrollpr + v62 + 224);
    Waddlocalprim((char *)&scrollpr + v62 + 192);
    ++v69;
  }
  iOS_setV2Icon(133, 0);
  if ( v76 )
    Wdisposememory(v68);
  wasmTaskEntry();
  --wturndispflag;
  result = wasmGetInput2();
  if ( !result )
    Wtask_killmyself();
  return result;
}

