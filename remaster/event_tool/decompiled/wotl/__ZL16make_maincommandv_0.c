// __ZL16make_maincommandv_0 @ 0x715C4 (116 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn make_maincommand()
{
  int Input1; // r0
  int v1; // r5
  int v2; // r6

  TRACE_Dummy("make_maincommand\n");
  Input1 = asmGetInput1();
  v1 = 17 * word_27B28E;
  v2 = Input1;
  change_maincommand();
  *((_DWORD *)&asmtaskframe + 256 * asmtasknumber + 1) = 1;
  disp_selectwindow();
  iOS_v2menuSetType(0);
  cursv[v1] = *(_WORD *)(v2 + 56);
  task_killmyself();
}

