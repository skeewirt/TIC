// __ZL17check_commandmaski @ 0x59D70 (56 bytes)
// WotL iOS - debug symbols

int __fastcall check_commandmask(int a1)
{
  int i; // r2
  int v2; // r3

  for ( i = 0; ; ++i )
  {
    v2 = command_mask[i];
    if ( v2 == 255 )
      break;
    if ( v2 == a1 )
      return 1;
  }
  return 0;
}

