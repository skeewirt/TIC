// __Z17bGetSortConditioniPs @ 0xC020C (60 bytes)
// WotL iOS - debug symbols

int __fastcall bGetSortCondition(int a1, __int16 *a2)
{
  int i; // r12
  int v3; // r2
  int result; // r0

  for ( i = 0; ; ++i )
  {
    v3 = (unsigned __int8)battle_chr_sort[i];
    result = 2 * i;
    a2[i] = (char)v3;
    if ( v3 == 255 )
      break;
  }
  return result;
}

