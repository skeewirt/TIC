// InitCamera @ 0x14037CDA0 (259 bytes)
// Decompiled by IDA Pro - Event System Phase 0

__int64 sub_14037CD88()
{
  __int16 v0; // cx
  __int64 result; // rax
  __int128 v2; // xmm0

  LOWORD(qword_143C4B678) = *(_WORD *)(qword_143CC30A8 + 147676) & 0xFFF;
  LOWORD(qword_143C4B670) = qword_143C4B678;
  LOWORD(qword_143C4B668) = qword_143C4B678;
  LOWORD(qword_143C4B680) = qword_143C4B678;
  WORD1(qword_143C4B678) = *(_WORD *)(qword_143CC30A8 + 147678) & 0xFFF;
  WORD1(qword_143C4B670) = WORD1(qword_143C4B678);
  WORD1(qword_143C4B668) = WORD1(qword_143C4B678);
  v0 = *(_WORD *)(qword_143CC30A8 + 147680) & 0xFFF;
  WORD1(qword_143C4B680) = WORD1(qword_143C4B678);
  WORD2(qword_143C4B678) = v0;
  WORD2(qword_143C4B670) = v0;
  WORD2(qword_143C4B668) = v0;
  LODWORD(xmmword_143C4B6B8) = *(int *)(qword_143CC30A8 + 147700) >> 12;
  LODWORD(xmmword_143C4B6A8) = xmmword_143C4B6B8;
  LODWORD(xmmword_143C4B698) = xmmword_143C4B6B8;
  LODWORD(xmmword_143C4B6C8) = xmmword_143C4B6B8;
  DWORD1(xmmword_143C4B6B8) = *(int *)(qword_143CC30A8 + 147704) >> 12;
  DWORD1(xmmword_143C4B6A8) = DWORD1(xmmword_143C4B6B8);
  DWORD1(xmmword_143C4B698) = DWORD1(xmmword_143C4B6B8);
  DWORD1(xmmword_143C4B6C8) = DWORD1(xmmword_143C4B6B8);
  result = (unsigned int)(*(int *)(qword_143CC30A8 + 147708) >> 12);
  DWORD2(xmmword_143C4B6B8) = result;
  DWORD2(xmmword_143C4B6A8) = result;
  DWORD2(xmmword_143C4B698) = result;
  v2 = *(_OWORD *)(qword_143CC30A8 + 147660);
  WORD2(qword_143C4B680) = v0;
  DWORD2(xmmword_143C4B6C8) = result;
  xmmword_143C4B700 = v2;
  xmmword_143C4B6F0 = v2;
  xmmword_143C4B6E0 = v2;
  xmmword_143C4B710 = v2;
  return result;
}

