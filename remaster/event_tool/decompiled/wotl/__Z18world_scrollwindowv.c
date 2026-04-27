// __Z18world_scrollwindowv @ 0xA65D4 (4900 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn world_scrollwindow()
{
  int v0; // r6
  _WORD *v1; // r5
  int Input1; // r11
  __int16 v3; // r3
  __int16 v4; // r3
  int TPage; // r0
  __int16 v6; // r0
  int v7; // r6
  __int16 v8; // r5
  int v9; // r1
  int v10; // r0
  __int16 v11; // r1
  int v12; // r2
  int v13; // r1
  int v14; // r2
  bool v15; // zf
  int v16; // r4
  bool v17; // zf
  int v18; // r3
  int v19; // r0
  int v20; // r8
  __int16 *v21; // r4
  __int16 *v22; // r6
  int v23; // r5
  int v24; // r3
  __int16 *v25; // r4
  _DWORD *v26; // r5
  _DWORD *v27; // r0
  __int16 v28; // r1
  __int16 v29; // r2
  __int16 v30; // r3
  int v31; // r0
  int v32; // r1
  int v33; // r0
  char *v34; // r2
  int v35; // r10
  char *v36; // r2
  char *v37; // r4
  __int16 v38; // r3
  int v39; // r6
  _WORD *v40; // r3
  int v41; // r2
  int v42; // r0
  int v43; // r1
  int v44; // r6
  char *v45; // r5
  _DWORD *v46; // r8
  int v47; // r1
  int v48; // r2
  int v49; // r3
  _DWORD *v50; // r12
  _DWORD *v51; // r12
  int v52; // r1
  __int16 v53; // r3
  bool v54; // zf
  int v55; // r4
  _WORD *v56; // r3
  __int16 v57; // r2
  bool v58; // zf
  char *v59; // r0
  unsigned int *v60; // [sp+40h] [bp-354h]
  _DWORD *v61; // [sp+44h] [bp-350h]
  __int16 *v62; // [sp+48h] [bp-34Ch]
  char *v63; // [sp+4Ch] [bp-348h]
  int v64; // [sp+50h] [bp-344h]
  int v65; // [sp+54h] [bp-340h]
  int v66; // [sp+58h] [bp-33Ch]
  char v67; // [sp+5Ch] [bp-338h]
  int v68; // [sp+60h] [bp-334h]
  int v69; // [sp+64h] [bp-330h]
  int v70; // [sp+68h] [bp-32Ch]
  int v71; // [sp+6Ch] [bp-328h]
  int v72; // [sp+74h] [bp-320h]
  _BYTE v73[18]; // [sp+78h] [bp-31Ch] BYREF
  __int16 v74; // [sp+8Ah] [bp-30Ah]
  _QWORD v75[6]; // [sp+26Ch] [bp-128h] BYREF
  _BYTE v76[24]; // [sp+29Ch] [bp-F8h] BYREF
  _BYTE v77[24]; // [sp+2B4h] [bp-E0h] BYREF
  _BYTE v78[24]; // [sp+2CCh] [bp-C8h] BYREF
  _BYTE v79[24]; // [sp+2E4h] [bp-B0h] BYREF
  char v80; // [sp+2FCh] [bp-98h] BYREF
  _BYTE v81[24]; // [sp+314h] [bp-80h] BYREF
  _WORD v82[6]; // [sp+32Ch] [bp-68h] BYREF
  _WORD v83[4]; // [sp+338h] [bp-5Ch] BYREF
  __int16 v84; // [sp+340h] [bp-54h] BYREF
  __int16 v85; // [sp+342h] [bp-52h]
  __int16 v86; // [sp+344h] [bp-50h]
  __int16 v87; // [sp+346h] [bp-4Eh]
  _DWORD v88[2]; // [sp+348h] [bp-4Ch] BYREF
  _WORD v89[4]; // [sp+350h] [bp-44h] BYREF
  __int16 v90; // [sp+358h] [bp-3Ch] BYREF
  __int16 v91; // [sp+35Ah] [bp-3Ah]
  __int16 v92; // [sp+35Ch] [bp-38h]
  __int16 v93; // [sp+35Eh] [bp-36h]
  __int16 v94; // [sp+360h] [bp-34h] BYREF
  __int16 v95; // [sp+362h] [bp-32h]
  __int16 v96; // [sp+364h] [bp-30h]
  __int16 v97; // [sp+366h] [bp-2Eh]
  int v98; // [sp+368h] [bp-2Ch] BYREF
  int v99; // [sp+36Ch] [bp-28h] BYREF
  int v100; // [sp+370h] [bp-24h] BYREF
  int v101; // [sp+374h] [bp-20h] BYREF
  _DWORD var4[9]; // [sp+378h] [bp-1Ch] BYREF

  iOS_setLockInput(0);
  v0 = 0;
  v1 = &pr;
  v60 = (unsigned int *)Wimport_localpad(0);
  var4[0] = 0;
  v61 = (_DWORD *)Wimport_localpad(1);
  Input1 = wasmGetInput1();
  v62 = *(__int16 **)(Input1 + 48);
  *(_WORD *)(Input1 + 14) = 16 * *v62 + 28;
  *(_WORD *)(Input1 + 6) = 16 * *v62 + 28;
  v3 = *v62;
  v82[4] = 8;
  v82[0] = 0;
  v82[5] = 12;
  *(_WORD *)(Input1 + 22) = 16 * v3 + 28;
  v82[1] = 126;
  v82[2] = *(_WORD *)(Input1 + 12) - 18;
  v82[3] = *(_WORD *)(Input1 + 14) - 26;
  Winitdrmode(&unk_D378C4, 0);
  v4 = *(unsigned __int8 *)(Input1 + 2);
  v89[0] = 0;
  v89[1] = v4;
  v89[2] = 256;
  v89[3] = 256;
  dword_D37964 = (int)&v80;
  dword_D37968 = (int)v78;
  dword_D3796C = (int)v76;
  Wmultiwindow_packetinit(&v94, Input1, &unk_D378E4);
  dword_D37B38 = (int)v81;
  dword_D37B3C = (int)v79;
  dword_D37B40 = (int)v77;
  Wmultiwindow_packetinit(&v94, Input1, &unk_D37AB8);
  Wmultiwindow_packetclipinit(&unk_D379C8);
  TPage = GetTPage(0, 0, *(_WORD *)Input1 & 0xFFC0, *(_WORD *)(Input1 + 2) & 0xFF00);
  SetDrawMode(&unk_D378B4, 1, 0, TPage, v89);
  do
  {
    Winitsprt((char *)&pr + 24 * v0 + 24);
    v1[22] = 8;
    *((_BYTE *)v1 + 41) = 0;
    v1[21] = 32124;
    *((_BYTE *)v1 + 40) = 8 * (v0 + 27);
    v1[23] = 16;
    v1[18] = *(_WORD *)(Input1 + 8) + *(_WORD *)(Input1 + 12) - 15;
    v6 = *(_WORD *)(Input1 + 10) + 16 + (*(_WORD *)(Input1 + 14) - 50) * v0++;
    v1[19] = v6;
    v1 += 12;
  }
  while ( v0 != 2 );
  Winitsprt(&unk_D3789C);
  word_D378B0 = 8;
  byte_D378AC = 16;
  word_D378B2 = 8;
  word_D378AE = 32124;
  byte_D378AD = 16;
  Winitsprt(&pr);
  Wbgput(&pr, Input1, Input1 + 8, v82);
  word_D3783A -= 2;
  word_D37832 += 2;
  Winitsprtfield(&unk_D3786C, 2, 31804);
  byte_D3787C = -24;
  byte_D37894 = -24;
  word_D37878 = word_D37848 - 1;
  word_D37882 = 12;
  byte_D37895 = 12;
  word_D3787A = word_D3784A + 3;
  word_D37880 = 6;
  word_D37890 = word_D37860;
  word_D37898 = 4;
  word_D3789A = 4;
  byte_D3787D = 0;
  word_D37892 = word_D37862 + 14;
  v63 = (char *)Wallocatememorywait(*(__int16 *)(Input1 + 6) * *(__int16 *)(Input1 + 4) / 2);
  memset(v63, 0, *(__int16 *)(Input1 + 6) * *(__int16 *)(Input1 + 4) / 2);
  Wtask_create(15, (void (__fastcall *)())world_dispemptywindow);
  Wsend_taskparamater(15, Input1 + 8, 0, 0);
  v7 = *(__int16 *)(Input1 + 58);
  var4[0] = v7;
  v8 = *(_WORD *)(Input1 + 56);
  scrollinit(Input1, var4, v63);
  v96 = dword_26C8F8 >> 2;
  PSX_LoadImage(&v94, v63);
  v93 = 2;
  v90 = v94;
  v91 = (unsigned __int8)(v95 - 2) + (v95 & 0xFF00);
  v92 = v96;
  ClearImage(&v90, 0, 0, 0);
  memcpy(&unk_D379F8, &pr, 0x1D4u);
  dword_D37964 = (int)&v80;
  dword_D37968 = (int)v78;
  dword_D3796C = (int)v76;
  dword_D37B38 = (int)v81;
  dword_D37B3C = (int)v79;
  dword_D37B40 = (int)v77;
  v68 = v8 - v7;
  *v60 = 0;
  *v61 = 0;
  LoadImage_menuData();
  v65 = 0;
  v64 = 0;
  v9 = wcurrent_flame;
  v69 = 0;
  v66 = 0;
  if ( wcurrent_flame >= 2 )
    v9 = 2;
  v70 = 1;
  v72 = v9;
  v71 = 0;
  v67 = 0;
  while ( 1 )
  {
    if ( !v71 && v64 > 7 )
    {
      xpLibGetOffset(&v101, &v100);
      v10 = v101;
      if ( v101 == 128 )
        v10 = 172;
      v11 = *v62;
      if ( v101 == 128 )
        v101 = v10;
      if ( v62[1] )
        v12 = *v62 + v62[1];
      else
        v12 = *v62;
      iOS_CMenuTouch::init(
        (iOS_CMenuTouch *)v73,
        v11,
        v12,
        0,
        (__int16)(v10 + *(_WORD *)(Input1 + 8)),
        (__int16)(*(_WORD *)(Input1 + 10) + v100 + 15),
        (__int16)(*(_WORD *)(Input1 + 12) - 12),
        16,
        0);
      iOS_CMenuTouch::setDispOffset((iOS_CMenuTouch *)v73, -v101, -v100);
      v71 = 1;
    }
    xpLibGetOffset(&v101, &v100);
    if ( !wasmGetActiveF() || wallgrayf )
    {
      v13 = Input1 + 8;
      v14 = 0;
    }
    else
    {
      v13 = Input1 + 8;
      v14 = 1;
    }
    Wsend_taskparamater(15, v13, v14, 0);
    if ( wasmGetActiveF() || wallgrayf == 1 )
    {
      iOS_CMenuTouch::setDispAssist((iOS_CMenuTouch *)v73, 0);
      goto LABEL_67;
    }
    if ( !v66 && Wcheckkeyok() )
    {
      v15 = v64 == 0;
      if ( v64 )
        v15 = *(_DWORD *)(Input1 + 60) == 0;
      if ( !v15 && !iOS_getLockInput() && v71 )
      {
        v98 = var4[0];
        v99 = v68;
        v16 = iOS_CMenuTouch::exec((iOS_CMenuTouch *)v73, &v98, &v99, nullptr);
        if ( v16 == 7 )
        {
          v17 = v68 == v99;
          if ( v68 == v99 )
            v17 = var4[0] == v98;
          if ( !v17 )
          {
            var4[0] = v98;
            v68 = v99;
            wsoundf = 3;
          }
        }
        iOS_setPadState(0);
        if ( v16 == 2 )
          WiOS_battle_scrollwindow_tap();
        if ( (*v60 & 0x1000) == 0 || (*v61 & 0x80) != 0 )
        {
          if ( (*v60 & 0x4000) == 0 || (*v61 & 0x80) != 0 )
          {
            v69 = 0;
            goto LABEL_67;
          }
          v19 = *v62;
          if ( v68 != v19 - 1 )
          {
            ++v68;
            goto LABEL_48;
          }
          if ( v62[1] != var4[0] )
          {
            wsoundf = 3;
            v95 = *(_WORD *)(Input1 + 2) + (unsigned __int8)(16 * (v67 + *v62));
            v66 = 1;
LABEL_54:
            v97 = 16;
            v20 = 0;
            v63 = (char *)Wallocatememorywait(2048);
            memset(v63, 0, 0x800u);
            v21 = v62;
            dword_26C8F8 = *(__int16 *)(Input1 + 4);
            v22 = v62;
            do
            {
              v23 = v68 + var4[0] + v66;
              Wloadcdst(v22[2], 0);
              if ( v22[5] != 2 )
                wkanjicolor = *(__int16 *)(2 * v23 + *((_DWORD *)v21 + 7));
              if ( wkanjicolor == 4 )
                dword_26C8FC = 1145324612;
              v24 = (unsigned __int16)v22[5];
              if ( v22[5] )
              {
                if ( v24 == 1 )
                {
                  Wstatusfigprint10(*(__int16 *)(2 * v23 + *((_DWORD *)v21 + 4)), 2, v63, &wcdst);
                }
                else if ( (__int16)v24 == 3 )
                {
                  Wstatusfigprint16(*(__int16 *)(2 * v23 + *((_DWORD *)v21 + 4)), 2, v63, &wcdst);
                }
              }
              else
              {
                Wstatuskanjiprint(*(__int16 *)(2 * v23 + *((_DWORD *)v21 + 4)), (unsigned int)v63, (unsigned int)&wcdst);
              }
              ++v20;
              ++v22;
              v21 += 2;
            }
            while ( v20 != 3 );
            dword_26C8FC = 0;
            wkanjicolor = 0;
            PSX_LoadImage(&v94, v63);
            v92 = v96;
            v90 = v94;
            v91 = (unsigned __int8)(v95 - 2) + (v95 & 0xFF00);
            v93 = 2;
            ClearImage(&v90, 0, 0, 0);
            goto LABEL_67;
          }
          if ( !v62[1] )
          {
            if ( v19 != 1 )
              wsoundf = 3;
            v68 = 0;
          }
        }
        else
        {
          if ( v68 )
          {
            --v68;
LABEL_48:
            wsoundf = 3;
            goto LABEL_67;
          }
          if ( var4[0] )
          {
            wsoundf = 3;
            v95 = *(_WORD *)(Input1 + 2) + (unsigned __int8)(16 * v67 - 16);
            v66 = -1;
            goto LABEL_54;
          }
          if ( !v62[1] )
          {
            v18 = *v62;
            v68 = v18 - 1;
            if ( v18 != 1 )
              goto LABEL_48;
          }
        }
      }
    }
LABEL_67:
    wasmTaskEntry();
    if ( v70 )
    {
      Wdisposememory(v63);
      v63 = nullptr;
    }
    if ( !v66 && Wcheckkeyok() )
    {
      v25 = *(__int16 **)(Input1 + 48);
      v26 = (_DWORD *)Wimport_localpad(0);
      v27 = (_DWORD *)Wimport_localpad(1);
      v28 = *(_WORD *)Input1;
      v29 = *(_WORD *)(Input1 + 2);
      v86 = *(__int16 *)(Input1 + 4) >> 2;
      v30 = *(_WORD *)(Input1 + 6);
      v84 = v28;
      v85 = v29;
      v87 = v30;
      if ( (*v27 & 0x80) != 0 || *((_DWORD *)wasmtaskframeptr + 256 * wasmtasknumber + 24) )
      {
        if ( (*v26 & 0x1000) != 0 && var4[0] )
        {
          v31 = 0;
          if ( var4[0] - *v25 >= 0 )
            v31 = var4[0] - *v25;
          var4[0] = v31;
          goto LABEL_82;
        }
        if ( (*v26 & 0x4000) != 0 )
        {
          v32 = var4[0];
          if ( var4[0] != v25[1] )
          {
            v33 = *v25;
            var4[0] += v33;
            if ( v33 + v32 > v25[1] )
              var4[0] = v25[1];
LABEL_82:
            wsoundf = 3;
LABEL_85:
            v63 = (char *)Wallocatememorywait(*(__int16 *)(Input1 + 6) * *(__int16 *)(Input1 + 4) / 2);
            memset(v63, 0, *(__int16 *)(Input1 + 6) * *(__int16 *)(Input1 + 4) / 2);
            scrollinit(Input1, var4, v63);
            PSX_LoadImage(&v84, v63);
            v83[1] = (unsigned __int8)(v85 - 2) + (v85 & 0xFF00);
            v83[2] = v86;
            v83[3] = 2;
            v83[0] = v84;
            ClearImage(v83, 0, 0, 0);
            v67 = 0;
LABEL_87:
            v70 = (int)v63;
            ClearImage(&v90, 0, 0, 0);
            goto LABEL_88;
          }
        }
        v34 = (char *)wasmtaskframeptr + 1024 * wasmtasknumber;
        if ( *((_DWORD *)v34 + 24) )
        {
          *((_DWORD *)v34 + 24) = 0;
          goto LABEL_85;
        }
      }
      v63 = nullptr;
      goto LABEL_87;
    }
    v70 = 0;
LABEL_88:
    *(_WORD *)(Input1 + 56) = v68 + LOWORD(var4[0]);
    *(_WORD *)(Input1 + 58) = var4[0];
    iOS_setPadState(0);
    if ( Wmultiwindow_break(v60) )
    {
      Wsend_taskparamater(15, 0, 0, 1);
      iOS_CMenuTouch::setDispAssist((iOS_CMenuTouch *)v73, 0);
      *(_WORD *)(Input1 + 58) = var4[0];
      if ( (v65 & 0xF) != 0 )
      {
        v59 = v63;
        goto LABEL_141;
      }
      if ( v63 )
      {
        v59 = v63;
LABEL_141:
        Wdisposememory(v59);
      }
      wasmTaskEntry();
      Wtask_killmyself();
    }
    if ( !v66 )
      Wmultiwindow_keyright(Input1, v68);
    Wmultiwindow_keydown(Input1);
    if ( v72 == 1 )
    {
      if ( (Wget_padframe() & 1) != 0 )
        goto LABEL_98;
    }
    else if ( v72 != 2 )
    {
      goto LABEL_98;
    }
    if ( v69 >= (unsigned __int8)scroll2_delay )
      v65 += 2 * (unsigned __int8)scroll2_speed * v66;
    else
      v65 += 2 * (unsigned __int8)scroll1_speed * v66;
LABEL_98:
    if ( (unsigned int)(v65 + 15) > 0x1E )
    {
      var4[0] += v66;
      if ( Wget_padframe() >= (unsigned __int8)keyrept1_delay / v72 )
        *v60 |= *v61 & 0x5000;
      v67 += v66;
      Wdisposememory(v63);
      v63 = nullptr;
      v65 = 0;
      v66 = 0;
    }
    v35 = v64 & 1;
    v36 = (char *)&pr + 468 * v35;
    v37 = v36 + 16;
    v36[17] = 16 * v67 + v65;
    if ( wasmGetActiveF() || wallgrayf == 1 )
      v38 = 32637;
    else
      v38 = 32764;
    *((_WORD *)v37 + 1) = v38;
    if ( v62[1] && Wcheckkeyok() )
    {
      v39 = var4[0];
      if ( var4[0] )
      {
        Waddlocalprim((char *)&pr + 468 * v35 + 24);
        Waddlocalprim((char *)&pr + 468 * v35 + 72);
        v39 = var4[0];
      }
      if ( v62[1] != v39 )
      {
        Waddlocalprim((char *)&pr + 468 * v35 + 48);
        Waddlocalprim((char *)&pr + 468 * v35 + 96);
      }
      v40 = (_WORD *)((char *)&pr + 468 * v35);
      v41 = (__int16)v40[19];
      v42 = (__int16)v40[31];
      v40[66] = v40[18];
      v40[67] = v40[23] + v41 - 2 + *(__int16 *)(Input1 + 56) * (v42 - ((__int16)v40[23] + v41)) / (v62[1] + *v62);
      Waddlocalprim((char *)&pr + 468 * v35 + 120);
    }
    v43 = *(_DWORD *)(Input1 + 12);
    v88[0] = *(_DWORD *)(Input1 + 8);
    v88[1] = v43;
    v44 = 468 * v35;
    LOWORD(v88[0]) += 42;
    v45 = (char *)&pr + 468 * v35;
    Wmultiwindow_packetclip((char *)&pr + 468 * v35 + 420, v88, v64, fbuf_idx);
    Wmultiwindow_loadcolor2(*((_DWORD *)v45 + 80));
    if ( *(__int16 *)(Input1 + 44) > 4 )
      Waddlocalprim(*((_DWORD *)v45 + 80));
    Waddlocalprim((char *)&pr + v44 + 436);
    Waddlocalprim((char *)&pr + v44 + 160);
    Waddlocalprim((char *)&pr + 468 * v35);
    if ( *((__int16 *)v45 + 11) + (unsigned __int8)v45[17] > 255 )
    {
      v46 = &var4[6 * v35 + 1];
      v47 = *((_DWORD *)v45 + 1);
      v48 = *((_DWORD *)v45 + 2);
      v49 = *((_DWORD *)v45 + 3);
      v50 = v46 - 68;
      *v50 = *(_DWORD *)v45;
      v50[1] = v47;
      v50[2] = v48;
      v50[3] = v49;
      v51 = v46 - 64;
      v52 = *((_DWORD *)v45 + 5);
      *v51 = *((_DWORD *)v45 + 4);
      v51[1] = v52;
      SetSprt(&v75[3 * v35]);
      v53 = (unsigned __int8)v45[17];
      *((_WORD *)v46 - 129) = *((_WORD *)v45 + 7) + 256 - v53;
      *((_WORD *)v46 - 125) = v53 + *((_WORD *)v45 + 11) - 256;
      *((_BYTE *)v46 - 255) = 0;
      Waddlocalprim(&v75[3 * v35]);
    }
    Waddlocalprim((char *)&pr + v44 + 144);
    Waddlocalprim((char *)&pr + 468 * v35 + 420);
    Wmultiwindow_packetcolor((char *)&pr + v44 + 192);
    Wmultiwindow_packetanm(Input1, (char *)&pr + v44 + 192, v64, v68);
    if ( wasmGetActiveF() || wallgrayf == 1 || v66 || !Wcheckkeyok() )
      goto LABEL_126;
    v54 = v64 == 0;
    if ( v64 )
      v54 = *(_DWORD *)(Input1 + 60) == 0;
    if ( v54 || iOS_getLockInput() )
LABEL_126:
      v55 = 0;
    else
      v55 = v74;
    Wcheckkeyok();
    v56 = (_WORD *)((char *)&pr + 468 * v35);
    v57 = v56[131];
    v56[118] = 1000;
    v56[131] = v57 + 4;
    v56[143] += 4;
    Wmultiwindow_packetadd((char *)&pr + v44 + 192, *(_DWORD *)(Input1 + 60), v55);
    iOS_CMenuTouch::setYLine((iOS_CMenuTouch *)v73, v68);
    if ( !wasmGetActiveF() && wallgrayf != 1 && !v66 && Wcheckkeyok() )
    {
      v58 = v64 == 0;
      if ( v64 )
        v58 = *(_DWORD *)(Input1 + 60) == 0;
      if ( !v58 && !iOS_getLockInput() )
        WiOS_assist_addlocalprim2((iOS_CMenuTouch *)v73, v68);
    }
    ++v64;
    v69 += v72;
  }
}

