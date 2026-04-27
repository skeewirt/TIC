// __Z17eSetSortConditioniPs @ 0xD18C4 (44 bytes)
// WotL iOS - debug symbols

int __fastcall eSetSortCondition(int a1, __int16 *a2)
{
  int v2; // r2
  int result; // r0
  int v4; // r3

  v2 = 0;
  result = sort_type[a1];
  while ( 1 )
  {
    v4 = LOBYTE(a2[v2]);
    *(_BYTE *)(v2 + result) = v4;
    if ( v4 == 255 )
      break;
    ++v2;
  }
  return result;
}

