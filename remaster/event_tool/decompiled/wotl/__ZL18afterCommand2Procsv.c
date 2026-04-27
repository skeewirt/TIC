// __ZL18afterCommand2Procsv @ 0x14C440 (388 bytes)
// WotL iOS - debug symbols

int *__fastcall afterCommand2Procs()
{
  unsigned int *OTptrZ; // r0
  int *result; // r0
  int *v2; // r4
  int v3; // r3
  int v4; // r0

  standerdExecution();
  OTptrZ = (unsigned int *)ASHURA_getOTptrZ(0);
  menu_call(OTptrZ, padd);
  result = (int *)searchCurrentAnimation();
  v2 = result;
  if ( dword_12B1728 | gMoveVector | dword_12B172C )
    return result;
  result = &turning;
  if ( turning )
    return result;
  if ( gBEventMode != 512 )
  {
    if ( check_turn_end(*(unsigned __int8 *)(v2[77] + 428)) != 1 )
      return (int *)preCommandInit();
    memcpy(v2 + 88, (const void *)(v2[77] + 400), 0x14u);
    v3 = v2[96];
    *((_WORD *)v2 + 156) = *(_WORD *)(v2[77] + 402);
    if ( v3 != 3 )
      return (int *)directionSelectInit();
    v4 = *((unsigned __int8 *)v2 + 4);
    v2[96] = 0;
    inactivateAnimation(v4);
    return (int *)newTurn();
  }
  result = (int *)ask_event(8, 2, *(unsigned __int8 *)(v2[77] + 428), turning, 1);
  if ( result == (int *)2 )
  {
    if ( geteventcategory() )
    {
      gStatusModeOld = gStatusMode;
      ask_event(8, 0, *(unsigned __int8 *)(v2[77] + 428), 0, 1);
      iOS_setV2Icon(93, 0);
      return (int *)eventInit(0);
    }
    return (int *)newTurn();
  }
  if ( result != (int *)3 )
    return (int *)newTurn();
  return result;
}

