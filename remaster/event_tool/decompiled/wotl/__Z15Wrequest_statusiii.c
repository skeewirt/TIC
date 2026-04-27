// __Z15Wrequest_statusiii @ 0x47208 (184 bytes)
// WotL iOS - debug symbols

int __fastcall Wrequest_status(int result, int a2, int a3)
{
  int v3; // r6

  v3 = result;
  if ( wstoprequest != 1 )
  {
    Wrecover_chrname();
    tonecommand = requestflg[v3];
    if ( a2 != 255 )
    {
      word_271BAE = a2;
      word_273EF8 = a2;
    }
    if ( a3 != 255 )
    {
      word_273F1A = a3;
      word_273F28 = a3;
    }
    if ( !wasmGetActiveTask(2) )
      Wtask_create(2, (void (__fastcall *)())request_statussub);
    return Wsend_taskparamater(2, v3, 0, 0);
  }
  return result;
}

