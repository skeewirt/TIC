// __ZL23comCommandProcs_netmodev @ 0x14AB9C (728 bytes)
// WotL iOS - debug symbols

int __fastcall comCommandProcs_netmode()
{
  unsigned int *OTptrZ; // r0
  int v1; // r0
  int v2; // r5
  int v3; // r4
  unsigned __int16 v4; // r3
  int v5; // r2
  int v6; // r0
  unsigned int v7; // r0
  int v8; // r0

  return_actionstructure();
  if ( !pspNetCheckDuty() )
  {
    standerdExecution();
    OTptrZ = (unsigned int *)ASHURA_getOTptrZ(0);
    menu_call(OTptrZ, padd);
    v1 = searchCurrentAnimation();
    v2 = *(unsigned __int16 *)(v1 + 8);
    v3 = v1;
    if ( v2 > 30 / iOS_GetFrameRate() && !*(_BYTE *)(v3 + 442) )
    {
      iOS_SetFrameRate(2);
      if ( !BattleRoutine(*(unsigned __int8 *)(*(_DWORD *)(v3 + 308) + 428), v3 + 348) )
      {
        if ( *(_DWORD *)(v3 + 348) == 1 )
        {
          *(_BYTE *)(v3 + 352) = *(_BYTE *)(*(_DWORD *)(v3 + 308) + 428);
          setskilldata_to_ACT(v3 + 352);
        }
        *(_BYTE *)(v3 + 442) = 1;
        iOS_SetFrameRate(1);
      }
    }
    v4 = *(_WORD *)(v3 + 8) + 6;
    *(_WORD *)(v3 + 8) = v4;
    if ( v4 > 0x1Eu && *(_BYTE *)(v3 + 442) )
    {
      switch ( *(_DWORD *)(v3 + 348) )
      {
        case 0:
          if ( *(_BYTE *)(v3 + 304) )
            v5 = *(unsigned __int8 *)(searchAnimationByID(*(unsigned __int8 *)(v3 + 305)) + 4);
          else
            v5 = gCurrentAnimation;
          goto LABEL_15;
        case 1:
          switch ( *(_BYTE *)(v3 + 353) )
          {
            case 2:
              set_guard_status(*(unsigned __int8 *)(*(_DWORD *)(v3 + 308) + 428));
              *(_BYTE *)(v3 + 317) |= 2u;
              goto LABEL_19;
            case 3:
              v6 = *(_DWORD *)(v3 + 308);
              *(_BYTE *)(v3 + 317) |= 2u;
              after_equipchange(v6);
              SetUnitParameter(*(unsigned __int8 *)(*(_DWORD *)(v3 + 308) + 428));
LABEL_19:
              requestDamageResult(*(unsigned __int8 *)(v3 + 4));
              goto LABEL_20;
            case 4:
            case 0x18:
LABEL_20:
              set_act_end(*(unsigned __int8 *)(*(_DWORD *)(v3 + 308) + 428));
              goto LABEL_26;
            default:
              *(_WORD *)(v3 + 312) = *(_WORD *)(v3 + 354);
              v7 = getskillrange(v3 + 352);
              *(_DWORD *)(v3 + 376) = v7;
              if ( v7 <= 3 && ((1 << v7) & 0xB) != 0 )
                actionCommandSelectInit();
              else
                actionPrepare2Init();
              goto LABEL_27;
          }
        case 2:
          v8 = *(_DWORD *)(v3 + 308);
          *(_BYTE *)(v3 + 317) |= 3u;
          set_turn_end(*(unsigned __int8 *)(v8 + 428));
LABEL_26:
          afterCommandInit();
          break;
        case 0x19:
          v5 = gCurrentAnimation;
LABEL_15:
          gActiveAnimation = v5;
          moveCommandSelectInit();
          break;
        default:
          break;
      }
    }
LABEL_27:
    get_netdatamode();
  }
  return 0;
}

