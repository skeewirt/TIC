// __Z15changeFlameRatei @ 0x1562AC (36 bytes)
// WotL iOS - debug symbols

int __fastcall changeFlameRate(int a1)
{
  if ( (unsigned int)(a1 - 1) > 1 )
    return -1;
  iOS_SetFrameRate(a1);
  return 0;
}

