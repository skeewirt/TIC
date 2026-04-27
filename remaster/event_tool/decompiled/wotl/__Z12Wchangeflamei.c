// __Z12Wchangeflamei @ 0x46EA0 (24 bytes)
// WotL iOS - debug symbols

int __fastcall Wchangeflame(int a1)
{
  int result; // r0

  result = iOS_GetFrameRate();
  wcurrent_flame = result;
  return result;
}

