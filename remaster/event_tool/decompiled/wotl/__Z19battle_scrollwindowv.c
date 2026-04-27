// __Z19battle_scrollwindowv @ 0x9698C (4332 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn battle_scrollwindow()
{
  int v0; // r6
  _WORD *v1; // r5
  int Input1; // r11
  __int16 v3; // r3
  __int16 v4; // r3
  int TPage; // r0
  __int16 v6; // r0
  int v7; // r1
  int v8; // r0
  __int16 v9; // r1
  int v10; // r2
  int v11; // r1
  int v12; // r2
  bool v13; // zf
  int v14; // r4
  bool v15; // zf
  __int16 *v16; // r8
  int v17; // r5
  __int16 *v18; // r4
  int v19; // r6
  int v20; // r3
  int v21; // r10
  char *v22; // r2
  char *v23; // r4
  __int16 v24; // r3
  int v25; // r6
  _WORD *v26; // r3
  int v27; // r1
  int v28; // r0
  int v29; // r1
  int v30; // r6
  char *v31; // r5
  _DWORD *v32; // r8
  int v33; // r1
  int v34; // r2
  int v35; // r3
  _DWORD *v36; // r12
  _DWORD *v37; // r12
  int v38; // r1
  __int16 v39; // r3
  bool v40; // zf
  int v41; // r4
  _WORD *v42; // r3
  __int16 v43; // r2
  bool v44; // zf
  unsigned int *v45; // [sp+44h] [bp-33Ch]
  _DWORD *v46; // [sp+48h] [bp-338h]
  __int16 *v47; // [sp+4Ch] [bp-334h]
  int v48; // [sp+50h] [bp-330h]
  int v49; // [sp+54h] [bp-32Ch]
  int v50; // [sp+58h] [bp-328h]
  int v51; // [sp+5Ch] [bp-324h]
  int v52; // [sp+60h] [bp-320h]
  int i; // [sp+68h] [bp-318h]
  _BYTE v54[18]; // [sp+6Ch] [bp-314h] BYREF
  __int16 v55; // [sp+7Eh] [bp-302h]
  _QWORD v56[6]; // [sp+260h] [bp-120h] BYREF
  _BYTE v57[24]; // [sp+290h] [bp-F0h] BYREF
  _BYTE v58[24]; // [sp+2A8h] [bp-D8h] BYREF
  _BYTE v59[24]; // [sp+2C0h] [bp-C0h] BYREF
  _BYTE v60[24]; // [sp+2D8h] [bp-A8h] BYREF
  _BYTE v61[16]; // [sp+2F0h] [bp-90h] BYREF
  _BYTE v62[24]; // [sp+308h] [bp-78h] BYREF
  _WORD v63[6]; // [sp+320h] [bp-60h] BYREF
  _DWORD v64[2]; // [sp+32Ch] [bp-54h] BYREF
  _WORD v65[4]; // [sp+334h] [bp-4Ch] BYREF
  __int16 v66; // [sp+33Ch] [bp-44h] BYREF
  __int16 v67; // [sp+33Eh] [bp-42h]
  __int16 v68; // [sp+340h] [bp-40h]
  __int16 v69; // [sp+342h] [bp-3Eh]
  __int16 v70; // [sp+344h] [bp-3Ch] BYREF
  __int16 v71; // [sp+346h] [bp-3Ah]
  __int16 v72; // [sp+348h] [bp-38h]
  __int16 v73; // [sp+34Ah] [bp-36h]
  int v74; // [sp+34Ch] [bp-34h] BYREF
  int v75; // [sp+350h] [bp-30h] BYREF
  int v76; // [sp+354h] [bp-2Ch] BYREF
  int v77; // [sp+358h] [bp-28h] BYREF
  int v78; // [sp+35Ch] [bp-24h] BYREF
  int v79; // [sp+360h] [bp-20h] BYREF
  _DWORD var4[9]; // [sp+364h] [bp-1Ch] BYREF

  iOS_setLockInput(0);
  v0 = 0;
  v1 = &pr;
  v45 = (unsigned int *)Wimport_localpad(0);
  var4[0] = 0;
  v78 = 0;
  v46 = (_DWORD *)Wimport_localpad(1);
  Input1 = wasmGetInput1();
  v47 = *(__int16 **)(Input1 + 48);
  *(_WORD *)(Input1 + 14) = 16 * *v47 + 28;
  *(_WORD *)(Input1 + 6) = 16 * *v47 + 28;
  v3 = *v47;
  v63[4] = 8;
  v63[0] = 0;
  v63[5] = 12;
  *(_WORD *)(Input1 + 22) = 16 * v3 + 28;
  v63[1] = 126;
  v63[2] = *(_WORD *)(Input1 + 12) - 18;
  v63[3] = *(_WORD *)(Input1 + 14) - 26;
  Winitdrmode(&unk_D26858, 0);
  v4 = *(unsigned __int8 *)(Input1 + 2);
  v65[0] = 0;
  v65[1] = v4;
  v65[2] = 256;
  v65[3] = 256;
  dword_D268F8 = (int)v61;
  dword_D268FC = (int)v59;
  dword_D26900 = (int)v57;
  Wmultiwindow_packetinit(&v70, Input1, &unk_D26878);
  dword_D26ACC = (int)v62;
  dword_D26AD0 = (int)v60;
  dword_D26AD4 = (int)v58;
  Wmultiwindow_packetinit(&v70, Input1, &unk_D26A4C);
  Wmultiwindow_packetclipinit(&unk_D2695C);
  TPage = GetTPage(0, 0, *(_WORD *)Input1 & 0xFFC0, *(_WORD *)(Input1 + 2) & 0xFF00);
  SetDrawMode(&unk_D26848, 1, 0, TPage, v65);
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
  Winitsprt(&unk_D26830);
  word_D26844 = 8;
  byte_D26840 = 16;
  word_D26846 = 8;
  word_D26842 = 32124;
  byte_D26841 = 16;
  Winitsprt(&pr);
  Wbgput(&pr, Input1, Input1 + 8, v63);
  word_D267CE -= 2;
  word_D267C6 += 2;
  Winitsprtfield(&unk_D26800, 2, 31804);
  byte_D26810 = -24;
  byte_D26828 = -24;
  word_D2680C = word_D267DC - 1;
  word_D26816 = 12;
  byte_D26829 = 12;
  word_D2680E = word_D267DE + 3;
  word_D26814 = 6;
  byte_D26811 = 0;
  word_D2682C = 4;
  word_D2682E = 4;
  word_D26824 = word_D267F4;
  word_D26826 = word_D267F6 + 14;
  memset(&optionbuffer, 0, *(__int16 *)(Input1 + 6) * *(__int16 *)(Input1 + 4) / 2);
  Wtask_create(15, (void (__fastcall *)())world_dispemptywindow);
  Wsend_taskparamater(15, Input1 + 8, 0, 0);
  var4[0] = *(__int16 *)(Input1 + 58);
  v78 = *(__int16 *)(Input1 + 56) - var4[0];
  scrollinit(Input1, var4, &optionbuffer);
  v79 = 0;
  v72 = dword_26C8F8 >> 2;
  PSX_LoadImage(&v70, &optionbuffer);
  v69 = 2;
  v66 = v70;
  v67 = (unsigned __int8)(v71 - 2) + (v71 & 0xFF00);
  v68 = v72;
  ClearImage(&v66, 0, 0, 0);
  memcpy(&unk_D2698C, &pr, 0x1D4u);
  dword_D268F8 = (int)v61;
  dword_D268FC = (int)v59;
  dword_D26900 = (int)v57;
  dword_D26ACC = (int)v62;
  dword_D26AD0 = (int)v60;
  dword_D26AD4 = (int)v58;
  *v45 = 0;
  *v46 = 0;
  LoadImage_menuData();
  v48 = 0;
  v49 = 0;
  v51 = 0;
  v7 = wcurrent_flame;
  v50 = 0;
  v52 = 0;
  if ( wcurrent_flame >= 2 )
    v7 = 2;
  for ( i = v7; ; v51 += i )
  {
    if ( !v52 && v48 > 7 )
    {
      xpLibGetOffset(&v77, &v76);
      v8 = v77;
      if ( v77 == 128 )
        v8 = 172;
      v9 = *v47;
      if ( v77 == 128 )
        v77 = v8;
      if ( v47[1] )
        v10 = *v47 + v47[1];
      else
        v10 = *v47;
      iOS_CMenuTouch::init(
        (iOS_CMenuTouch *)v54,
        v9,
        v10,
        0,
        (__int16)(v8 + *(_WORD *)(Input1 + 8)),
        (__int16)(*(_WORD *)(Input1 + 10) + v76 + 15),
        (__int16)(*(_WORD *)(Input1 + 12) - 12),
        16,
        0);
      iOS_CMenuTouch::setDispOffset((iOS_CMenuTouch *)v54, -v77, -v76);
      v52 = 1;
    }
    xpLibGetOffset(&v77, &v76);
    if ( !wasmGetActiveF() || wallgrayf )
    {
      v11 = Input1 + 8;
      v12 = 0;
    }
    else
    {
      v11 = Input1 + 8;
      v12 = 1;
    }
    Wsend_taskparamater(15, v11, v12, 0);
    if ( wasmGetActiveF() || wallgrayf == 1 )
      break;
    if ( v50 || !Wcheckkeyok() )
      goto LABEL_66;
    v13 = v48 == 0;
    if ( v48 )
      v13 = *(_DWORD *)(Input1 + 60) == 0;
    if ( v13 || iOS_getLockInput() || !v52 )
      goto LABEL_66;
    v75 = v78;
    v74 = var4[0];
    v14 = iOS_CMenuTouch::exec((iOS_CMenuTouch *)v54, &v74, &v75, nullptr);
    if ( v14 == 7 )
    {
      v15 = v78 == v75;
      if ( v78 == v75 )
        v15 = var4[0] == v74;
      if ( !v15 )
      {
        var4[0] = v74;
        v78 = v75;
        wsoundf = 3;
      }
    }
    iOS_setPadState(0);
    if ( v14 == 2 )
      WiOS_battle_scrollwindow_tap();
    if ( (*v45 & 0x1000) == 0 || (*v46 & 0x80) != 0 )
    {
      if ( (*v45 & 0x4000) == 0 || (*v46 & 0x80) != 0 )
      {
        v51 = 0;
        goto LABEL_127;
      }
      if ( *v47 - 1 != v78 )
      {
        ++v78;
        goto LABEL_43;
      }
      if ( v47[1] == var4[0] )
      {
        if ( !v47[1] )
        {
          v78 = 0;
          if ( *v47 != 1 )
            goto LABEL_43;
        }
        goto LABEL_127;
      }
      wsoundf = 3;
      v71 = *(_WORD *)(Input1 + 2) + (unsigned __int8)(16 * (*v47 + v79));
      v50 = 1;
    }
    else
    {
      if ( v78 )
      {
        --v78;
LABEL_43:
        wsoundf = 3;
        goto LABEL_127;
      }
      if ( !var4[0] )
      {
        if ( !v47[1] )
        {
          v78 = *v47 - 1;
          if ( *v47 != 1 )
            goto LABEL_43;
        }
LABEL_127:
        wasmTaskEntry();
LABEL_67:
        if ( Wcheckkeyok() )
        {
          scrollupdown(Input1, var4, &v79, &v78);
          ClearImage(&v66, 0, 0, 0);
        }
        goto LABEL_69;
      }
      wsoundf = 3;
      v71 = *(_WORD *)(Input1 + 2) + (unsigned __int8)(16 * v79 - 16);
      v50 = -1;
    }
    v73 = 16;
    memset(&optionbuffer, 0, 0x800u);
    v16 = v47;
    v17 = 0;
    dword_26C8F8 = *(__int16 *)(Input1 + 4);
    v18 = v47;
    do
    {
      v19 = v78 + var4[0] + v50;
      Wloadcdst(v16[2], 0);
      if ( v16[5] != 2 )
        wkanjicolor = *(__int16 *)(2 * v19 + *((_DWORD *)v18 + 7));
      if ( wkanjicolor == 4 )
        dword_26C8FC = 1145324612;
      v20 = (unsigned __int16)v16[5];
      if ( v16[5] )
      {
        if ( v20 == 1 )
        {
          Wstatusfigprint10(*(__int16 *)(2 * v19 + *((_DWORD *)v18 + 4)), 2, &optionbuffer, &wcdst);
        }
        else if ( (__int16)v20 == 3 )
        {
          Wstatusfigprint16(*(__int16 *)(2 * v19 + *((_DWORD *)v18 + 4)), 2, &optionbuffer, &wcdst);
        }
      }
      else
      {
        Wstatuskanjiprint(
          *(__int16 *)(2 * v19 + *((_DWORD *)v18 + 4)),
          (unsigned int)&optionbuffer,
          (unsigned int)&wcdst);
      }
      ++v17;
      ++v16;
      v18 += 2;
    }
    while ( v17 != 3 );
    dword_26C8FC = 0;
    wkanjicolor = 0;
    PSX_LoadImage(&v70, &optionbuffer);
    v68 = v72;
    v66 = v70;
    v67 = (unsigned __int8)(v71 - 2) + (v71 & 0xFF00);
    v69 = 2;
    ClearImage(&v66, 0, 0, 0);
    wasmTaskEntry();
LABEL_69:
    *(_WORD *)(Input1 + 56) = LOWORD(var4[0]) + v78;
    *(_WORD *)(Input1 + 58) = var4[0];
    iOS_setPadState(0);
    if ( Wmultiwindow_break(v45) )
    {
      Wsend_taskparamater(15, 0, 0, 1);
      iOS_CMenuTouch::setDispAssist((iOS_CMenuTouch *)v54, 0);
      *(_WORD *)(Input1 + 58) = var4[0];
      wasmTaskEntry();
      Wtask_killmyself();
    }
    if ( !v50 )
      Wmultiwindow_keyright(Input1, v78);
    Wmultiwindow_keydown(Input1);
    if ( i == 1 )
    {
      if ( (Wget_padframe() & 1) != 0 )
        goto LABEL_79;
    }
    else if ( i != 2 )
    {
      goto LABEL_79;
    }
    if ( v51 >= (unsigned __int8)scroll2_delay )
      v49 += 2 * (unsigned __int8)scroll2_speed * v50;
    else
      v49 += 2 * (unsigned __int8)scroll1_speed * v50;
LABEL_79:
    if ( (unsigned int)(v49 + 15) > 0x1E )
    {
      v79 += v50;
      var4[0] += v50;
      if ( Wget_padframe() >= (unsigned __int8)keyrept1_delay / i )
        *v45 |= *v46 & 0x5000;
      v50 = 0;
      v49 = 0;
    }
    v21 = v48 & 1;
    v22 = (char *)&pr + 468 * v21;
    v23 = v22 + 16;
    v22[17] = v49 + 16 * v79;
    if ( wasmGetActiveF() || wallgrayf == 1 )
      v24 = 32637;
    else
      v24 = 32764;
    *((_WORD *)v23 + 1) = v24;
    if ( v47[1] && Wcheckkeyok() )
    {
      v25 = var4[0];
      if ( var4[0] )
      {
        Waddlocalprim((char *)&pr + 468 * v21 + 24);
        Waddlocalprim((char *)&pr + 468 * v21 + 72);
        v25 = var4[0];
      }
      if ( v47[1] != v25 )
      {
        Waddlocalprim((char *)&pr + 468 * v21 + 48);
        Waddlocalprim((char *)&pr + 468 * v21 + 96);
      }
      v26 = (_WORD *)((char *)&pr + 468 * v21);
      v27 = (__int16)v26[23];
      v28 = (__int16)v26[31];
      v26[66] = v26[18];
      v26[67] = v27 + v26[19] - 2 + *(__int16 *)(Input1 + 56) * (v28 - (v27 + (__int16)v26[19])) / (v47[1] + *v47);
      Waddlocalprim((char *)&pr + 468 * v21 + 120);
    }
    v29 = *(_DWORD *)(Input1 + 12);
    v64[0] = *(_DWORD *)(Input1 + 8);
    v64[1] = v29;
    LOWORD(v64[0]) += 42;
    v30 = 468 * v21;
    v31 = (char *)&pr + 468 * v21;
    Wmultiwindow_packetclip((char *)&pr + 468 * v21 + 420, v64, v48, fbuf_idx);
    Wmultiwindow_loadcolor2(*((_DWORD *)v31 + 80));
    if ( *(__int16 *)(Input1 + 44) > 4 )
      Waddlocalprim(*((_DWORD *)v31 + 80));
    Waddlocalprim((char *)&pr + v30 + 436);
    Waddlocalprim((char *)&pr + v30 + 160);
    Waddlocalprim((char *)&pr + 468 * v21);
    if ( *((__int16 *)v31 + 11) + (unsigned __int8)v31[17] > 255 )
    {
      v32 = &var4[6 * v21 + 1];
      v33 = *((_DWORD *)v31 + 1);
      v34 = *((_DWORD *)v31 + 2);
      v35 = *((_DWORD *)v31 + 3);
      v36 = v32 - 66;
      *v36 = *(_DWORD *)v31;
      v36[1] = v33;
      v36[2] = v34;
      v36[3] = v35;
      v37 = v32 - 62;
      v38 = *((_DWORD *)v31 + 5);
      *v37 = *((_DWORD *)v31 + 4);
      v37[1] = v38;
      SetSprt(&v56[3 * v21]);
      v39 = (unsigned __int8)v31[17];
      *((_WORD *)v32 - 125) = *((_WORD *)v31 + 7) + 256 - v39;
      *((_WORD *)v32 - 121) = v39 + *((_WORD *)v31 + 11) - 256;
      *((_BYTE *)v32 - 247) = 0;
      Waddlocalprim(&v56[3 * v21]);
    }
    Waddlocalprim((char *)&pr + v30 + 144);
    Waddlocalprim((char *)&pr + 468 * v21 + 420);
    Wmultiwindow_packetcolor((char *)&pr + v30 + 192);
    Wmultiwindow_packetanm(Input1, (char *)&pr + v30 + 192, v48, v78);
    if ( wasmGetActiveF() || wallgrayf == 1 || v50 || !Wcheckkeyok() )
      goto LABEL_107;
    v40 = v48 == 0;
    if ( v48 )
      v40 = *(_DWORD *)(Input1 + 60) == 0;
    if ( v40 || iOS_getLockInput() )
LABEL_107:
      v41 = 0;
    else
      v41 = v55;
    Wcheckkeyok();
    v42 = (_WORD *)((char *)&pr + 468 * v21);
    v43 = v42[131];
    v42[118] = 1000;
    v42[131] = v43 + 4;
    v42[143] += 4;
    Wmultiwindow_packetadd((char *)&pr + v30 + 192, *(_DWORD *)(Input1 + 60), v41);
    iOS_CMenuTouch::setYLine((iOS_CMenuTouch *)v54, v78);
    if ( !wasmGetActiveF() && wallgrayf != 1 && !v50 && Wcheckkeyok() )
    {
      v44 = v48 == 0;
      if ( v48 )
        v44 = *(_DWORD *)(Input1 + 60) == 0;
      if ( !v44 && !iOS_getLockInput() )
        WiOS_assist_addlocalprim2((iOS_CMenuTouch *)v54, v78);
    }
    ++v48;
  }
  iOS_CMenuTouch::setDispAssist((iOS_CMenuTouch *)v54, 0);
LABEL_66:
  wasmTaskEntry();
  if ( v50 )
    goto LABEL_69;
  goto LABEL_67;
}

