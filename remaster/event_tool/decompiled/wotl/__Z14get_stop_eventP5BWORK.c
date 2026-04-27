// __Z14get_stop_eventP5BWORK @ 0x11D5B4 (344 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall get_stop_event(unsigned __int8 *a1)
{
  int v2; // r6
  unsigned __int8 *v3; // r5
  int v4; // r0
  int v5; // r5
  char *v6; // r0
  char v7; // r0

  v2 = check_coord2(a1[79], a1[80], a1[81] >> 7, 0x41u) >= 0;
  if ( (a1[420] & 0x80) != 0 )
  {
    v4 = 486 * (a1[420] & 0x1F);
    v3 = (unsigned __int8 *)&bwork + v4;
    target_bwp = (int)&bwork + v4;
    target_arp = (int)&bwork + v4 + 430;
    init_target_result();
    *(_BYTE *)(target_arp + 34) = byte_12463B9;
    *(_BYTE *)(target_arp + 35) = byte_12463BA;
    *(_BYTE *)(target_arp + 36) = byte_12463BB;
    *(_BYTE *)(target_arp + 37) = byte_12463BC;
    *(_BYTE *)(target_arp + 38) = byte_12463BD;
    if ( change_status_adjust(0) )
    {
      v2 |= 0x400u;
      *(_BYTE *)(target_arp + 39) = 8;
      set_status_all(v3[428], 0);
    }
  }
  else
  {
    v3 = a1;
  }
  v5 = v3[158] & 1;
  v6 = (char *)check_trap(a1[79], a1[80], a1[81] >> 7);
  if ( v5 )
  {
    v7 = *v6;
    if ( (v7 & 1) != 0 )
    {
      v2 |= 4u;
      goto LABEL_11;
    }
  }
  else
  {
    v7 = *v6;
  }
  if ( (v7 & 2) != 0 )
    v2 |= 8u;
LABEL_11:
  if ( check_charge(a1, 0) )
    v2 |= 0x10u;
  return v2 | check_move_ability(a1);
}

