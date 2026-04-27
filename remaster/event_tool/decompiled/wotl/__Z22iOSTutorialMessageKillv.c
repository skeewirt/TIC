// __Z22iOSTutorialMessageKillv @ 0x1036A8 (100 bytes)
// WotL iOS - debug symbols

bool __fastcall iOSTutorialMessageKill()
{
  if ( !iOSTutoCheck() )
    return 0;
  if ( com_typeBackUp == 18 )
    return 1;
  return com_typeBackUp == 22 && Wtask_status(16) && tutorialstatusget(16);
}

