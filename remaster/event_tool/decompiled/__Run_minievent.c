// __Run_minievent @ 0x14CF2C805 (78 bytes)

DWORD __fastcall sub_14CF2C805(int a1)
{
  char v1; // cf
  char v2; // al
  __int64 v3; // rbp
  __int64 v4; // rdi
  _QWORD *v5; // r13
  __int64 v6; // rcx
  HMODULE v7; // rcx
  WCHAR *v8; // rdx
  __int64 v9; // r8
  __int64 v11[6]; // [rsp+0h] [rbp-30h] BYREF

  v6 = (unsigned int)(a1 - 1);
  if ( ((char)(v1 + v2 + 3) < 0) ^ (__OFADD__(v1, v2) | __OFADD__(3, v1 + v2)) | (v1 + v2 == -3) )
    return sub_146508AB0(v6);
  v7 = (HMODULE)v5[5];
  v8 = (WCHAR *)v5[18];
  v9 = v5[16];
  v11[5] = v3;
  v11[0] = v4;
  _InterlockedExchange64(v11, (__int64)&sub_14CF2C854);
  return GetModuleFileNameW(v7, v8, v9);
}

