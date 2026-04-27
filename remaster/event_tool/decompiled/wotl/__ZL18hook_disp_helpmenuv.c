// __ZL18hook_disp_helpmenuv @ 0x552AC (72 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_disp_helpmenu()
{
  if ( Wchecktaskkind(21) )
  {
    if ( !Wchecktaskkind(49) )
      wsoundf = 1;
  }
  mallocbytask(0x20000u);
  Wwait_overlay(3);
  Wdisp_helpmenu();
}

