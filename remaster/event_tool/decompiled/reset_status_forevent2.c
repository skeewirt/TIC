// reset_status_forevent2 @ 0x14F7496D0 (34 bytes)

void __fastcall sub_14F7496D0()
{
  __int64 v0; // r15
  _UNKNOWN *retaddr; // [rsp+0h] [rbp+0h] BYREF

  _InterlockedExchange64((volatile __int64 *)&retaddr, (__int64)&qword_14B7D4370[203] + 4);
  retaddr = (_UNKNOWN *)(v0 - 109830448);
}

