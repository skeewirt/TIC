// __Z19changeCharacterClutiiisss @ 0x159FB8 (144 bytes)
// WotL iOS - debug symbols

int __fastcall changeCharacterClut(int a1, int a2, int a3, __int16 a4, __int16 a5, __int16 a6)
{
  int i; // r4
  int v10; // r2
  int result; // r0

  if ( a3 <= 15 )
    return changeCharacterClutSub(a1, a2, a3, a4, a5, a6);
  changeCharacterClutSub(a1, a2, 0, a4, a5, a6);
  for ( i = 1; i != 16; ++i )
  {
    v10 = i;
    result = changeCharacterClutSub(a1, a2, v10, a4, a5, a6);
  }
  return result;
}

