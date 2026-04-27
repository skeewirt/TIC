// __Z11task_createlPc @ 0x1D06D8 (140 bytes)
// WotL iOS - debug symbols

int __fastcall task_create(int a1, void (__fastcall *a2)())
{
  int v4; // r4
  int GP; // r0
  _DWORD *v6; // r3

  v4 = gStackAsmTaskPtr[a1] + 2032;
  GP = asmGetGP();
  v4 += 12;
  v6 = (_DWORD *)((char *)asmtaskframeptr + 1024 * a1);
  v6[18] = 1;
  v6[15] = v4;
  v6[16] = v4;
  v6[17] = a2;
  v6[19] = 0;
  v6[3] = 0;
  v6[20] = 0;
  v6[21] = 0;
  v6[22] = 0;
  v6[23] = 0;
  v6[24] = 0;
  v6[25] = 0;
  v6[26] = 0;
  v6[14] = GP;
  return TE_task_create(a1, a2, 0);
}

