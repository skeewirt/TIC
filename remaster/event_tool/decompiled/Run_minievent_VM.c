// Run_minievent_VM @ 0x14C580CFA (109 bytes)

__int64 sub_14C580CFA()
{
  __int64 v0; // r9
  __int64 i; // r8
  __int64 v2; // rax
  __int64 result; // rax
  _QWORD *v4; // rdx
  __int64 v5; // r11

  v0 = qword_140D3A508;
  for ( i = 0; i < 11; ++i )
  {
    v2 = byte_14066D0B8[i];
    *(_WORD *)(88 * v2 + v0 + 80) = 0;
  }
  result = sub_1403047E8((unsigned int)(-1957932731 - dword_14DDF7C9C), sub_1402241A0);
  v4 = off_14077D0A8;
  *((_QWORD *)off_14077D0A8 + 1024) = v5;
  v4[1025] = 0;
  v4[1026] = 0;
  return result;
}

