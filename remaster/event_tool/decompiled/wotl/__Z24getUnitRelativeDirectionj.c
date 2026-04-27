// __Z24getUnitRelativeDirectionj @ 0x155F88 (56 bytes)
// WotL iOS - debug symbols

int __fastcall getUnitRelativeDirection(unsigned __int16 a1)
{
  int v1; // r0
  bool v2; // zf
  int result; // r0

  v1 = searchAnimationByBattleID(a1);
  v2 = v1 == 0;
  if ( v1 )
    result = *(__int16 *)(v1 + 108);
  else
    result = -1;
  if ( !v2 )
    return result % 4;
  return result;
}

