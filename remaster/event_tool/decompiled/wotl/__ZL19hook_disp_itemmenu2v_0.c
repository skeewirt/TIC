// __ZL19hook_disp_itemmenu2v_0 @ 0x79C4C (288 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn hook_disp_itemmenu2()
{
  int i; // r4
  int v1; // r0
  int v2; // r4

  addactiveturn = 4;
  do
    asmTaskEntry();
  while ( asmGetActiveTask(6) );
  exeoverlay = 2;
  allstopf = 0;
  do
    task_wait(1);
  while ( exeoverlay );
  freeForFile((void *)FileLoadAddress);
  send_taskparamater(2, 0, 0, 1);
  for ( i = 3; i != 15; ++i )
  {
    v1 = i;
    send_taskparamater(v1, 0, 0, 1);
  }
  v2 = 239;
  localfadef = 255;
  asmTaskEntry();
  do
  {
    localfadef = v2;
    v2 -= 16;
    asmTaskEntry();
  }
  while ( v2 != -1 );
  localfadef = 0;
  maskhelp = 0;
  stoprequest = 0;
  addactiveturn = 0;
  request_status(2, word_27B28E, 255);
  task_killmyself();
}

