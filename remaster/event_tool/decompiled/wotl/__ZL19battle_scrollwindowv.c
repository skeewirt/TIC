// __ZL19battle_scrollwindowv @ 0x1CE2F8 (4340 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn battle_scrollwindow()
{
  int v0; // r8
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
  int v13; // r0
  bool v14; // zf
  int v15; // r4
  bool v16; // zf
  __int16 *v17; // r6
  int v18; // r8
  __int16 *v19; // r4
  int v20; // r5
  int v21; // r3
  int v22; // r10
  char *v23; // r2
  char *v24; // r4
  __int16 v25; // r3
  int v26; // r6
  _WORD *v27; // r3
  int v28; // r1
  int v29; // r0
  int v30; // r1
  int v31; // r6
  char *v32; // r5
  int *v33; // r8
  int v34; // r1
  int v35; // r2
  int v36; // r3
  int *v37; // r12
  int *v38; // r12
  int v39; // r1
  __int16 v40; // r3
  bool v41; // zf
  int v42; // r4
  _WORD *v43; // r3
  __int16 v44; // r2
  bool v45; // zf
  unsigned int *v46; // [sp+44h] [bp-33Ch]
  _DWORD *v47; // [sp+48h] [bp-338h]
  __int16 *v48; // [sp+4Ch] [bp-334h]
  int v49; // [sp+50h] [bp-330h]
  int v50; // [sp+54h] [bp-32Ch]
  int v51; // [sp+58h] [bp-328h]
  int v52; // [sp+5Ch] [bp-324h]
  int v53; // [sp+60h] [bp-320h]
  int i; // [sp+68h] [bp-318h]
  _BYTE v55[18]; // [sp+6Ch] [bp-314h] BYREF
  __int16 v56; // [sp+7Eh] [bp-302h]
  _QWORD v57[6]; // [sp+260h] [bp-120h] BYREF
  _BYTE v58[24]; // [sp+290h] [bp-F0h] BYREF
  _BYTE v59[24]; // [sp+2A8h] [bp-D8h] BYREF
  _BYTE v60[24]; // [sp+2C0h] [bp-C0h] BYREF
  _BYTE v61[24]; // [sp+2D8h] [bp-A8h] BYREF
  _BYTE v62[16]; // [sp+2F0h] [bp-90h] BYREF
  _BYTE v63[24]; // [sp+308h] [bp-78h] BYREF
  _WORD v64[6]; // [sp+320h] [bp-60h] BYREF
  _DWORD v65[2]; // [sp+32Ch] [bp-54h] BYREF
  _WORD v66[4]; // [sp+334h] [bp-4Ch] BYREF
  __int16 v67; // [sp+33Ch] [bp-44h] BYREF
  __int16 v68; // [sp+33Eh] [bp-42h]
  __int16 v69; // [sp+340h] [bp-40h]
  __int16 v70; // [sp+342h] [bp-3Eh]
  __int16 v71; // [sp+344h] [bp-3Ch] BYREF
  __int16 v72; // [sp+346h] [bp-3Ah]
  __int16 v73; // [sp+348h] [bp-38h]
  __int16 v74; // [sp+34Ah] [bp-36h]
  int v75; // [sp+34Ch] [bp-34h] BYREF
  int v76; // [sp+350h] [bp-30h] BYREF
  int v77; // [sp+354h] [bp-2Ch] BYREF
  int v78; // [sp+358h] [bp-28h] BYREF
  int v79; // [sp+35Ch] [bp-24h]
  int v80; // [sp+360h] [bp-20h] BYREF
  int var4[9]; // [sp+364h] [bp-1Ch] BYREF

  iOS_setLockInput(0);
  v0 = 0;
  v1 = &pr;
  v46 = (unsigned int *)import_localpad(0);
  var4[0] = 0;
  v79 = 0;
  v47 = (_DWORD *)import_localpad(1);
  Input1 = asmGetInput1();
  v48 = *(__int16 **)(Input1 + 48);
  *(_WORD *)(Input1 + 14) = 16 * *v48 + 28;
  *(_WORD *)(Input1 + 6) = 16 * *v48 + 28;
  v3 = *v48;
  v64[4] = 8;
  v64[0] = 0;
  v64[5] = 12;
  *(_WORD *)(Input1 + 22) = 16 * v3 + 28;
  v64[1] = 126;
  v64[2] = *(_WORD *)(Input1 + 12) - 18;
  v64[3] = *(_WORD *)(Input1 + 14) - 26;
  initdrmode(&unk_113AFA8, 0);
  v4 = *(unsigned __int8 *)(Input1 + 2);
  v66[0] = 0;
  v66[1] = v4;
  v66[2] = 256;
  v66[3] = 256;
  dword_113B048 = (int)v62;
  dword_113B04C = (int)v60;
  dword_113B050 = (int)v58;
  multiwindow_packetinit(&v71, Input1, &unk_113AFC8);
  dword_113B21C = (int)v63;
  dword_113B220 = (int)v61;
  dword_113B224 = (int)v59;
  multiwindow_packetinit(&v71, Input1, &unk_113B19C);
  multiwindow_packetclipinit(&unk_113B0AC);
  TPage = GetTPage(0, 0, *(_WORD *)Input1 & 0xFFC0, *(_WORD *)(Input1 + 2) & 0xFF00);
  SetDrawMode(&unk_113AF98, 1, 0, TPage, v66);
  do
  {
    initsprt((char *)&pr + 24 * v0 + 24);
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
  initsprt(&unk_113AF80);
  word_113AF94 = 8;
  byte_113AF90 = 16;
  word_113AF96 = 8;
  word_113AF92 = 32124;
  byte_113AF91 = 16;
  initsprt(&pr);
  bgput(&pr, Input1, Input1 + 8, v64);
  word_113AF1E -= 2;
  word_113AF16 += 2;
  initsprtfield(&unk_113AF50, 2, 31804);
  byte_113AF60 = -24;
  byte_113AF78 = -24;
  word_113AF5C = word_113AF2C - 1;
  word_113AF64 = 6;
  word_113AF7C = 4;
  word_113AF5E = word_113AF2E + 3;
  word_113AF7E = 4;
  byte_113AF61 = 0;
  word_113AF74 = word_113AF44;
  word_113AF66 = 12;
  byte_113AF79 = 12;
  word_113AF76 = word_113AF46 + 14;
  asmClearBuffer(&optionbuffer, *(__int16 *)(Input1 + 6) * *(__int16 *)(Input1 + 4) / 2);
  task_create(asmtasknumber + 1, (void (__fastcall *)())world_dispemptywindow);
  send_taskparamater(asmtasknumber + 1, Input1 + 8, 0, 0);
  scrollinit(Input1, var4, (unsigned int)&optionbuffer);
  v80 = 0;
  v73 = dword_274E78 >> 2;
  PSX_LoadImage(&v71, &optionbuffer);
  v70 = 2;
  v67 = v71;
  v68 = (unsigned __int8)(v72 - 2) + (v72 & 0xFF00);
  v69 = v73;
  ClearImage(&v67, 0, 0, 0);
  memcpy(&unk_113B0DC, &pr, 0x1D4u);
  dword_113B048 = (int)v62;
  dword_113B04C = (int)v60;
  dword_113B050 = (int)v58;
  dword_113B21C = (int)v63;
  dword_113B220 = (int)v61;
  dword_113B224 = (int)v59;
  LoadImage_menuData();
  v49 = 0;
  v50 = 0;
  v52 = 0;
  v7 = current_flame;
  v51 = 0;
  v53 = 0;
  if ( current_flame >= 2 )
    v7 = 2;
  for ( i = v7; ; v52 += i )
  {
    if ( !v53 && v49 > 7 )
    {
      xpLibGetOffset(&v78, &v77);
      v8 = v78;
      if ( v78 == 128 )
        v8 = 172;
      v9 = *v48;
      if ( v78 == 128 )
        v78 = v8;
      if ( v48[1] )
        v10 = *v48 + v48[1];
      else
        v10 = *v48;
      iOS_CMenuTouch::init(
        (iOS_CMenuTouch *)v55,
        v9,
        v10,
        0,
        (__int16)(v8 + *(_WORD *)(Input1 + 8)),
        (__int16)(*(_WORD *)(Input1 + 10) + v77 + 15),
        (__int16)(*(_WORD *)(Input1 + 12) - 12),
        16,
        0);
      iOS_CMenuTouch::setDispOffset((iOS_CMenuTouch *)v55, -v78, -v77);
      v53 = 1;
    }
    xpLibGetOffset(&v78, &v77);
    if ( !asmGetActiveF() || allgrayf )
    {
      v11 = Input1 + 8;
      v12 = 0;
      v13 = asmtasknumber + 1;
    }
    else
    {
      v11 = Input1 + 8;
      v12 = 1;
      v13 = asmtasknumber + 1;
    }
    send_taskparamater(v13, v11, v12, 0);
    if ( asmGetActiveF() || allgrayf == 1 )
      break;
    if ( v51 || !checkkeyok() )
      goto LABEL_66;
    v14 = v49 == 0;
    if ( v49 )
      v14 = *(_DWORD *)(Input1 + 60) == 0;
    if ( v14 || iOS_getLockInput() || !v53 )
      goto LABEL_66;
    v76 = v79;
    v75 = var4[0];
    v15 = iOS_CMenuTouch::exec((iOS_CMenuTouch *)v55, &v75, &v76, nullptr);
    if ( v15 == 7 )
    {
      v16 = v79 == v76;
      if ( v79 == v76 )
        v16 = var4[0] == v75;
      if ( !v16 )
      {
        var4[0] = v75;
        v79 = v76;
        soundf = 3;
      }
    }
    iOS_setPadState(0);
    if ( v15 == 2 )
      iOS_battle_scrollwindow_tap();
    if ( (*v46 & 0x1000) == 0 || (*v47 & 0x80) != 0 )
    {
      if ( (*v46 & 0x4000) == 0 || (*v47 & 0x80) != 0 )
      {
        v52 = 0;
        goto LABEL_127;
      }
      if ( *v48 - 1 != v79 )
      {
        ++v79;
        goto LABEL_43;
      }
      if ( v48[1] == var4[0] )
      {
        if ( !v48[1] )
        {
          v79 = 0;
          if ( *v48 != 1 )
            goto LABEL_43;
        }
        goto LABEL_127;
      }
      soundf = 3;
      v72 = *(_WORD *)(Input1 + 2) + (unsigned __int8)(16 * (*v48 + v80));
      v51 = 1;
    }
    else
    {
      if ( v79 )
      {
        --v79;
LABEL_43:
        soundf = 3;
        goto LABEL_127;
      }
      if ( !var4[0] )
      {
        if ( !v48[1] )
        {
          v79 = *v48 - 1;
          if ( *v48 != 1 )
            goto LABEL_43;
        }
LABEL_127:
        asmTaskEntry();
LABEL_67:
        if ( checkkeyok() )
        {
          scrollupdown(Input1, var4, &v80);
          ClearImage(&v67, 0, 0, 0);
        }
        goto LABEL_69;
      }
      soundf = 3;
      v72 = *(_WORD *)(Input1 + 2) + (unsigned __int8)(16 * v80 - 16);
      v51 = -1;
    }
    v74 = 16;
    asmClearBuffer(&optionbuffer, 0x800u);
    v17 = v48;
    v18 = 0;
    dword_274E78 = *(__int16 *)(Input1 + 4);
    v19 = v48;
    do
    {
      v20 = v79 + var4[0] + v51;
      loadcdst(v17[2], 0);
      if ( v17[5] != 2 )
        kanjicolor = *(__int16 *)(2 * v20 + *((_DWORD *)v19 + 7));
      if ( kanjicolor == 4 )
        dword_274E7C = 1145324612;
      v21 = (unsigned __int16)v17[5];
      if ( v17[5] )
      {
        if ( v21 == 1 )
        {
          statusfigprint10(*(__int16 *)(2 * v20 + *((_DWORD *)v19 + 4)), 2, &optionbuffer, &cdst);
        }
        else if ( (__int16)v21 == 3 )
        {
          statusfigprint16(*(__int16 *)(2 * v20 + *((_DWORD *)v19 + 4)), 2, &optionbuffer, &cdst);
        }
      }
      else
      {
        statuskanjiprint(*(__int16 *)(2 * v20 + *((_DWORD *)v19 + 4)), (unsigned int)&optionbuffer, (unsigned int)&cdst);
      }
      ++v18;
      ++v17;
      v19 += 2;
    }
    while ( v18 != 3 );
    dword_274E7C = 0;
    kanjicolor = 0;
    PSX_LoadImage(&v71, &optionbuffer);
    v69 = v73;
    v67 = v71;
    v68 = (unsigned __int8)(v72 - 2) + (v72 & 0xFF00);
    v70 = 2;
    ClearImage(&v67, 0, 0, 0);
    asmTaskEntry();
LABEL_69:
    *(_WORD *)(Input1 + 56) = LOWORD(var4[0]) + v79;
    iOS_setPadState(0);
    if ( multiwindow_break(v46) )
    {
      send_taskparamater(asmtasknumber + 1, 0, 0, 1);
      iOS_CMenuTouch::setDispAssist((iOS_CMenuTouch *)v55, 0);
      asmTaskEntry();
      task_killmyself();
    }
    if ( !v51 )
      multiwindow_keyright(Input1, v79);
    multiwindow_keydown(Input1);
    if ( i == 1 )
    {
      if ( (get_padframe() & 1) != 0 )
        goto LABEL_79;
    }
    else if ( i != 2 )
    {
      goto LABEL_79;
    }
    if ( v52 >= (unsigned __int8)scroll2_delay )
      v50 += 2 * (unsigned __int8)scroll2_speed * v51;
    else
      v50 += 2 * (unsigned __int8)scroll1_speed * v51;
LABEL_79:
    if ( (unsigned int)(v50 + 15) > 0x1E )
    {
      v80 += v51;
      var4[0] += v51;
      if ( get_padframe() >= (unsigned __int8)keyrept1_delay / i )
        *v46 |= *v47 & 0x5000;
      v51 = 0;
      v50 = 0;
    }
    v22 = v49 & 1;
    v23 = (char *)&pr + 468 * v22;
    v24 = v23 + 16;
    v23[17] = v50 + 16 * v80;
    if ( asmGetActiveF() || allgrayf == 1 )
      v25 = 32637;
    else
      v25 = 32764;
    *((_WORD *)v24 + 1) = v25;
    if ( v48[1] && checkkeyok() )
    {
      v26 = var4[0];
      if ( var4[0] )
      {
        addlocalprim((char *)&pr + 468 * v22 + 24);
        addlocalprim((char *)&pr + 468 * v22 + 72);
        v26 = var4[0];
      }
      if ( v48[1] != v26 )
      {
        addlocalprim((char *)&pr + 468 * v22 + 48);
        addlocalprim((char *)&pr + 468 * v22 + 96);
      }
      v27 = (_WORD *)((char *)&pr + 468 * v22);
      v28 = (__int16)v27[23];
      v29 = (__int16)v27[31];
      v27[66] = v27[18];
      v27[67] = v28 + v27[19] - 2 + *(__int16 *)(Input1 + 56) * (v29 - (v28 + (__int16)v27[19])) / (v48[1] + *v48);
      addlocalprim((char *)&pr + 468 * v22 + 120);
    }
    v30 = *(_DWORD *)(Input1 + 12);
    v65[0] = *(_DWORD *)(Input1 + 8);
    v65[1] = v30;
    LOWORD(v65[0]) += 42;
    v31 = 468 * v22;
    v32 = (char *)&pr + 468 * v22;
    multiwindow_packetclip((char *)&pr + 468 * v22 + 420, v65, v49, gTheFlame);
    multiwindow_loadcolor2(*((_DWORD *)v32 + 80));
    if ( *(__int16 *)(Input1 + 44) > 4 )
      addlocalprim(*((_DWORD *)v32 + 80));
    addlocalprim((char *)&pr + v31 + 436);
    addlocalprim((char *)&pr + v31 + 160);
    addlocalprim((char *)&pr + 468 * v22);
    if ( *((__int16 *)v32 + 11) + (unsigned __int8)v32[17] > 255 )
    {
      v33 = &var4[6 * v22 + 1];
      v34 = *((_DWORD *)v32 + 1);
      v35 = *((_DWORD *)v32 + 2);
      v36 = *((_DWORD *)v32 + 3);
      v37 = v33 - 66;
      *v37 = *(_DWORD *)v32;
      v37[1] = v34;
      v37[2] = v35;
      v37[3] = v36;
      v38 = v33 - 62;
      v39 = *((_DWORD *)v32 + 5);
      *v38 = *((_DWORD *)v32 + 4);
      v38[1] = v39;
      SetSprt(&v57[3 * v22]);
      v40 = (unsigned __int8)v32[17];
      *((_WORD *)v33 - 125) = *((_WORD *)v32 + 7) + 256 - v40;
      *((_WORD *)v33 - 121) = v40 + *((_WORD *)v32 + 11) - 256;
      *((_BYTE *)v33 - 247) = 0;
      addlocalprim(&v57[3 * v22]);
    }
    addlocalprim((char *)&pr + v31 + 144);
    addlocalprim((char *)&pr + 468 * v22 + 420);
    multiwindow_packetcolor((char *)&pr + v31 + 192);
    multiwindow_packetanm(Input1, (char *)&pr + v31 + 192, v49, v79);
    if ( asmGetActiveF() || allgrayf == 1 || v51 || !checkkeyok() )
      goto LABEL_107;
    v41 = v49 == 0;
    if ( v49 )
      v41 = *(_DWORD *)(Input1 + 60) == 0;
    if ( v41 || iOS_getLockInput() )
LABEL_107:
      v42 = 0;
    else
      v42 = v56;
    checkkeyok();
    v43 = (_WORD *)((char *)&pr + 468 * v22);
    v44 = v43[131];
    v43[118] = 1000;
    v43[131] = v44 + 4;
    v43[143] += 4;
    multiwindow_packetadd((char *)&pr + v31 + 192, *(_DWORD *)(Input1 + 60), v42);
    iOS_CMenuTouch::setYLine((iOS_CMenuTouch *)v55, v79);
    if ( !asmGetActiveF() && allgrayf != 1 && !v51 && checkkeyok() )
    {
      v45 = v49 == 0;
      if ( v49 )
        v45 = *(_DWORD *)(Input1 + 60) == 0;
      if ( !v45 && !iOS_getLockInput() )
        iOS_assist_addlocalprim2((iOS_CMenuTouch *)v55, v79);
    }
    ++v49;
  }
  iOS_CMenuTouch::setDispAssist((iOS_CMenuTouch *)v55, 0);
LABEL_66:
  asmTaskEntry();
  if ( v51 )
    goto LABEL_69;
  goto LABEL_67;
}

