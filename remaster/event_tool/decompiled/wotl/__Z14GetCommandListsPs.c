// __Z14GetCommandListsPs @ 0xF3A0C (172 bytes)
// WotL iOS - debug symbols

int __fastcall GetCommandList(__int16 a1, __int16 *a2)
{
  int v2; // r4
  int v4; // r6
  unsigned __int8 v5; // r0
  int v6; // r3
  int v7; // r4
  __int16 v8; // r5
  bool v9; // zf
  unsigned __int8 *jobdata; // r0
  int v11; // r2
  int v12; // r0
  __int16 v14[23]; // [sp+2h] [bp-42h] BYREF

  v2 = a1;
  v4 = 0;
  TRACE_Dummy("GetCommandList\n");
  v5 = v2;
  v6 = ChrList[v2];
  v7 = 0;
  v8 = *(_WORD *)(v6 + 36);
  GetJobList(v5, v14, 1);
  while ( 1 )
  {
    v12 = v14[v7];
    if ( v12 == -1 )
      break;
    v9 = v8 == v12;
    if ( v8 != v12 )
      v9 = v12 == 93;
    if ( !v9 )
      v9 = v12 == 161;
    if ( !v9 && v12 != 164 )
    {
      jobdata = (unsigned __int8 *)get_jobdata(v12);
      v11 = v4++;
      a2[v11] = *jobdata;
    }
    ++v7;
  }
  a2[v4] = -1;
  return v4;
}

