// __ZL18hook_disp_itemmenuv @ 0x55150 (68 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_disp_itemmenu()
{
  wmaskhelp = 1;
  Wtask_create(wasmtasknumber - 1, (void (__fastcall *)())hook_disp_itemmenu3);
  Wwait_taskend(wasmtasknumber - 1);
  Wtask_killmyself();
}

