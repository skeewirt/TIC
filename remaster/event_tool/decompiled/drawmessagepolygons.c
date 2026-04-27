// drawmessagepolygons @ 0x14020BDE8 (98 bytes)
// Decompiled by IDA Pro - Event System Phase 0

void __fastcall sub_14020BDB4(__int64 a1)
{
  __int64 v1; // rdx
  __int64 v2; // rax

  if ( a1 )
  {
    LODWORD(v1) = 0;
    v2 = 0;
    while ( *(_QWORD *)&xmmword_142FE9FB0[v2] != a1 )
    {
      v1 = (unsigned int)(v1 + 2);
      if ( ++v2 >= 3 )
      {
        sub_1403048CC(a1, v1, 0, &_ImageBase);
        return;
      }
    }
    xmmword_142FE9FB0[v2] = 0;
    *((_QWORD *)&unk_142FE9200 + 73 * (int)v1) = 0;
    *((_QWORD *)&unk_142FE9200 + 73 * (int)v1 + 73) = 0;
  }
}

