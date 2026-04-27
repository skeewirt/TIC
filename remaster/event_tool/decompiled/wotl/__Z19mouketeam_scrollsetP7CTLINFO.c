// __Z19mouketeam_scrollsetP7CTLINFO @ 0x19F30C (264 bytes)
// WotL iOS - debug symbols

int __fastcall mouketeam_scrollset(int a1)
{
  int v2; // r5
  unsigned __int8 *unitwork_add_wld; // r0
  unsigned __int8 *v4; // r4
  int IsSpecialJob; // r0
  __int16 v6; // r1
  int v7; // r2
  int v8; // r12
  int v9; // r1
  int result; // r0

  v2 = 0;
  *(_DWORD *)(a1 + 48) = 0;
  do
  {
    unitwork_add_wld = (unsigned __int8 *)get_unitwork_add_wld(v2);
    v4 = unitwork_add_wld;
    if ( !unitwork_add_wld[238] && unitwork_add_wld[1] != 255 && (unitwork_add_wld[4] & 0x20) == 0 )
    {
      IsSpecialJob = pspJobIsSpecialJob(*unitwork_add_wld);
      if ( !IsSpecialJob )
      {
        while ( 1 )
        {
          if ( IsSpecialJob >= mouke_unitcnt )
          {
            v6 = 0;
            v7 = 2 * *(_DWORD *)(a1 + 48);
            goto LABEL_12;
          }
          if ( mouke_unitno[IsSpecialJob] == v2 )
            break;
          ++IsSpecialJob;
        }
        v6 = 8;
        v7 = 2 * *(_DWORD *)(a1 + 48);
LABEL_12:
        *(_WORD *)((char *)&scritem_col + v7) = v6;
        v8 = *(_DWORD *)(a1 + 48);
        v9 = v8;
        scritem[v9] = v2 + 0x4000;
        *(_WORD *)((char *)&scritem2 + v9 * 2) = v4[29];
        *(_DWORD *)(a1 + 48) = v8 + 1;
      }
    }
    ++v2;
  }
  while ( v2 != 24 );
  result = *(_DWORD *)(a1 + 48);
  if ( result >= 6 )
    return 6;
  return result;
}

