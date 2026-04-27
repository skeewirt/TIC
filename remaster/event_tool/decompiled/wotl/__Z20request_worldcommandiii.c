// __Z20request_worldcommandiii @ 0xA62DC (316 bytes)
// WotL iOS - debug symbols

int __fastcall request_worldcommand(int a1, int a2, int a3)
{
  int result; // r0
  int v5; // r6
  char *v6; // r2
  __int16 v7; // r1
  __int16 v8; // r0
  int v9; // r1
  __int16 v10; // r3
  _WORD v11[4]; // [sp+0h] [bp-14h] BYREF

  result = TRACE_Dummy("request_worldcommand no:%d x:%d y:%d\n", a1, a2, a3);
  if ( !*((_DWORD *)wasmtaskframeptr + 2066) )
  {
    lastworldcommand = a1;
    v5 = a1 << 6;
    wcombase = (int)&worldmaptes;
    if ( a1 == 4 )
    {
      v11[0] = 384;
      v11[2] = 168;
      v11[3] = 256;
      v11[1] = 0;
      ClearImage(v11, 0, 0, 0);
    }
    v6 = (char *)&worldmaptes + v5;
    v7 = *(_WORD *)((char *)&worldmaptes + v5 + 12);
    *((_WORD *)v6 + 4) = -112;
    *((_WORD *)v6 + 5) = -80;
    if ( v7 - 112 > 128 )
      *((_WORD *)v6 + 4) = 120 - v7;
    v8 = *(_WORD *)((char *)&worldmaptes + v5 + 14);
    v9 = *(__int16 *)((char *)&worldmaptes + v5 + 10);
    if ( v9 + v8 <= 120 )
    {
      if ( v9 >= -120 )
      {
LABEL_11:
        Wtask_create(8, *(void (__fastcall **)())(v5 + wcombase + 40));
        return Wsend_taskparamater(8, v5 + wcombase, 0, 0);
      }
      v10 = -112;
    }
    else
    {
      v10 = 112 - v8;
    }
    *(_WORD *)((char *)&worldmaptes + v5 + 10) = v10;
    goto LABEL_11;
  }
  return result;
}

