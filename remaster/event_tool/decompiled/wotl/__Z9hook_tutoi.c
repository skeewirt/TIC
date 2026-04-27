// __Z9hook_tutoi @ 0xA966C (72 bytes)
// WotL iOS - debug symbols

int __fastcall hook_tuto(int a1)
{
  int result; // r0

  worldmap_restart();
  UnitList(a1 + 1, 0);
  result = worldmap_restart();
  stopworldrequest = 0;
  wcombase = (int)&worldmaptes;
  return result;
}

