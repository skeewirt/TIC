// __ZL13wait_clutloadv @ 0x5C810 (36 bytes)
// WotL iOS - debug symbols

int __fastcall wait_clutload()
{
  int result; // r0

  while ( clutloadf )
    result = asmTaskEntry();
  return result;
}

