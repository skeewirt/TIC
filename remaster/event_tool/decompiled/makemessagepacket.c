// makemessagepacket @ 0x1402DA28C (43 bytes)
// Decompiled by IDA Pro - Event System Phase 0

char *__fastcall sub_1402DA26C(_DWORD *a1)
{
  _DWORD *v1; // r9
  _QWORD *v2; // r8
  char *result; // rax
  __int64 v4; // rdx

  v1 = a1;
  v2 = &unk_141844460;
  do
  {
    result = &byte_141844560;
    v4 = (unsigned int)(*v1++ + 128);
    *v2++ = (char *)a1 + v4;
  }
  while ( (__int64)v2 < (__int64)&byte_141844560 );
  return result;
}

