// __Z9ask_eventiiiP7SVECTORi @ 0x626FC (196 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall ask_event(int a1, int a2, int a3, int a4, int a5)
{
  bool v9; // zf
  int v10; // r0
  int v11; // r3
  int AnimationAction; // r0

  TRACE_Dummy("ask_event info:%d phaseno:%d\n", a2, a1);
  v9 = a1 == 8;
  if ( a1 != 8 )
    v9 = a1 == 6;
  v10 = !v9;
  if ( v9 )
  {
    v11 = v10;
  }
  else
  {
    AnimationAction = getAnimationAction(a3);
    v11 = AnimationAction;
    if ( a1 == 5 )
      return disp_plateorspell(AnimationAction, a3, a5, AnimationAction);
    if ( a1 == 7 )
      return ask_eventmain(7, 0, a3, 0, 0, AnimationAction);
  }
  return ask_eventmain(a1, a2, a3, a4, a5, v11);
}

