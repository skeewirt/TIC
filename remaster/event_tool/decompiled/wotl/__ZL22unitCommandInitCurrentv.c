// __ZL22unitCommandInitCurrentv @ 0x1446E8 (128 bytes)
// WotL iOS - debug symbols

void __fastcall unitCommandInitCurrent()
{
  int v0; // r4
  int v1; // r3
  int comwindow_data; // r0

  scrolling = 0;
  v0 = searchCurrentAnimation();
  gActiveAnimation = *(unsigned __int8 *)(v0 + 4);
  setActivePanelFromAnimation(v0);
  gStatusMode = 4;
  iOS_setV2Icon(21, 1);
  v1 = *(_DWORD *)(v0 + 308);
  if ( v1 )
  {
    request_status(3, *(unsigned __int8 *)(v1 + 428), 0);
    v1 = *(_DWORD *)(v0 + 308);
  }
  comwindow_data = get_comwindow_data(*(unsigned __int8 *)(v1 + 428));
  request_command(comwindow_data);
}

