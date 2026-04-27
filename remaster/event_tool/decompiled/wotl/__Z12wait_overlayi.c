// __Z12wait_overlayi @ 0x5CB28 (124 bytes)
// WotL iOS - debug symbols

int __fastcall wait_overlay(int a1)
{
  int result; // r0

  result = TRACE_Dummy("wait_overlay\n");
  while ( loadoverlay || loaddata )
    result = asmTaskEntry();
  loadoverlay = a1;
  while ( loadoverlay )
    result = asmTaskEntry();
  if ( loadf == 1 )
    task_killmyself();
  return result;
}

