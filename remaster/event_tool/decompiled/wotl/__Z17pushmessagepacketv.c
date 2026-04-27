// __Z17pushmessagepacketv @ 0x5DA00 (68 bytes)
// WotL iOS - debug symbols, no obfuscation

void *__fastcall pushmessagepacket()
{
  void *result; // r0

  if ( !pushflag )
  {
    result = memcpy(&messagepacketrsv, messagepacket, 0x80u);
    pushflag = 1;
  }
  return result;
}

