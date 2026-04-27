// __Z17set_direction_subP13tag_animationi @ 0x140C20 (60 bytes)
// WotL iOS - debug symbols

int __fastcall set_direction_sub(int a1, int a2)
{
  int result; // r0

  result = ((int (*)(void))setAnimationDirection)();
  if ( *(_BYTE *)(a1 + 304) )
  {
    result = searchAnimationByID(*(unsigned __int8 *)(a1 + 305));
    if ( result )
      return setAnimationDirection(result, a2);
  }
  return result;
}

