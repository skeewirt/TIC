// serchmessagepointer @ 0x14CDB69E1 (72 bytes)

__int64 __fastcall sub_14CDB69E1(__int64 a1)
{
  int v1; // eax
  int v2; // r11d
  __int64 result; // rax
  int v4; // r11d
  __int64 v5; // [rsp+0h] [rbp-8h] BYREF

  *(_BYTE *)(a1 + 41) = __ROL1__(*(_BYTE *)(a1 + 41), 210);
  result = v2 + (*(_DWORD *)((char *)&qword_1440AFA18[334] + 7) ^ 0xDBE1993E ^ v1);
  v4 = v2 ^ 0x3ECE658A;
  v5 = (unsigned int)v4;
  _InterlockedExchange64(&v5, *((_QWORD *)&off_155562F62 + (v4 <= 0)));
  return result;
}

