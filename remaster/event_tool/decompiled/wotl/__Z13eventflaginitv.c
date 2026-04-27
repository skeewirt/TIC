// __Z13eventflaginitv @ 0xA59EC (212 bytes)
// WotL iOS - debug symbols, no obfuscation

void *__fastcall eventflaginit()
{
  int i; // r3
  void *result; // r0

  eventwork[0] = 0;
  for ( i = 1; i != 256; ++i )
    eventwork[i] = 0;
  dword_120159C = 3;
  dword_12015A0 = 21;
  result = memcpy(&optrec, &optrecorg, 4u);
  keyrept1_delay = 14;
  keyrept1_time = 4;
  keyreptlr_time = 10;
  scroll2_delay = 32;
  scroll1_speed = 4;
  scroll2_speed = 4;
  scroll_visualsw = 1;
  itemtransfer = 0;
  return result;
}

