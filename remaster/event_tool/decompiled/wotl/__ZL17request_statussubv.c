// __ZL17request_statussubv @ 0x46EBC (768 bytes)
// WotL iOS - debug symbols

void __fastcall __noreturn request_statussub()
{
  int Input1; // r0
  int v1; // r3
  int v2; // r10
  char *v3; // r8
  char *v4; // r6
  int v5; // r0
  char *v6; // r4
  int v7; // r3
  int v8; // r2
  __int16 *v9; // r3
  char *v10; // r2
  int v11; // lr
  int v12; // r1
  int i; // r4
  int v14; // r0
  _DWORD var40[24]; // [sp+28h] [bp-58h] BYREF

  while ( 1 )
  {
    Input1 = wasmGetInput1();
    *((_DWORD *)&asmtaskframe + 256 * wasmtasknumber) = 255;
    wlastrequestno = Input1;
    var40[0] = 0;
    v1 = 1;
    if ( request_statussub(void)::no_keep != Input1 )
      request_statussub(void)::no_keep = Input1;
    do
      var40[v1++] = 0;
    while ( v1 != 16 );
    v2 = 0;
    v3 = (char *)&req + 48 * Input1;
    v4 = v3;
    do
    {
      v5 = *((_DWORD *)v4 + 4);
      v6 = (char *)&asmtaskframe + 1024 * v5;
      if ( *((_DWORD *)v6 + 18) )
      {
        v7 = *((_DWORD *)v6 + 19);
        if ( v7 != *((_DWORD *)v4 + 8) )
          goto LABEL_14;
        switch ( v7 )
        {
          case 17:
            v8 = (unsigned __int16)lastid1;
            v9 = (__int16 *)&wpersonalinfo;
            break;
          case 58:
            v8 = (unsigned __int16)lastid2;
            v9 = (__int16 *)&wpersonalinfo2;
            break;
          case 20:
            v8 = (unsigned __int16)lastid1;
            v9 = (__int16 *)&wpersonalinfo;
            break;
          default:
            goto LABEL_17;
        }
        if ( v8 != v9[5] )
        {
LABEL_14:
          var40[v5] = 1;
          Wsend_taskparamater(v5, 0, 0, 1);
        }
      }
      else if ( *(_DWORD *)v4 != -1 )
      {
        Wtask_create(v5, *(void (__fastcall **)())v4);
        Wsend_taskparamater(*((_DWORD *)v4 + 4), 0, 0, 0);
        *((_DWORD *)v6 + 19) = *((_DWORD *)v4 + 8);
        var40[*((_DWORD *)v4 + 4)] = 2;
      }
LABEL_17:
      ++v2;
      v4 += 4;
    }
    while ( v2 != 4 );
    lastid1 = word_271BAE;
    lastid2 = word_273F1A;
    while ( 1 )
    {
      v10 = v3;
      v11 = 0;
LABEL_20:
      v12 = *((_DWORD *)v10 + 4);
      if ( var40[v12] != 1 || !*((_DWORD *)&asmtaskframe + 256 * v12 + 18) )
        break;
      Wtask_wait(1);
    }
    ++v11;
    v10 += 4;
    if ( v11 != 4 )
      goto LABEL_20;
    for ( i = 0; i != 4; ++i )
    {
      v14 = *((_DWORD *)v3 + 4);
      if ( var40[v14] == 1 && *(_DWORD *)v3 != -1 )
      {
        Wtask_create(v14, *(void (__fastcall **)())v3);
        Wsend_taskparamater(*((_DWORD *)v3 + 4), 0, 0, 0);
        *((_DWORD *)&asmtaskframe + 256 * *((_DWORD *)v3 + 4) + 19) = *((_DWORD *)v3 + 8);
      }
      v3 += 4;
    }
    if ( wasmGetInput1() == 255 )
      Wtask_killmyself();
  }
}

