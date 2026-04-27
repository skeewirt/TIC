// __Z23setAnimationDirection16jj @ 0x156E5C (160 bytes)
// WotL iOS - debug symbols

int __fastcall setAnimationDirection16(unsigned int a1, unsigned int a2)
{
  int v4; // r0
  int v5; // r5
  unsigned int v7; // r4

  v4 = searchAnimationByID(a1);
  v5 = v4;
  if ( !v4 )
    return -1;
  *(_WORD *)(v4 + 112) = (_WORD)a2 << 8;
  v7 = *(unsigned __int16 *)(v4 + 484) >> 1;
  if ( v7 <= 2 )
  {
    v7 = 2;
    TRACE_Dummy("STAND_ANIMATION:%d\n", a1);
  }
  if ( a1 == 4 )
    TRACE_Dummy("        DIREC:%2d:%4d:%4x:%d \n", 4, a2, *(__int16 *)(v5 + 112), v7);
  forceChangeAnimation(v7, *(__int16 *)(v5 + 112), v5);
  return a1;
}

