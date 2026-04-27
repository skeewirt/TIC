// __Z10wait_direci @ 0x62CC4 (204 bytes)
// WotL iOS - debug symbols

int __fastcall wait_direc(int a1)
{
  int v1; // r4
  char *v2; // r2
  int i; // r1
  int result; // r0
  int v5; // r6
  int v6; // r5

  if ( a1 == -1 )
  {
    v1 = 0;
    TRACE_Dummy("wait_direc_all start \n");
LABEL_3:
    ++v1;
    asmTaskEntry();
    v2 = eventdirec;
    for ( i = 0; i != 21; ++i )
    {
      if ( v2[4] )
        goto LABEL_3;
      v2 += 7;
    }
    return TRACE_Dummy("wait_direc end ii:%d\n", v1);
  }
  else
  {
    result = cnvglobaltolocalid(a1);
    v5 = result;
    if ( result != 2000 )
    {
      v6 = 0;
      TRACE_Dummy("wait_direc start chr:%d\n", result);
      do
      {
        asmTaskEntry();
        ++v6;
      }
      while ( eventdirec[7 * v5 + 4] );
      return TRACE_Dummy("wait_direc end chr:%d %ii:d\n", v5, v6);
    }
  }
  return result;
}

