// __Z14checkScrollingv @ 0x15605C (184 bytes)
// WotL iOS - debug symbols

int __fastcall checkScrolling()
{
  bool v0; // zf
  int result; // r0

  if ( !iOSIsCurMode() )
  {
    v0 = gMoveVector == 0;
    if ( !gMoveVector )
      v0 = dword_12B1728 == 0;
    if ( v0 && !dword_12B172C && !turning && !fukaning )
      goto LABEL_12;
    return 1;
  }
  if ( turning || fukaning )
    return 1;
LABEL_12:
  result = zooming;
  if ( zooming )
    return 1;
  return result;
}

