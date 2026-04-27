// __Z12eventMapJumpii @ 0x15563C (104 bytes)
// WotL iOS - debug symbols, no obfuscation

int *__fastcall eventMapJump(int a1, int a2)
{
  int *result; // r0

  gTheMapNo = a1;
  result = &gStatusMode;
  gStatusModeOld = gStatusMode;
  gStatusMode = 53;
  if ( a2 )
  {
    gMapJumpSpeed = 256 / a2;
    return (int *)(256 / a2);
  }
  else
  {
    gMapJumpSpeed = 256;
  }
  return result;
}

