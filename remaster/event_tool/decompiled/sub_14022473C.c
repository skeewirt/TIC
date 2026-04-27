// sub_14022473C @ 0x14022473C (2412 bytes)
// Decompiled by IDA Pro - Event System Phase 0 (batch 2)

__int64 __fastcall ask_event(int a1, int a2, signed int a3, __int64 a4, int a5, __int64 a6)
{
  __int64 v6; // r14
  __int64 v7; // rdi
  int v9; // ecx
  void *v10; // rax
  __int64 v11; // r8
  __int64 v12; // r10
  __int64 v13; // r11
  __int64 v14; // rdx
  unsigned int v15; // ebx
  unsigned int eventflag; // r15d
  int v17; // esi
  int v18; // r11d
  int v19; // eax
  int v20; // ecx
  __int64 v21; // rdx
  __int64 v22; // rdx
  int v23; // eax
  __int64 result; // rax
  bool v25; // zf
  int v26; // eax
  __int64 v27; // rcx
  unsigned int v28; // eax
  _QWORD *v29; // rcx
  __int64 v30; // rdx
  __int64 v31; // rax
  int v32; // edx
  __int64 v33; // rdx
  int v34; // eax
  __int64 v35; // r8
  __int64 v36; // r8
  unsigned int v37; // ebp
  __int64 v38; // rax
  int v39; // edx
  __int64 v40; // rax
  __int64 v41; // rdx
  int v42; // eax
  __int64 CommonData; // rbx
  __int64 v44; // r8
  __int64 v45; // rdx
  int v46; // eax
  unsigned int v47; // r10d
  __int16 v48; // ax
  __int64 v49; // r8
  __int64 v50; // rax
  int v51; // edx
  int v52; // r9d
  __int16 v53; // ax
  _DWORD *v54; // rcx
  __int64 v55; // rax

  v6 = a3;
  v7 = a2;
  if ( qword_143CD3500 )
  {
    v9 = *(_DWORD *)(qword_143CD3500 + 8);
    if ( !v9 )
    {
      v10 = &unk_1407FB020;
      goto LABEL_9;
    }
    if ( v9 == 3 )
    {
      v10 = &unk_1407FDB80;
      goto LABEL_9;
    }
  }
  else
  {
    v9 = 1;
  }
  v10 = &unk_1407FC5D0;
  if ( v9 == 2 )
    v10 = &unk_1407FF130;
LABEL_9:
  dword_14077CD0C = -1;
  lastbgm1 = (__int64)v10;
  byte_142FC930B = 0;
  if ( (unsigned int)a3 > 0x14 )
  {
    v14 = 417;
    v11 = 422;
    v12 = 420;
    v13 = 418;
  }
  else
  {
    v11 = (__int64)&unk_14184DA36 + 512 * (__int64)a3;
    v12 = (__int64)&unk_14184DA34 + 512 * v6;
    v13 = (__int64)&unk_14184DA32 + 512 * v6;
    v14 = (__int64)&unk_14184DA31 + 512 * v6;
  }
  v15 = 8;
  if ( a1 == 8 )
  {
    eventflag = read_eventflag(39, v14);
    if ( eventflag - 410 > 0xF && !word_140D3A41C )
    {
      if ( (_DWORD)v7 == 1 )
        goto LABEL_44;
      if ( !*((_QWORD *)off_14077D0A8 + 274) )
      {
        dword_1407D5F6C = v6;
        v17 = 0;
        v18 = 0;
        do
        {
          v19 = sub_14025E3E8((unsigned int)(v18 + 1));
          v20 = v17 + 1;
          if ( v19 != -3 )
            v20 = v17;
          v17 = v20;
        }
        while ( v18 < 3 );
        if ( ((int)j_check_game_cont() < 0 || v17) && !(unsigned int)read_eventflag(509, v21) )
        {
          if ( (_DWORD)v7 != 2 )
          {
            write_eventflag(39, 400);
            sub_140220A78(0, 255, 255);
            word_140D3A38C = 1;
LABEL_39:
            word_140D3A37C = 1;
            goto LABEL_40;
          }
          dword_142FF1C0C = 400;
          return 2;
        }
        if ( word_140D3A37C )
        {
          if ( (unsigned int)j_ChangeToNextEventState() )
          {
            if ( (_DWORD)v7 == 2 )
            {
              dword_142FF1C0C = read_eventflag(39, v14);
              write_eventflag(39, eventflag);
              return 2;
            }
            sub_140220A78(0, 255, 255);
            word_140D3A38C = 1;
LABEL_40:
            BeginRunningEvent();
            return 2;
          }
        }
        else
        {
          if ( (unsigned int)read_eventflag(509, v21) )
          {
            if ( (_DWORD)v7 == 2 )
            {
              dword_142FF1C0C = 401;
              return 2;
            }
            sub_140220A78(0, 255, 255);
            word_140D3A38C = 1;
            v23 = read_eventflag(510, v22);
            write_eventflag(39, v23 != 0 ? 403 : 401);
            goto LABEL_40;
          }
          if ( !(unsigned int)j_check_game_cont() )
          {
            if ( (_DWORD)v7 == 2 )
            {
              dword_142FF1C0C = 402;
              return 2;
            }
            sub_140220A78(0, 255, 255);
            word_140D3A38C = 1;
            write_eventflag(39, 402);
            goto LABEL_39;
          }
        }
      }
    }
    if ( (_DWORD)v7 == 2 )
      return 1;
LABEL_44:
    j___Run_minievent(8, v14, v11);
    return 1;
  }
  if ( !a5 )
    goto LABEL_44;
  switch ( a1 )
  {
    case 1:
      if ( dword_142FCCF30 && dword_142FCCF30 != 25 )
      {
        switch ( dword_142FCCF30 )
        {
          case 1:
            v15 = 41;
            byte_142FC930B = 1;
            v14 = 6;
            if ( (_DWORD)v7 != 1 )
              v15 = 6;
            break;
          case 12:
            v15 = 20;
            break;
          case 14:
            v15 = 21;
            break;
          default:
            if ( dword_142FCAF4C == 2 )
              v15 = 28;
            break;
        }
        goto LABEL_63;
      }
      v15 = 7;
      v25 = (_DWORD)v7 == 2;
      v26 = 49;
LABEL_61:
      if ( v25 )
        v15 = v26;
      goto LABEL_63;
    case 2:
      if ( (_DWORD)v7 )
      {
        if ( (_DWORD)v7 == 1 )
        {
          v15 = 0;
        }
        else if ( (_DWORD)v7 == 4 )
        {
          v15 = 48;
        }
        else
        {
          v15 = 60;
          if ( (_DWORD)v7 != 5 )
            v15 = v7 + 13;
        }
      }
      goto LABEL_63;
    case 3:
      if ( dword_1407D615C != 2 || dword_1407D6398 != 1 )
        v15 = 1;
      goto LABEL_63;
    case 4:
      if ( (_DWORD)v7 == 5 )
      {
        v28 = 47;
      }
      else if ( (_DWORD)v7 == 1 )
      {
        v28 = 11;
      }
      else if ( (((_DWORD)v7 - 2) & 0xFFFFFFFD) != 0 )
      {
        if ( dword_1407D6144 == 65534 && dword_142FCCF34 )
          v28 = 13;
        else
          v28 = 46;
      }
      else if ( dword_1407D6144 == 65534 || (v28 = 12, !dword_142FCCF34) )
      {
        v28 = 45;
      }
      byte_142FC930B = 1;
      v27 = v28;
      goto LABEL_173;
  }
  if ( a1 != 5 )
  {
    if ( a1 == 7 )
    {
      v31 = *(unsigned __int8 *)v14;
      word_140801D9C = 60;
      if ( byte_140678FB0[v31] == 3 )
      {
        v32 = *(__int16 *)v11;
        LODWORD(xmmword_14077D220) = *(__int16 *)v12 + 28672;
        v33 = (unsigned int)(v32 + 28672);
        v34 = *(__int16 *)v13 + 28672;
        DWORD1(xmmword_14077D220) = v33;
        DWORD2(xmmword_14077D220) = v34;
        Item_EnhancedWordField_1401E7A64(1, v33, v11);
        Item_EnhancedWordField_1401E7A64(0, (unsigned int)xmmword_14077D220, v35);
        Item_EnhancedWordField_1401E7A64(2, DWORD2(xmmword_14077D220), v36);
        v37 = 44;
      }
      else
      {
        v14 = a6;
        if ( *(_BYTE *)(a6 + 1) <= 0x39u && (v11 = 0x300000000100040LL, _bittest64(&v11, *(unsigned __int8 *)(a6 + 1))) )
        {
          LODWORD(xmmword_14077D220) = *(unsigned __int16 *)(a6 + 8) + 14336;
          v38 = pUISoundModule;
          v11 = (unsigned int)*(unsigned __int16 *)(a6 + 8) + 14336;
          if ( pUISoundModule )
          {
            *(_DWORD *)(pUISoundModule + 8) = 4;
            *(_DWORD *)(v38 + 12) = v11;
          }
        }
        else
        {
          v39 = *(_WORD *)(a6 + 2) & 0x1FF;
          if ( (unsigned int)(v39 - 60) > 0x19 )
          {
            v41 = (unsigned int)(v39 + 28672);
            LODWORD(xmmword_14077D220) = v41;
            Item_EnhancedWordField_1401E7A64(0, v41, v11);
          }
          else
          {
            v40 = pUISoundModule;
            v14 = (unsigned int)(v39 + 47044);
            LODWORD(xmmword_14077D220) = v14;
            if ( pUISoundModule )
            {
              *(_DWORD *)(pUISoundModule + 8) = 7;
              *(_DWORD *)(v40 + 12) = v14;
            }
          }
        }
        v37 = 10;
      }
      goto LABEL_104;
    }
    v14 = 6;
    switch ( a1 )
    {
      case 6:
LABEL_63:
        v27 = v15;
LABEL_173:
        j___Run_minievent(v27, v14, v11);
        goto LABEL_174;
      case 9:
        switch ( (_DWORD)v7 )
        {
          case 1:
            v15 = 22;
            break;
          case 2:
            v15 = 23;
            break;
          case 3:
            v15 = 32;
            break;
          default:
            if ( dword_142FCCF30 != 12 )
            {
              v26 = 27;
              v25 = dword_142FCCF30 == 14;
              goto LABEL_61;
            }
            v15 = 26;
            break;
        }
        goto LABEL_63;
      case 10:
        if ( (dword_14077CA24 & 0x180000) == 0 )
        {
          LODWORD(xmmword_14077D220) = (unsigned __int8)a4;
          word_1408039B2 = v7;
          j_SetWorldFieldValue(0, (unsigned __int8)a4, v11, a4);
          v15 = 29;
        }
        goto LABEL_63;
      case 11:
        LODWORD(xmmword_14077D220) = v7 + 28672;
        Item_EnhancedWordField_1401E7A64(0, (unsigned int)(v7 + 28672), v11);
        v27 = 30;
        goto LABEL_173;
      case 12:
        v27 = 31;
        goto LABEL_173;
      case 13:
        v27 = 33;
        goto LABEL_173;
      case 18:
        v27 = 58;
        goto LABEL_173;
      case 14:
        v27 = (unsigned int)(v7 + 51);
        goto LABEL_173;
      case 15:
        v42 = sub_140274F30((unsigned __int16)v7, 6, v11);
        LODWORD(xmmword_14077D220) = v7;
        DWORD1(xmmword_14077D220) = v7;
        if ( v42 < 99 )
        {
          ++byte_1411A17C0[v7];
          sub_1401E7A90(0, (unsigned int)v7);
          sub_1401E7A90(1, DWORD1(xmmword_14077D220));
          v37 = 39;
        }
        else
        {
          CommonData = ItemGetCommonData(v7 & 0x1FF);
          DWORD2(xmmword_14077D220) = *(unsigned __int16 *)(CommonData + 8) >> 2;
          sub_1401E7A90(0, (unsigned int)v7);
          sub_1401E7A90(1, DWORD1(xmmword_14077D220));
          EnhancedWordfield_WriteID(2, DWORD2(xmmword_14077D220), v44);
          v46 = read_eventflag(44, v45);
          write_eventflag(44, v46 + (*(unsigned __int16 *)(CommonData + 8) >> 2));
          v37 = 38;
        }
LABEL_104:
        v27 = v37;
        goto LABEL_173;
      case 16:
        v27 = 40;
        goto LABEL_173;
    }
    if ( a1 != 17 )
    {
      j___Run_minievent(8, 6, v11);
      result = 0;
      goto LABEL_176;
    }
    v47 = 50;
    if ( (unsigned int)(v7 - 39) > 6 )
    {
      if ( (_DWORD)v7 == 46 )
      {
        LODWORD(xmmword_14077D220) = abs32(a4);
        EnhancedWordfield_WriteID(0, (unsigned int)xmmword_14077D220, v11);
        v14 = 20623;
      }
      else
      {
        if ( (_DWORD)v7 != 47 )
        {
          if ( (unsigned int)(v7 - 28) <= 1 )
          {
            v55 = pUISoundModule;
            if ( (a4 & 0x8000) != 0 )
            {
              v14 = (unsigned int)(unsigned __int8)a4 + 14336;
              LODWORD(xmmword_14077D220) = (unsigned __int8)a4 + 14336;
              if ( pUISoundModule )
              {
                *(_DWORD *)(pUISoundModule + 8) = 4;
                *(_DWORD *)(v55 + 12) = v14;
              }
              v53 = 20635;
            }
            else
            {
              v14 = (unsigned int)(a4 + 14336);
              LODWORD(xmmword_14077D220) = a4 + 14336;
              if ( pUISoundModule )
              {
                *(_DWORD *)(pUISoundModule + 8) = 4;
                *(_DWORD *)(v55 + 12) = v14;
              }
              v53 = v7 + 20596;
            }
            goto LABEL_171;
          }
          if ( (_DWORD)v7 == 50 )
          {
            v53 = 20638;
            goto LABEL_171;
          }
          if ( (_DWORD)v7 == 51 )
          {
            v53 = 20639;
            goto LABEL_171;
          }
          if ( (_DWORD)v7 != 52 )
            goto LABEL_63;
          v54 = (_DWORD *)pUISoundModule;
          v11 = (__int64)&_ImageBase;
          word_140803C52 = 20640;
          v14 = *((unsigned int *)&xmmword_14378F2E0 + (int)a4);
          if ( pUISoundModule )
          {
            *(_DWORD *)(pUISoundModule + 16780) = *((_DWORD *)&xmmword_14378F2C0 + (int)a4);
            v54[4194] = 1;
            v54[4325] = 1;
            v54[4326] = v14;
          }
          goto LABEL_172;
        }
        LODWORD(xmmword_14077D220) = a4 & 0x7F;
        EnhancedWordfield_WriteID(0, a4 & 0x7F, v11);
        v14 = 20622;
      }
      word_140803C52 = v14;
      goto LABEL_172;
    }
    LODWORD(xmmword_14077D220) = v6;
    DWORD1(xmmword_14077D220) = v7 + 20587;
    if ( (_DWORD)v7 == 45 )
    {
      if ( (a4 & 0x80u) != 0LL )
      {
        a4 = 129;
LABEL_148:
        DWORD2(xmmword_14077D220) = a4 & 0x7F;
        v48 = 20620;
        goto LABEL_142;
      }
      a4 = 1;
      DWORD2(xmmword_14077D220) = 1;
    }
    else
    {
      DWORD2(xmmword_14077D220) = a4;
      if ( (a4 & 0x80u) != 0LL )
        goto LABEL_148;
    }
    v48 = 20621;
LABEL_142:
    word_140803C52 = v48;
    j_SetWorldFieldValue(0, (unsigned int)v6, v11, a4);
    v50 = pUISoundModule;
    v51 = DWORD1(xmmword_14077D220);
    if ( pUISoundModule )
    {
      *(_DWORD *)(pUISoundModule + 532) = 8;
      *(_DWORD *)(v50 + 536) = v51;
    }
    EnhancedWordfield_WriteID(2, DWORD2(xmmword_14077D220), v49);
    if ( (_DWORD)v7 != 39 )
      goto LABEL_172;
    if ( v52 == 255 )
    {
      v53 = 20634;
LABEL_171:
      word_140803C52 = v53;
      goto LABEL_172;
    }
    if ( v52 == 127 )
    {
      v53 = 20633;
      goto LABEL_171;
    }
LABEL_172:
    v27 = v47;
    goto LABEL_173;
  }
  dword_142FCAF48 = *(_WORD *)(a6 + 2) & 0x1FF;
  j_task_create(4, sub_14021F598, v11);
  v29 = off_14077D0A8;
  v30 = dword_142FCAF48;
  *((_QWORD *)off_14077D0A8 + 1024) = v6;
  v29[1025] = v30;
  v29[1026] = 0;
LABEL_174:
  result = 1;
LABEL_176:
  dword_1407D6398 = v7;
  dword_1407D615C = a1;
  return result;
}

