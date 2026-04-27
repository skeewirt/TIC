// __ZL15drive_minieventi @ 0x5DF24 (56 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall drive_minievent(int a1)
{
  clear_menu();
  task_create(4, (char *)minievent);
  return send_taskparamater(4, a1, 0, 0);
}

