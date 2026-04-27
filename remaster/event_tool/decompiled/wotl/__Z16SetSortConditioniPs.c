// __Z16SetSortConditioniPs @ 0xF1A10 (44 bytes)
// WotL iOS - debug symbols

char *__fastcall SetSortCondition(int a1, __int16 *a2)
{
  int v2; // r2
  char *result; // r0
  int v4; // r3

  v2 = 0;
  result = sort_type[a1];
  while ( 1 )
  {
    v4 = LOBYTE(a2[v2]);
    result[v2] = v4;
    if ( v4 == 255 )
      break;
    ++v2;
  }
  return result;
}

