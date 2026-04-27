// __Z28pspNetCheckAutoCommandPlayerv @ 0x1584A4 (68 bytes)
// WotL iOS - debug symbols

int __fastcall pspNetCheckAutoCommandPlayer()
{
  int result; // r0
  int v1; // r3
  int v2; // r3
  bool v3; // zf

  for ( result = gStartAnimation; result; result = *(_DWORD *)result )
  {
    v1 = *(_DWORD *)(result + 308);
    if ( v1 )
    {
      v2 = *(unsigned __int8 *)(v1 + 476);
      v3 = v2 == 10;
      if ( v2 != 10 )
        v3 = v2 == 0;
      if ( !v3 )
        return 1;
    }
  }
  return result;
}

