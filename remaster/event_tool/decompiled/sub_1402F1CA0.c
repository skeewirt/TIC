// sub_1402F1CA0 @ 0x1402F1CA0 (70 bytes)
// Decompiled by IDA Pro - Event System Phase 0 (batch 2)

_BOOL8 __fastcall check_turn_frozen(_BYTE *a1)
{
  if ( a1[1] == 0xFF )
    return 1;
  if ( *(_DWORD *)(qword_143CD37B0 + 13436) )
  {
    if ( (a1[97] & 0x40) != 0 || (a1[5] & 4) != 0 && (a1[97] & 0x20) != 0 )
      return 1;
  }
  else if ( (a1[97] & 0x60) != 0 )
  {
    return 1;
  }
  return (a1[98] & 0x81) != 0 || (a1[436] & 0x40) != 0;
}

