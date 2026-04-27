// __Z23getAnimationDirection16j @ 0x155EA0 (68 bytes)
// WotL iOS - debug symbols

unsigned int __fastcall getAnimationDirection16(unsigned __int16 a1)
{
  int v1; // r0
  int v3; // r0

  v1 = searchAnimationByID(a1);
  if ( !v1 )
    return -1;
  v3 = *(__int16 *)(v1 + 112);
  return ((((unsigned int)((v3 + (unsigned __int8)-(v3 < 0)) >> 31) >> 28)
         + ((unsigned __int16)(v3 + (unsigned __int8)-(v3 < 0)) >> 8))
        & 0xF)
       - ((unsigned int)((v3 + (unsigned __int8)-(v3 < 0)) >> 31) >> 28);
}

