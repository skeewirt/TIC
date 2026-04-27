// event_init_memory @ 0x1402E578C (165 bytes)
// Decompiled by IDA Pro - Event System Phase 0

void *sub_1402E576C()
{
  int v0; // ecx
  void *result; // rax

  if ( qword_143CD3500 )
  {
    v0 = *(_DWORD *)(qword_143CD3500 + 8);
    if ( !v0 )
    {
      result = &unk_1408D7EF0;
      goto LABEL_9;
    }
    if ( v0 == 3 )
    {
      result = &unk_1408DAA50;
      goto LABEL_9;
    }
  }
  else
  {
    v0 = 1;
  }
  result = &unk_1408D94A0;
  if ( v0 == 2 )
    result = &unk_1408DC000;
LABEL_9:
  qword_141844DE8 = (__int64)result;
  off_140787698 = &unk_141844F90;
  qword_141844F68 = (__int64)&unk_142FCCF60;
  qword_141844DD8 = (__int64)&unk_1408B3EF0;
  qword_141844F78 = (__int64)&unk_140D37020;
  off_140787D38 = &unk_140D39C20;
  word_141844E48 = 0;
  word_141844F14 = 0;
  return result;
}

