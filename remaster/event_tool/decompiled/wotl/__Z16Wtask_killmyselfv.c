// __Z16Wtask_killmyselfv @ 0xA52EC (64 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn Wtask_killmyself()
{
  int v0; // r2

  v0 = wasmtasknumber << 10;
  *((_DWORD *)wasmtaskframeptr + 256 * wasmtasknumber + 18) = 0;
  *(_DWORD *)((char *)wasmtaskframeptr + v0 + 76) = 0;
  TE_task_killmyself();
}

