// read_eventflag @ 0x14021F2E0 (124 bytes)
// Decompiled by IDA Pro - Event System Phase 0

void *sub_14021F294()
{
  __int64 v0; // rbx
  __int64 v1; // rdx
  __int64 v2; // r8
  __int64 v3; // r9
  void *result; // rax
  __int64 v5; // rcx

  v0 = *((_QWORD *)off_14077D0A8 + (unsigned int)(dword_140D3A500 << 8));
  dword_140D3A4D0 = 1;
  while ( 1 )
  {
    sub_14030497C();
    if ( (unsigned int)sub_140218204(off_1407D67F8) )
      break;
    sub_140217D14(v0, 0);
    sub_140218110(v0);
  }
  sub_14030497C();
  result = off_14077D0A8;
  dword_140D3A4D0 = 0;
  v5 = (unsigned int)(dword_140D3A500 << 8);
  if ( !*((_QWORD *)off_14077D0A8 + v5 + 1) )
    return (void *)sub_1403048CC(v5, v1, v2, v3);
  return result;
}

