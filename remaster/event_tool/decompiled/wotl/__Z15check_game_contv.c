// __Z15check_game_contv @ 0x11E788 (348 bytes)
// WotL iOS - debug symbols

int __fastcall check_game_cont()
{
  int v0; // r8
  int v1; // r5
  _BYTE *v2; // r4
  int v3; // r10
  int v4; // r3
  int v5; // r6
  int result; // r0
  int v7; // r5
  char *v8; // r4
  char v9; // r6
  int v10; // r6

  v0 = 0;
  v1 = 0;
  v2 = &bwork;
  v3 = 0;
  do
  {
    if ( (v2[478] & 3) == 3 )
    {
      v4 = (unsigned __int8)v2[421];
      if ( v4 != 255 )
      {
        if ( check_status_data2((char *)&bwork + 486 * v1, 1) + (v4 == 128) )
        {
          v5 = v2[478] & 0x30;
          if ( get_netmodeadhoc() != 1 || v2[98] != 64 )
          {
            if ( v5 )
              ++v3;
            else
              ++v0;
          }
        }
      }
    }
    ++v1;
    v2 += 486;
  }
  while ( v1 != 21 );
  if ( v0 )
    return -1;
  if ( v3 )
    return 0;
  v7 = 0;
  v8 = &byte_1242397;
  do
  {
    if ( (unsigned __int8)*v8 != 255 )
    {
      v9 = v8[477];
      if ( !check_status_data2((char *)&bwork + 486 * v7, 0) )
      {
        v10 = v9 & 0x30;
        if ( get_netmodeadhoc() != 1 || v8[97] != 64 )
        {
          if ( v10 )
            ++v3;
          else
            ++v0;
        }
      }
    }
    ++v7;
    v8 += 486;
  }
  while ( v7 != 21 );
  if ( !v0 )
    return -1;
  result = v3;
  if ( v3 )
    return 1;
  return result;
}

