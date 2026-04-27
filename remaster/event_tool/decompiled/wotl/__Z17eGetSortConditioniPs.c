// __Z17eGetSortConditioniPs @ 0xD1880 (64 bytes)
// WotL iOS - debug symbols

int __fastcall eGetSortCondition(int a1, __int16 *a2)
{
  int v2; // r12
  int v3; // lr
  int v4; // r2
  int result; // r0

  v2 = 0;
  v3 = sort_type[a1];
  while ( 1 )
  {
    v4 = *(unsigned __int8 *)(v2 + v3);
    result = 2 * v2;
    a2[v2] = (char)v4;
    if ( v4 == 255 )
      break;
    ++v2;
  }
  return result;
}

