// __Z9hook_wipev @ 0x75C40 (52 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_wipe()
{
  *((_DWORD *)&asmtaskframe + 256 * asmtasknumber + 19) = 54;
  wait_overlay(6);
  wipe_const();
}

