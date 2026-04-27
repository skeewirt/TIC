// __ZL18change_maincommandP9COMRECORD @ 0x45E4C (188 bytes)
// WotL iOS - debug symbols

int __fastcall change_maincommand(int result)
{
  int v1; // r5
  int v2; // r2
  int i; // r6
  int v4; // r3
  __int16 v5; // r1

  v1 = result;
  if ( *(_DWORD *)(result + 36) )
  {
    v2 = *(__int16 *)(result + 30);
    for ( i = 0; ; ++i )
    {
      if ( i > v2 )
        return result;
      v4 = *(__int16 *)(*(_DWORD *)(v1 + 36) + 2 * i);
      if ( v4 == 1 || v4 == 60 )
        break;
LABEL_14:
      ;
    }
    result = (char)pspNetGetBattleModeFlag();
    if ( (char)result == 1 )
    {
      v5 = 20650;
      *(_WORD *)(*(_DWORD *)(v1 + 36) + 2 * i) = 60;
    }
    else
    {
      if ( (char)result != 2 )
      {
        if ( !(_BYTE)result )
          *(_WORD *)(*(_DWORD *)(v1 + 36) + 2 * i) = 1;
        goto LABEL_13;
      }
      v5 = 20651;
      *(_WORD *)(*(_DWORD *)(v1 + 36) + 2 * i) = 60;
    }
    word_272AD0 = v5;
LABEL_13:
    v2 = *(__int16 *)(v1 + 30);
    goto LABEL_14;
  }
  return result;
}

