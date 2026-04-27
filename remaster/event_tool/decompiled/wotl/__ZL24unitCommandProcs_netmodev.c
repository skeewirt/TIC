// __ZL24unitCommandProcs_netmodev @ 0x14C5DC (1160 bytes)
// WotL iOS - debug symbols

int __fastcall unitCommandProcs_netmode()
{
  int result; // r0
  unsigned int *OTptrZ; // r0
  int *v2; // r4
  int v3; // r3
  int v4; // r5
  int v5; // r2
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int v9; // r3
  int v10; // r1
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r1
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r3
  int v20; // r1
  unsigned int v21; // r0
  int active; // r0
  int v23; // r0

  return_actionstructure();
  searchCurrentAnimation();
  result = get_netmodeadhoc();
  if ( result != 1 )
  {
    if ( !recieve_statusinfo() )
      freeCursorInit();
    if ( (trg & 0x100) != 0 )
    {
      scrolling = 0;
      gStatusMode = 6;
      gHelpMode = 1;
      request_help();
    }
    standerdExecution();
    OTptrZ = (unsigned int *)ASHURA_getOTptrZ(0);
    menu_call(OTptrZ, padd);
    v2 = (int *)return_actionstructure();
    result = searchActiveAnimation();
    v3 = *v2;
    v4 = result;
    switch ( *v2 )
    {
      case 0:
        if ( *(_BYTE *)(result + 304) )
          v5 = *(unsigned __int8 *)(searchAnimationByID(*(unsigned __int8 *)(result + 305)) + 4);
        else
          v5 = gCurrentAnimation;
        gActiveAnimation = v5;
        goto LABEL_12;
      case 1:
        gTurnOrder = 0;
        switch ( *((_BYTE *)v2 + 5) )
        {
          case 2:
            v6 = v2[1];
            v7 = v2[2];
            v8 = v2[3];
            *(_DWORD *)(result + 348) = *v2;
            *(_DWORD *)(result + 352) = v6;
            *(_DWORD *)(result + 356) = v7;
            *(_DWORD *)(result + 360) = v8;
            v9 = *(_DWORD *)(result + 308);
            v10 = v2[5];
            *(_DWORD *)(result + 364) = v2[4];
            *(_DWORD *)(result + 368) = v10;
            set_guard_status(*(unsigned __int8 *)(v9 + 428));
            *(_BYTE *)(v4 + 317) |= 2u;
            goto LABEL_16;
          case 3:
            v11 = v2[1];
            v12 = v2[2];
            v13 = v2[3];
            *(_DWORD *)(result + 348) = *v2;
            *(_DWORD *)(result + 352) = v11;
            *(_DWORD *)(result + 356) = v12;
            *(_DWORD *)(result + 360) = v13;
            v14 = v2[5];
            LOBYTE(v13) = *(_BYTE *)(result + 317);
            *(_DWORD *)(result + 364) = v2[4];
            *(_DWORD *)(result + 368) = v14;
            v15 = *(_DWORD *)(result + 308);
            *(_BYTE *)(v4 + 317) = v13 | 2;
            after_equipchange(v15);
            SetUnitParameter(*(unsigned __int8 *)(*(_DWORD *)(v4 + 308) + 428));
LABEL_16:
            requestDamageResult(*(unsigned __int8 *)(v4 + 4));
            set_act_end(*(unsigned __int8 *)(*(_DWORD *)(v4 + 308) + 428));
            goto LABEL_17;
          case 4:
          case 0x18:
LABEL_17:
            result = afterCommandInit();
            break;
          default:
            v16 = v2[1];
            v17 = v2[2];
            v18 = v2[3];
            *(_DWORD *)(result + 348) = *v2;
            *(_DWORD *)(result + 352) = v16;
            *(_DWORD *)(result + 356) = v17;
            *(_DWORD *)(result + 360) = v18;
            v19 = *(_DWORD *)(result + 308);
            v20 = v2[5];
            *(_DWORD *)(result + 364) = v2[4];
            *(_DWORD *)(result + 368) = v20;
            *(_BYTE *)(result + 352) = *(_BYTE *)(v19 + 428);
            *(_BYTE *)(result + 362) = 5;
            setskilldata_to_ACT(result + 352);
            *(_WORD *)(v4 + 312) = *(_WORD *)(v4 + 354);
            v21 = getskillrange(v4 + 352);
            *(_DWORD *)(v4 + 376) = v21;
            if ( v21 <= 3 && ((1 << v21) & 0xB) != 0 )
              result = actionCommandSelectInit();
            else
              result = actionPrepare2Init();
            break;
        }
        return result;
      case 2:
        return directionSelectInit();
      case 7:
        gInterventionFlag = 0;
        gInterventionMode = 0;
        if ( get_netmodeadhoc() == 1 )
          pspNetSetCharacterWaitFlag(2);
        return newTurn();
      case 12:
      case 14:
        *(_BYTE *)(result + 444) = v3;
        scrolling = 0;
        gStatusMode = 31;
        active = searchActiveAnimation();
        result = ask_event(1, 0, *(unsigned __int8 *)(*(_DWORD *)(active + 308) + 428), 0, 1);
        goto LABEL_25;
      case 13:
      case 15:
        *(_BYTE *)(result + 444) = v3;
        scrolling = 0;
        gStatusMode = 35;
        request_status(1, 255, 255);
        v23 = searchActiveAnimation();
        result = ask_event(1, 0, *(unsigned __int8 *)(*(_DWORD *)(v23 + 308) + 428), 0, 1);
        gActionCode = 0;
LABEL_25:
        gCursorDisplay = 1;
        break;
      case 16:
      case 17:
        result = preCommandInit();
        break;
      case 18:
        if ( get_netmodeadhoc() == 1 )
        {
          gInterventionFlag = 0;
          gInterventionMode = 0;
        }
        result = getDutyInputData(v4);
        break;
      case 25:
        gActiveAnimation = gCurrentAnimation;
LABEL_12:
        gTurnOrder = 0;
        result = moveCommandSelectInit();
        break;
      default:
        return result;
    }
  }
  return result;
}

