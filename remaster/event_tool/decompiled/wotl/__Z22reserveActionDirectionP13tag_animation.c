// __Z22reserveActionDirectionP13tag_animation @ 0x140360 (28 bytes)
// WotL iOS - debug symbols

int __fastcall reserveActionDirection(int result)
{
  if ( result )
  {
    if ( *(__int16 *)(result + 114) == -1 )
      *(_WORD *)(result + 114) = *(_WORD *)(result + 112);
  }
  return result;
}

