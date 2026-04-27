// __Z15task_killmyselfv @ 0x1D062C (64 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn task_killmyself()
{
  int v0; // r2

  v0 = asmtasknumber << 10;
  *((_DWORD *)asmtaskframeptr + 256 * asmtasknumber + 18) = 0;
  *(_DWORD *)((char *)asmtaskframeptr + v0 + 76) = 0;
  TE_task_killmyself();
}

