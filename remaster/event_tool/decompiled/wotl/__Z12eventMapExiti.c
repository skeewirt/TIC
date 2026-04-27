// __Z12eventMapExiti @ 0x1562D0 (108 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall eventMapExit(int a1)
{
  int result; // r0

  result = iOS_SetFrameRate(2);
  gStatusMode = 59;
  if ( a1 )
  {
    result = 256 / a1;
    gMapJumpSpeed = 256 / a1;
  }
  else
  {
    gMapJumpSpeed = 256;
  }
  gMapLoopFlag = 1;
  return result;
}

