// __Z18Wpushmessagepacketv @ 0x46D7C (68 bytes)
// WotL iOS - debug symbols, no obfuscation

void *__fastcall Wpushmessagepacket()
{
  void *result; // r0

  if ( !pushflag )
  {
    result = memcpy(&messagepacketrsv, wmessagepacket, 0x80u);
    pushflag = 1;
  }
  return result;
}

