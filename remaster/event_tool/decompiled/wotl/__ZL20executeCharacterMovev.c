// __ZL20executeCharacterMovev @ 0x14E5C8 (60 bytes)
// WotL iOS - debug symbols

int __fastcall executeCharacterMove()
{
  int i; // r4
  int result; // r0

  for ( i = 0; i != 16; ++i )
  {
    result = searchAnimationByID(i);
    if ( result )
    {
      if ( *(_BYTE *)(result + 156) )
        result = executeMoveProcs();
    }
  }
  return result;
}

