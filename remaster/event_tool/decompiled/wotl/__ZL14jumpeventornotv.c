// __ZL14jumpeventornotv @ 0x60E9C (56 bytes)
// WotL iOS - debug symbols

int __fastcall jumpeventornot()
{
  int result; // r0

  result = jumpeventno;
  if ( jumpeventno )
    return (unsigned __int16)eventlinkdata[read_eventflag(39)];
  return result;
}

