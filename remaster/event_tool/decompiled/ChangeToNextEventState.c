// ChangeToNextEventState @ 0x14CF38140 (401 bytes)

// positive sp value has been detected, the output may be wrong!
char __fastcall sub_14CF38140(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // r12
  __int64 v5; // r13
  __int64 v6; // rdx
  __int64 v7; // rdx
  int v8; // ebp
  bool v10; // cf
  char v11; // al
  __int64 v12; // rbp
  __int64 v13; // rdi
  _QWORD *v14; // r12
  __int64 v15; // r14
  char result; // al
  __int64 v17; // rdx
  __int64 v18; // r12
  __int64 v19; // rsi
  __int64 v20; // r12
  __int64 v21; // [rsp-8h] [rbp-18h] BYREF
  __int64 v22; // [rsp+0h] [rbp-10h]
  __int64 v23; // [rsp+8h] [rbp-8h] BYREF

  result = v10 + v11 + 36;
  v23 &= a2;
  v17 = *v14 + v23;
  v18 = *(_QWORD *)(v15 + 160);
  v19 = v17 + v18;
  v20 = v17 | v18;
  *(_QWORD *)(v15 + 160) = ((v19 - v20) ^ v17) + v19 - v20;
  v23 = v20;
  v4 = *(_QWORD *)(v15 + 160) ^ ~(v20 ^ ~v20);
  v5 = *((_QWORD *)NtCurrentTeb()->ThreadLocalStoragePointer
       + *(unsigned int *)(*(__int64 *)((char *)&qword_1555E6260[4] + 6) - 46986129));
  v23 = v15;
  v23 = a4
      - MEMORY[0x7FFE0288]
      + (int)(*(_QWORD *)(v5 + 5104) - 172017260 + 1846649530)
      - ((v4 ^ (a4 - MEMORY[0x7FFE0288]))
       + 2 * (v4 & (a4 - MEMORY[0x7FFE0288])));
  v6 = v23;
  v22 = ~v4;
  v21 = v4;
  _InterlockedExchange64(&v21, ~v4);
  v22 = ~v22;
  v22 += v6 + 1;
  __asm { rcr     qword ptr [rsp+0], 1 }
  v7 = v23;
  v23 = v12;
  v22 = v7;
  LODWORD(v7) = __ROL4__(10, 26);
  v8 = v7 | 0x809A0B;
  if ( (int)v7 < 0 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))sub_14D1B0321)(a1, v22, a3, -2147353225);
  v10 = __CFSHR__(v8, 12);
  _RBP = (unsigned int)(v8 >> 12);
  __asm { rcl     ebp, 0Ch }
  if ( v10 )
    JUMPOUT(0x14928F874LL);
  v22 = ~_RBP & _RBP;
  v23 = v13;
  _InterlockedExchange64(&v23, (__int64)sub_14A9F16ED);
  v23 += 39086802;
  return result;
}

