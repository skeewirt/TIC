// __Z17checkstatusscrolli @ 0x5D558 (60 bytes)
// WotL iOS - debug symbols

int __fastcall checkstatusscroll(int a1)
{
  int bwp; // r0
  int v2; // r2
  int v3; // r1
  int result; // r0

  bwp = get_bwp(a1);
  v2 = 0;
  v3 = bwp;
  while ( 1 )
  {
    result = *(unsigned __int8 *)(v3 + v2 + 97);
    if ( *(_BYTE *)(v3 + v2 + 97) )
      break;
    if ( ++v2 == 5 )
      return result;
  }
  return 1;
}

