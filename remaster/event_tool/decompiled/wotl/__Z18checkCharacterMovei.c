// __Z18checkCharacterMovei @ 0x156650 (56 bytes)
// WotL iOS - debug symbols

int __fastcall checkCharacterMove(unsigned __int16 a1)
{
  int v1; // r0
  int v2; // r4
  int result; // r0

  v1 = searchAnimationByID(a1);
  v2 = v1;
  if ( v1 )
  {
    result = *(unsigned __int8 *)(v1 + 156);
    if ( *(_BYTE *)(v2 + 156) )
      return 1;
  }
  else
  {
    warningHandler(12);
    return 0;
  }
  return result;
}

