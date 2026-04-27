// __ZL30getTargetCharacterVisibleTransiP6VECTOR @ 0x160C74 (44 bytes)
// WotL iOS - debug symbols

__int16 *__fastcall getTargetCharacterVisibleTrans(unsigned int a1, _DWORD *a2)
{
  __int16 *result; // r0

  result = (__int16 *)getAnimationPosition(a1);
  *a2 = *result;
  a2[1] = result[1];
  a2[2] = result[2];
  return result;
}

