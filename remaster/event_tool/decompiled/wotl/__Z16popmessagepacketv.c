// __Z16popmessagepacketv @ 0x5D9C4 (48 bytes)
// WotL iOS - debug symbols, no obfuscation

void *__fastcall popmessagepacket()
{
  void *result; // r0

  result = memcpy(&messagepacket, &messagepacketrsv, 0x80u);
  pushflag = 0;
  return result;
}

