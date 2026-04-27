// __ZL14preCommandInitv @ 0x145A44 (120 bytes)
// WotL iOS - debug symbols

int __fastcall preCommandInit()
{
  int active; // r5
  int v1; // r0
  int v2; // r4
  int result; // r0

  scrolling = 0;
  active = searchActiveAnimation();
  v1 = searchCurrentAnimation();
  gCursorDisplay = 1;
  v2 = v1;
  getDutyInputData(active);
  result = checkEventStart(v2);
  if ( !result )
  {
    gStatusMode = 3;
    gActionCode = 0;
    return startAutoTurn(active);
  }
  return result;
}

