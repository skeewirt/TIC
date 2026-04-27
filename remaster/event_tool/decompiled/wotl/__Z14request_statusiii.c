// __Z14request_statusiii @ 0x5E2AC (184 bytes)
// WotL iOS - debug symbols

int __fastcall request_status(int result, int a2, int a3)
{
  int v3; // r6

  v3 = result;
  if ( stoprequest != 1 )
  {
    recover_chrname();
    tonecommand = requestflg[v3];
    if ( a2 != 255 )
    {
      word_27B28E = a2;
      word_29330E = a2;
    }
    if ( a3 != 255 )
    {
      word_293330 = a3;
      word_29333E = a3;
    }
    if ( !asmGetActiveTask(2) )
      task_create(2, (void (__fastcall *)())request_statussub);
    return send_taskparamater(2, v3, 0, 0);
  }
  return result;
}

