// __ZL19directionSelectInitv @ 0x14C29C (384 bytes)
// WotL iOS - debug symbols

int __fastcall directionSelectInit()
{
  int v0; // r5
  int v1; // r4
  int result; // r0
  int main_player; // r0
  int v4; // r2

  scrolling = 0;
  v0 = searchCurrentAnimation();
  v1 = ask_event(8, 2, *(unsigned __int8 *)(*(_DWORD *)(v0 + 308) + 428), 0, 1);
  result = TRACE_Dummy("ask_event result :%d\n", v1);
  if ( v1 == 2 )
  {
    if ( geteventcategory() )
    {
      gStatusModeOld = gStatusMode;
      ask_event(8, 0, *(unsigned __int8 *)(*(_DWORD *)(v0 + 308) + 428), 0, 1);
      TRACE_Dummy("eventInit\n");
      iOS_setV2Icon(93, 0);
      return eventInit(0);
    }
  }
  else if ( v1 == 3 )
  {
    return result;
  }
  if ( (check_unit_active(*(unsigned __int8 **)(v0 + 308)) & 0xF) != 0 )
  {
    newTurn();
  }
  else
  {
    main_player = get_main_player();
    set_nettimer_flag(main_player, 1);
    gStatusMode = 20;
    TRACE_Dummy("directionSelectInit B gStatusMode= DirectionSelectMode\n");
    requestFreeCursorStatus();
    if ( !pspNetGetErrorCode() )
      ask_event(3, 0, *(unsigned __int8 *)(*(_DWORD *)(v0 + 308) + 428), 0, *(_BYTE *)(v0 + 318) & 8);
  }
  result = *(unsigned __int8 *)(v0 + 318);
  v4 = result & 8;
  if ( (result & 8) != 0 )
    v4 = 1;
  gCursorDisplay = v4;
  return result;
}

