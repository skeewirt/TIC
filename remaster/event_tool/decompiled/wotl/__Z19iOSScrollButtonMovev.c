// __Z19iOSScrollButtonMovev @ 0x1D8B14 (164 bytes)
// WotL iOS - debug symbols

void __fastcall iOSScrollButtonMove()
{
  unsigned __int8 *v0; // r0

  if ( sTchScrollButtonDTap )
  {
    sTchScrollButtonDTap = 0;
    if ( gStatusMode_old == gStatusMode )
    {
      if ( iOSgetCursorVisible() )
      {
        v0 = (unsigned __int8 *)searchCurrentAnimation();
        if ( v0 )
        {
          iOSsetCursorByTouch(v0[124], v0[126], v0[125], 0, 1);
          if ( !iOSScrollButtonAreaCheck() )
          {
            gStatusModeReturn = gStatusMode;
            gStatusMode = 74;
          }
        }
      }
    }
  }
}

