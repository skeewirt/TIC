// __ZL18battle_event_startv @ 0x61894 (268 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall battle_event_start()
{
  int result; // r0
  int v1; // r4
  int v2; // r0
  bool v3; // zf

  TRACE_Dummy("battle_event_start\n");
  directioninit();
  fromworldmap = 1;
  if ( read_eventflag(509) )
  {
    recieve_scroll();
    event_init_light();
    linkf = 0;
    cameraoperateflg = 0;
  }
  gBraveMovieFlg = 0;
  result = read_eventflag(39);
  v1 = result;
  if ( result )
  {
    if ( get_netmodeadhoc() == 1 )
    {
      v2 = eventlinkdata[v1] & 0xF300;
      v3 = v2 == 33280;
      if ( v2 != 33280 )
        v3 = v2 == 0x8000;
      if ( v3 || v2 >> 8 == 131 )
        setNetErrorCutFlg();
    }
    linkf = 0;
    cameraoperateflg = 0;
    SetChangePaletteData(2u, 0, 0, 0, 2u);
    return task_create(1, (char *)battle_event_main);
  }
  return result;
}

