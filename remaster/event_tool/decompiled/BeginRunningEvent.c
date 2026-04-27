// BeginRunningEvent @ 0x140222324 (119 bytes)

__int64 sub_1402222DC()
{
  __int16 v0; // r11
  _BYTE *v1; // r8
  int v2; // r9d
  __int64 v3; // rdx
  __int64 v4; // rcx
  __int64 v5; // r8
  unsigned int v6; // r9d
  unsigned __int64 v7; // r10
  __int64 result; // rax

  LOBYTE(v0) = 0;
  v1 = &unk_142FE5F16;
  LOWORD(v2) = 0;
  do
  {
    *(v1 - 2) = v0;
    *v1 = v0;
    if ( sub_14024C948((unsigned __int16)v2) )
      result = sub_14025E990(v6);
    else
      result = 255;
    *(_BYTE *)(v5 - 1) = result;
    if ( v7 >= 0x2A )
      _report_rangecheckfailure(v4, v3);
    *(_WORD *)((char *)&xmmword_142FE5FB0 + v7) = v0;
    v2 = v6 + 1;
    *(_WORD *)((char *)&xmmword_142FE5FE0 + v7) = v0;
    v1 = (_BYTE *)(v5 + 7);
  }
  while ( v2 < 21 );
  return result;
}

