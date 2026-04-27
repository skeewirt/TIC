// __Z17getTapedDirectionv @ 0x13E560 (180 bytes)
// WotL iOS - debug symbols

int __fastcall getTapedDirection()
{
  int v0; // r5
  _DWORD *i; // r4
  int v3; // [sp+0h] [bp-10h] BYREF
  int v4; // [sp+4h] [bp-Ch] BYREF

  xpLibGetOffset(&v4, &v3);
  v0 = 0;
  for ( i = &theVecDirection;
        iOS_getTouchNowX() < *i + v4 - 24
     || iOS_getTouchNowX() > *i + v4 + 24
     || iOS_getTouchNowY() < i[1] + v3 - 24
     || iOS_getTouchNowY() > i[1] + v3 + 24;
        i += 4 )
  {
    if ( ++v0 == 4 )
      return -1;
  }
  return v0;
}

