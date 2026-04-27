// __ZL18hook_disp_helpmenuv_0 @ 0x7ADB8 (72 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_disp_helpmenu()
{
  if ( checktaskkind(21) )
  {
    if ( !checktaskkind(49) )
      soundf = 1;
  }
  mallocbytask(0x20000u);
  wait_overlay(3);
  disp_helpmenu();
}

