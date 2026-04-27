// __Z23wasmSerchMessagePointerPci @ 0x2F67C (36 bytes)
// WotL iOS - debug symbols

_BYTE *__fastcall wasmSerchMessagePointer(_BYTE *result, int a2)
{
  int v2; // r2

  v2 = 0;
  while ( a2 != v2 )
  {
    if ( (*result & 0xFE) == 0xFE )
      ++v2;
    ++result;
  }
  return result;
}

