// event_call_inner_sub_1402256F0 @ 0x1402256F0 (58 bytes)
// Decompiled by IDA Pro - Event System Phase 0 (batch 2)

bool __fastcall sub_1402256F0(__int64 a1, __int64 a2)
{
  __int64 v2; // rdx
  char v3; // bl

  v3 = 0;
  if ( (unsigned int)read_eventflag(508, a2) && (unsigned int)read_eventflag(39, v2) - 410 > 0xF )
    return dword_141843948 == 0;
  return v3;
}

