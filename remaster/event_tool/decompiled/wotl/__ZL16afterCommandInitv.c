// __ZL16afterCommandInitv @ 0x144F8C (92 bytes)
// WotL iOS - debug symbols

int __fastcall afterCommandInit()
{
  int v0; // r0

  iOS_SetFrameRate(1);
  gStatusMode = 37;
  gActionCode = 0;
  v0 = searchCurrentAnimation();
  setActivePanelFromAnimation(v0);
  return ask_event(6, 0, 0, 0, 0);
}

