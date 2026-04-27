// __Z13Wwait_overlayi @ 0x465FC (124 bytes)
// WotL iOS - debug symbols

int __fastcall Wwait_overlay(int a1)
{
  int result; // r0

  result = TRACE_Dummy("wait_overlay\n");
  while ( wloadoverlay || wloaddata )
    result = wasmTaskEntry();
  wloadoverlay = a1;
  while ( wloadoverlay )
    result = wasmTaskEntry();
  if ( wloadf == 1 )
    Wtask_killmyself();
  return result;
}

