// __Z16GetSortConditioniPs @ 0xF19CC (64 bytes)
// WotL iOS - debug symbols

int __fastcall GetSortCondition(int a1, __int16 *a2)
{
  int v2; // r12
  char *v3; // lr
  int v4; // r2
  int result; // r0

  v2 = 0;
  v3 = sort_type[a1];
  while ( 1 )
  {
    v4 = (unsigned __int8)v3[v2];
    result = 2 * v2;
    a2[v2] = (char)v4;
    if ( v4 == 255 )
      break;
    ++v2;
  }
  return result;
}

