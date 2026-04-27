// __ZL20unitCommandInitOtherv @ 0x14461C (180 bytes)
// WotL iOS - debug symbols

void __fastcall unitCommandInitOther()
{
  int v0; // r4
  int comwindow_data; // r0

  v0 = searchAnimationByPositionBattle(gActivePanelX, gActivePanelZ, gActivePanelY);
  if ( v0 )
  {
    scrolling = 0;
    gStatusMode = 4;
    iOS_setV2Icon(21, 1);
    request_status(3, *(unsigned __int8 *)(*(_DWORD *)(v0 + 308) + 428), 0);
    comwindow_data = get_comwindow_data(*(unsigned __int8 *)(*(_DWORD *)(v0 + 308) + 428));
    if ( gInterventionMode )
    {
      if ( comwindow_data == 15 )
      {
        comwindow_data = 17;
      }
      else if ( comwindow_data == 16 )
      {
        comwindow_data = 18;
      }
    }
    request_command(comwindow_data);
  }
}

