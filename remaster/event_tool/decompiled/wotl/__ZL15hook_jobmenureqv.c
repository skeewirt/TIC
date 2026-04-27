// __ZL15hook_jobmenureqv @ 0x9AD64 (280 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_jobmenureq()
{
  void *v0; // r8

  iOS_setV2Icon(3, 1);
  iOS_setV2Icon(4, 1);
  export_localstatus((char *)&cstatusainfo, (char *)&cpersonalinfo, (char *)&cstatuscinfo);
  while ( 1 )
  {
    v0 = (void *)mallocAddress((void *)FileLoadAddress, 0x1F000u);
    if ( v0 == (void *)FileLoadAddress )
      break;
    asmTaskEntry();
    if ( gDebugDisplay )
      FntPrint("WAIT FOR FILEALLOCATION\n");
  }
  wait_overlay(7);
  task_wait(2);
  exeoverlay = 3;
  do
  {
    padptr = import_localpad(0);
    *(_DWORD *)padptr = 0;
    asmTaskEntry();
  }
  while ( exeoverlay );
  *(_DWORD *)padptr = 0;
  freeForFile(v0);
  task_wait(2);
  maskhelp = 0;
  iOS_setV2Icon(3, 0);
  task_killmyself();
}

