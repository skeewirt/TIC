// __ZL12hook_chapterv @ 0x75A18 (52 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_chapter()
{
  *((_DWORD *)&asmtaskframe + 256 * asmtasknumber + 19) = 61;
  wait_overlay(12);
  disp_chapter();
}

