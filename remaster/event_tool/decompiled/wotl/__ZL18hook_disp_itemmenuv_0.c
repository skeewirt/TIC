// __ZL18hook_disp_itemmenuv_0 @ 0x76140 (68 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_disp_itemmenu()
{
  maskhelp = 1;
  task_create(asmtasknumber - 1, (void (__fastcall *)())hook_disp_itemmenu3);
  wait_taskend(asmtasknumber - 1);
  task_killmyself();
}

