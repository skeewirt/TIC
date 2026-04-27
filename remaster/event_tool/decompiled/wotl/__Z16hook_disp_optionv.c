// __Z16hook_disp_optionv @ 0x761F4 (44 bytes)
// WotL iOS - debug symbols

int __fastcall hook_disp_option()
{
  maskhelp = 1;
  wait_overlay(1);
  return disp_option(0);
}

