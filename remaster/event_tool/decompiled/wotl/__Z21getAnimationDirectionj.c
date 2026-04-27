// __Z21getAnimationDirectionj @ 0x155EE4 (72 bytes)
// WotL iOS - debug symbols

unsigned int __fastcall getAnimationDirection(unsigned __int16 a1)
{
  int v1; // r0
  int v3; // r0
  int v4; // kr00_4

  v1 = searchAnimationByID(a1);
  if ( !v1 )
    return -1;
  v4 = *(__int16 *)(v1 + 112);
  v3 = v4 + (v4 < 0 ? 0x3FF : 0);
  return ((((unsigned int)(v3 >> 31) >> 30) + (unsigned __int8)(v4 / 1024)) & 3) - ((unsigned int)(v3 >> 31) >> 30);
}

