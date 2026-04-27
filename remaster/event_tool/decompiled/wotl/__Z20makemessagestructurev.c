// __Z20makemessagestructurev @ 0x59FA4 (92 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall makemessagestructure()
{
  int v0; // r2
  char v1; // r12
  int v2; // r3
  int result; // r0

  v0 = 0;
  v1 = tutorialstartf;
  if ( tutorialstartf )
    v1 = 1;
  do
  {
    if ( v0 )
      v2 = 0;
    else
      v2 = v1 & 1;
    if ( !v2 )
    {
      result = messagebuffer[v0];
      messagepacket[v0] = (int)&messagebuffer[32] + result;
    }
    ++v0;
  }
  while ( v0 != 31 );
  return result;
}

