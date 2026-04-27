// __ZL13ask_eventmainiiiP7SVECTORiP3ACT @ 0x619C4 (2820 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall ask_eventmain(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int bwp; // r0
  int v10; // r6
  int ActiveTask; // r4
  int v13; // r8
  __int16 *v14; // r3
  int v15; // r1
  bool v16; // zf
  int v17; // r0
  int v18; // r3
  bool v19; // zf
  int v20; // r3
  bool v21; // zf
  int v22; // r2
  int itemcommon; // r0
  int v24; // r4
  int eventflag; // r0
  int v26; // r3
  __int16 v27; // r0
  __int16 v28; // r1

  TRACE_Dummy("     ask_eventmain %d,%d,%d,%d\n", a1, a2, a3, a5);
  combase = (int)&comtest;
  lastcommandno = -1;
  cancelok = 0;
  bwp = get_bwp(a3);
  if ( a1 != 8 )
  {
    if ( !a5 )
    {
      TRACE_Dummy(" G drive_minievent\n");
      goto LABEL_8;
    }
    switch ( a1 )
    {
      case 1:
        TRACE_Dummy("PHASE_MENUEND\n");
        v16 = lastmaincommand == 25;
        if ( lastmaincommand != 25 )
          v16 = lastmaincommand == 0;
        if ( v16 )
        {
          if ( a2 == 2 )
          {
            TRACE_Dummy("EXCEPTION_CANNOTMOVE\n");
            v17 = 49;
          }
          else
          {
            v17 = 7;
          }
        }
        else
        {
          switch ( lastmaincommand )
          {
            case 1:
              cancelok = 1;
              if ( a2 == 1 )
                v17 = 41;
              else
                v17 = 6;
              break;
            case 12:
              v17 = 20;
              break;
            case 14:
              v17 = 21;
              break;
            default:
              if ( lastactioncommand == 2 )
                v17 = 28;
              else
                v17 = 8;
              break;
          }
        }
        goto LABEL_83;
      case 2:
        v18 = 1;
        soundf = 1;
        if ( a2 )
        {
          if ( a2 == 1 )
          {
            v17 = 0;
          }
          else
          {
            if ( a2 == 4 )
            {
              v17 = 48;
            }
            else
            {
              v17 = a2 + 13;
              v18 = 5;
            }
            if ( a2 != 4 )
              soundf = v18;
          }
          goto LABEL_83;
        }
        TRACE_Dummy(" H drive_minievent\n");
        goto LABEL_82;
      case 3:
        if ( lastphaseno != 2 || lastexception != 1 )
        {
          v17 = 1;
          goto LABEL_83;
        }
        TRACE_Dummy(" I drive_minievent\n");
LABEL_82:
        v17 = 8;
LABEL_83:
        drive_minievent(v17);
LABEL_192:
        lastphaseno = a1;
        lastexception = a2;
        return 1;
      case 4:
        if ( a2 == 5 )
        {
          v17 = 47;
        }
        else if ( a2 == 1 )
        {
          v17 = 11;
        }
        else
        {
          v19 = a2 == 4;
          if ( a2 != 4 )
            v19 = a2 == 2;
          if ( v19 )
          {
            if ( lastabilitycommand == 65534 || !lastchargetime )
              v17 = 45;
            else
              v17 = 12;
          }
          else if ( lastabilitycommand == 65534 && lastchargetime )
          {
            v17 = 13;
          }
          else
          {
            v17 = 46;
          }
        }
        cancelok = 1;
        goto LABEL_83;
      case 5:
        lastspell = *(_WORD *)(a6 + 2) & 0x1FF;
        task_create(4, (char *)hook_spel);
        send_taskparamater(4, a3, lastspell, 0);
        goto LABEL_192;
      case 7:
        platetime = 60;
        if ( comtype[*(unsigned __int8 *)(bwp + 401)] == 3 )
        {
          dword_274DB4 = *(__int16 *)(bwp + 406) + 28672;
          wordfield = *(__int16 *)(bwp + 404) + 28672;
          dword_274DB8 = *(__int16 *)(bwp + 402) + 28672;
          v17 = 44;
        }
        else
        {
          v20 = *(unsigned __int8 *)(a6 + 1);
          v21 = v20 == 20;
          if ( v20 != 20 )
            v21 = v20 == 6;
          if ( v21 )
          {
            wordfield = *(unsigned __int16 *)(a6 + 8) + 14336;
          }
          else
          {
            v22 = *(_WORD *)(a6 + 2) & 0x1FF;
            if ( (unsigned int)(v22 - 60) > 0x19 )
              wordfield = v22 + 28672;
            else
              wordfield = v22 + 47044;
          }
          v17 = 10;
        }
        goto LABEL_83;
      case 6:
        TRACE_Dummy(" J drive_minievent\n");
        goto LABEL_82;
      case 9:
        switch ( a2 )
        {
          case 1:
            v17 = 22;
            break;
          case 2:
            v17 = 23;
            break;
          case 3:
            v17 = 32;
            break;
          default:
            if ( lastmaincommand == 12 )
            {
              v17 = 26;
            }
            else if ( lastmaincommand == 14 )
            {
              v17 = 27;
            }
            else
            {
              v17 = 8;
            }
            break;
        }
        goto LABEL_83;
      case 10:
        TRACE_Dummy("PHASE_STTSMES\n");
        if ( (byte_29EB12 & 3) == 0 )
        {
          v17 = 29;
          word_27C59A = a2;
          wordfield = (unsigned __int8)a4;
          goto LABEL_83;
        }
        TRACE_Dummy(" K drive_minievent\n");
        goto LABEL_82;
      case 11:
        v17 = 30;
        wordfield = a2 + 28672;
        goto LABEL_83;
      case 12:
        v17 = 31;
        goto LABEL_83;
      case 13:
        v17 = 33;
        goto LABEL_83;
      case 14:
        v17 = a2 + 51;
        goto LABEL_83;
      case 15:
        if ( (int)get_item_number(a2, 1) <= 98 )
        {
          ++PartyItem[a2];
        }
        else if ( !(unsigned __int8)pspNetGetBattleModeFlag() )
        {
          get_itemcommon(a2);
          wordfield = a2;
          dword_274DB4 = a2;
          itemcommon = get_itemcommon(a2);
          dword_274DB8 = *(unsigned __int16 *)(itemcommon + 8) >> 2;
          v24 = *(unsigned __int16 *)(itemcommon + 8) >> 2;
          eventflag = read_eventflag(44);
          write_eventflag(44, eventflag + v24);
          v17 = 38;
          goto LABEL_83;
        }
        get_itemcommon(a2);
        v17 = 39;
        wordfield = a2;
        goto LABEL_83;
      case 16:
        v17 = 40;
        goto LABEL_83;
    }
    if ( a1 != 17 )
    {
      system_error(7, 5);
      TRACE_Dummy(" M drive_minievent\n");
      drive_minievent(8);
      lastphaseno = a1;
      lastexception = a2;
      return 0;
    }
    v26 = a4;
    if ( (unsigned int)(a2 - 39) > 6 )
    {
      if ( a2 == 46 )
      {
        if ( a4 < 0 )
          v26 = -a4;
        v28 = 20623;
        wordfield = v26;
      }
      else if ( a2 == 47 )
      {
        v28 = 20622;
        wordfield = a4 & 0x7F;
      }
      else
      {
        if ( (unsigned int)(a2 - 28) > 1 )
        {
          TRACE_Dummy(" L drive_minievent\n");
          goto LABEL_82;
        }
        if ( (a4 & 0x8000) == 0 )
        {
          wordfield = a4 + 14336;
          word_27C73E = a2 + 20596;
          goto LABEL_185;
        }
        wordfield = (unsigned __int8)a4 + 14336;
        v28 = 20635;
      }
      goto LABEL_184;
    }
    wordfield = a3;
    dword_274DB4 = a2 + 20587;
    if ( a2 == 45 )
    {
      if ( (a4 & 0x80) != 0 )
      {
        v26 = 129;
        dword_274DB8 = 129;
LABEL_171:
        v27 = 20620;
        dword_274DB8 = v26 & 0x7F;
        goto LABEL_173;
      }
      v26 = 1;
      dword_274DB8 = 1;
    }
    else
    {
      dword_274DB8 = a4;
      if ( (a4 & 0x80) != 0 )
        goto LABEL_171;
    }
    v27 = 20621;
LABEL_173:
    word_27C73E = v27;
    if ( a2 == 39 )
    {
      if ( v26 == 255 )
      {
        v28 = 20634;
LABEL_184:
        word_27C73E = v28;
        goto LABEL_185;
      }
      if ( v26 == 127 )
      {
        v28 = 20633;
        goto LABEL_184;
      }
    }
LABEL_185:
    v17 = 50;
    goto LABEL_83;
  }
  v10 = read_eventflag(39);
  if ( (unsigned int)(v10 - 410) <= 0xF )
  {
    if ( a2 != 2 )
    {
      TRACE_Dummy(" A drive_minievent\n");
LABEL_8:
      drive_minievent(8);
      return 1;
    }
    return 1;
  }
  if ( tutorialstartf )
  {
    if ( a2 != 2 )
    {
      TRACE_Dummy(" B drive_minievent\n");
      goto LABEL_8;
    }
    return 1;
  }
  if ( a2 == 1 )
  {
    TRACE_Dummy(" C drive_minievent\n");
    drive_minievent(8);
    return a2;
  }
  ActiveTask = asmGetActiveTask(1);
  if ( ActiveTask )
  {
    system_error(7, 3);
    if ( a2 == 2 )
      return 1;
    TRACE_Dummy(" D drive_minievent\n");
    goto LABEL_8;
  }
  atchr = a3;
  if ( get_netmodeadhoc() == 1 )
  {
    v13 = 0;
  }
  else
  {
    v13 = 0;
    do
    {
      if ( search_character_f(++ActiveTask) == -3 )
        ++v13;
    }
    while ( ActiveTask != 3 );
  }
  if ( pspNetGetErrorCode() && pspNetGetInterruptEndFlag() == 1 )
    ++v13;
  if ( (int)check_game_cont() >= 0 && !v13 || read_eventflag(509) )
  {
    if ( jumpeventno )
    {
      if ( !check_eventstart() )
      {
        if ( a2 == 2 )
          return 1;
        TRACE_Dummy(" E drive_minievent\n");
        goto LABEL_8;
      }
      if ( a2 == 2 )
      {
        checkeventno = read_eventflag(39);
        write_eventflag(39, v10);
        return a2;
      }
      request_status(0, 255, 255);
      v14 = &stoprequest;
      goto LABEL_196;
    }
    if ( read_eventflag(509) )
    {
      if ( a2 == 2 )
      {
        checkeventno = 401;
        return a2;
      }
      request_status(0, 255, 255);
      stoprequest = 1;
      if ( read_eventflag(510) )
        v15 = 403;
      else
        v15 = 401;
      write_eventflag(39, v15);
      goto LABEL_197;
    }
    if ( check_game_cont() )
    {
      if ( !(unsigned __int8)pspNetGetBattleModeFlag() || get_limit_turn_flg() != 1 )
      {
        if ( a2 == 2 )
          return 1;
        TRACE_Dummy(" F drive_minievent\n");
        goto LABEL_8;
      }
      if ( a2 == 2 )
      {
        checkeventno = 402;
        return a2;
      }
      request_status(0, 255, 255);
      stoprequest = 1;
      write_eventflag(39, 402);
      jumpeventno = 1;
      goto LABEL_197;
    }
    if ( a2 == 2 )
    {
      checkeventno = 402;
      return a2;
    }
    goto LABEL_195;
  }
  if ( a2 == 2 )
  {
    if ( (char)pspNetGetBattleModeFlag() == 1 )
      checkeventno = 402;
    else
      checkeventno = 400;
    return a2;
  }
  if ( (unsigned __int8)pspNetGetBattleModeFlag() && ((char)pspNetGetBattleModeFlag() != 2 || pspNetGetErrorCode()) )
  {
LABEL_195:
    request_status(0, 255, 255);
    stoprequest = 1;
    write_eventflag(39, 402);
    v14 = &jumpeventno;
    goto LABEL_196;
  }
  write_eventflag(39, 400);
  request_status(0, 255, 255);
  stoprequest = 1;
  v14 = &jumpeventno;
LABEL_196:
  *v14 = 1;
LABEL_197:
  battle_event_start();
  return 2;
}

