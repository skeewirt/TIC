// __ZL9hook_spelv @ 0x75AD0 (320 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_spel()
{
  int Input1; // r5
  int bwp; // r4
  int AnimationIDFormBattleWork; // r0
  int v3; // r8
  int v4; // r6
  int Input2; // r5
  _WORD v6[4]; // [sp+0h] [bp-1Ch] BYREF

  minieventcounter = 1;
  *((_DWORD *)&asmtaskframe + 256 * asmtasknumber + 19) = 70;
  changeflame(2);
  send_taskparamater(8, 0, 0, 1);
  wait_taskend(8);
  task_wait(3);
  Input1 = asmGetInput1();
  wordfield[0] = Input1;
  dword_274DB4 = Input1;
  dword_274DB8 = Input1;
  bwp = get_bwp(Input1);
  AnimationIDFormBattleWork = getAnimationIDFormBattleWork(Input1);
  getanimpos2d(AnimationIDFormBattleWork, v6);
  v3 = *(unsigned __int8 *)(bwp + 385);
  if ( v6[1] <= 127 )
    v4 = 18;
  else
    v4 = 17;
  Input2 = asmGetInput2();
  loaddataadr = mallocForFile(0x4000u);
  wait_loaddata(4);
  dword_1200E48 = loaddataadr;
  task_create(8, (void (__fastcall *)())mesputmain);
  send_taskparamater(8, v4, Input2 | 0xA800, v3);
  wait_taskend(8);
  freeForFile((void *)loaddataadr);
  menuoutput = 7;
  changeflame(1);
  minieventcounter = 0;
  task_killmyself();
}

