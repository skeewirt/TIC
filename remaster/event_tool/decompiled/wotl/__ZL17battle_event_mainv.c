// __ZL17battle_event_mainv @ 0x6BA2C (88 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn battle_event_main()
{
  reset_g_NetIcon_DrawFlg();
  seeknextevent();
  if ( !iOSTutoCheck() && iOS_getV2Icon(93) == 1 )
  {
    iOS_setV2Icon(2, 2);
    iOS_setV2Icon(3, 2);
    iOS_setV2Icon(6, 2);
  }
  event_maincommon();
}

