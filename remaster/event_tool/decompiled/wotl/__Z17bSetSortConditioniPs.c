// __Z17bSetSortConditioniPs @ 0xC024C (40 bytes)
// WotL iOS - debug symbols

char *__fastcall bSetSortCondition(int a1, __int16 *a2)
{
  int v2; // r2
  char *result; // r0
  int v4; // r3

  v2 = 0;
  result = battle_chr_sort;
  while ( 1 )
  {
    v4 = LOBYTE(a2[v2]);
    battle_chr_sort[v2] = v4;
    if ( v4 == 255 )
      break;
    ++v2;
  }
  return result;
}

