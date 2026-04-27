// event_call @ 0x140225744 (69 bytes)
// Decompiled by IDA Pro - Event System Phase 0

bool sub_14022572C()
{
  char v0; // al
  char v1; // cl

  v0 = sub_1402256F0();
  v1 = 0;
  if ( v0 )
    return 1;
  if ( dword_142E7954C && !(_DWORD)qword_142FF37C4 && HIDWORD(qword_142FF37BC) && !HIDWORD(qword_142FF3778) )
    return dword_142FF382C != 2;
  return v1;
}

