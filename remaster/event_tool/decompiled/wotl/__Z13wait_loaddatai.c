// __Z13wait_loaddatai @ 0x5CAA0 (116 bytes)
// WotL iOS - debug symbols

int __fastcall wait_loaddata(int result)
{
  int v1; // r5

  v1 = result;
  while ( loadoverlay || loaddata )
    result = asmTaskEntry();
  loaddata = v1;
  while ( loaddata )
    result = asmTaskEntry();
  if ( loadf == 1 )
    task_killmyself();
  return result;
}

