// __Z14eventMapFadeIni @ 0x1567BC (116 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall eventMapFadeIn(int a1)
{
  int result; // r0

  result = TRACE_Dummy("eventMapFadeIn speed:%d\n", a1);
  gStatusModeOld = gStatusMode;
  gStatusMode = 58;
  if ( a1 )
  {
    gMapJumpSpeed = 256 / a1;
    return 256 / a1;
  }
  else
  {
    gMapJumpSpeed = 256;
  }
  return result;
}

