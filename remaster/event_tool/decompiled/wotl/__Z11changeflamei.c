// __Z11changeflamei @ 0x5F614 (28 bytes)
// WotL iOS - debug symbols

int __fastcall changeflame(int a1)
{
  current_flame = iOS_GetFrameRate();
  return changeFlameRate(current_flame);
}

