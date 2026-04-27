// __Z11wait_anmendi @ 0x5C7EC (36 bytes)
// WotL iOS - debug symbols

int __fastcall wait_anmend(unsigned int a1)
{
  int result; // r0

  while ( 1 )
  {
    result = checkAnimation(a1);
    if ( result )
      break;
    asmTaskEntry();
  }
  return result;
}

