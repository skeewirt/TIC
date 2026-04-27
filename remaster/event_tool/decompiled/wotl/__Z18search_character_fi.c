// __Z18search_character_fi @ 0x11CA44 (312 bytes)
// WotL iOS - debug symbols

int __fastcall search_character_f(unsigned int a1)
{
  int result; // r0
  int v2; // r5
  int v3; // r2
  char *v4; // r2
  char *v5; // r2
  int v6; // r3
  bool v7; // zf
  int v8; // r3
  int i; // r4
  unsigned __int8 *unitwork_add; // r0

  if ( a1 > 0x7F && a1 - 162 > 1 )
    return -1;
  v2 = (unsigned __int8)a1;
  result = 0;
  v3 = 0;
  do
  {
    if ( *((unsigned __int8 *)&bwork + v3 + 1) != 255 && *((unsigned __int8 *)&bwork + v3) == v2 )
    {
      v4 = (char *)&bwork + 486 * result;
      if ( (v4[97] & 0x40) != 0 || (v4[98] & 1) != 0 )
        return -3;
      return result;
    }
    ++result;
    v3 += 486;
  }
  while ( result != 21 );
  v5 = &byte_124253B;
  do
  {
    v6 = (unsigned __int8)*(v5 - 420);
    v7 = v6 == 255;
    if ( v6 == 255 )
      v7 = (unsigned __int8)*(v5 - 421) == v2;
    if ( v7 )
    {
      v8 = (unsigned __int8)*v5;
      if ( v8 != 255 )
      {
        if ( !*v5 )
          return -2;
        if ( v8 == 128 )
          return -3;
      }
    }
    v5 += 486;
  }
  while ( v5 != (char *)&unk_1244D19 );
  for ( i = 0; i != 28; ++i )
  {
    unitwork_add = (unsigned __int8 *)get_unitwork_add(i);
    if ( unitwork_add[1] != 255 && *unitwork_add == v2 )
      return -4;
  }
  return -5;
}

