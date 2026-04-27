// __ZL13waitscrollingv @ 0x5EAF4 (52 bytes)
// WotL iOS - debug symbols

int __fastcall waitscrolling()
{
  int i; // r4

  for ( i = 0; ; ++i )
  {
    asmTaskEntry();
    if ( !checkScrolling() )
      break;
  }
  return TRACE_Dummy("waitscrolling %d\n", i);
}

