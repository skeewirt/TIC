// __Z17check_unit_activeP5BWORK @ 0x11E6C0 (112 bytes)
// WotL iOS - debug symbols

int __fastcall check_unit_active(unsigned __int8 *a1)
{
  int result; // r0

  if ( a1[1] == 255 || check_status_data2(a1, 3) || (a1[420] & 0x40) != 0 )
    return 1;
  if ( (a1[97] & 0x20) != 0 )
    return 6;
  result = a1[101] & 0x10;
  if ( (a1[101] & 0x10) != 0 )
    result = 10;
  if ( (a1[100] & 8) != 0 )
    result |= 0x10u;
  if ( (a1[100] & 4) != 0 )
    return result | 0x20;
  return result;
}

