// __Z12erase_unit_fi @ 0x11D71C (76 bytes)
// WotL iOS - debug symbols

int __fastcall erase_unit_f(int a1)
{
  char *v2; // r0

  TRACE_Dummy("erase_unit_f unit %d\n", a1);
  v2 = (char *)&bwork + 486 * a1;
  if ( (unsigned __int8)v2[1] != 255 )
  {
    v2[1] = -1;
    v2[421] = 0x80;
  }
  return 0;
}

