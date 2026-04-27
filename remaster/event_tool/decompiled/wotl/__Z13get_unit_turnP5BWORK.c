// __Z13get_unit_turnP5BWORK @ 0x11E568 (112 bytes)
// WotL iOS - debug symbols

int __fastcall get_unit_turn(int a1)
{
  int result; // r0
  int v3; // r4
  _DWORD v4[40]; // [sp+0h] [bp-A8h] BYREF

  if ( *(unsigned __int8 *)(a1 + 1) == 255 )
    return -1;
  if ( check_turn_frozen(a1) )
    return -3;
  v3 = *(unsigned __int8 *)(a1 + 428);
  set_event_table((int)v4, 1);
  result = 0;
  while ( (v4[result] & 0x1F) != v3 )
  {
    if ( ++result == 40 )
      return -2;
  }
  return result;
}

