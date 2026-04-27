// sub_1402F2318 @ 0x1402F2318 (181 bytes)
// Decompiled by IDA Pro - Event System Phase 0 (batch 2)

__int64 __fastcall sub_1402F2318(int a1, int a2, unsigned __int16 a3, __int64 a4)
{
  char v4; // r10
  unsigned __int16 *v5; // rax
  __int64 v6; // rsi
  unsigned int v7; // ebx
  int v8; // edi
  __int64 v9; // r11
  __int64 i; // rcx
  __int16 v11; // cx

  v4 = a1;
  v5 = (unsigned __int16 *)(a4 + 2);
  v6 = (__int64)a1 << 9;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  while ( *v5 <= a3 )
  {
    ++v8;
    ++v9;
    v5 += 2;
    if ( v9 >= 40 )
      goto LABEL_13;
  }
  for ( i = 39; i > v9; --i )
    *(_DWORD *)(a4 + 4 * i) = *(_DWORD *)(a4 + 4 * i - 4);
  *(_WORD *)(a4 + 4LL * v8 + 2) = a3;
  if ( a2 )
  {
    v4 += 64;
    if ( *((_BYTE *)&unk_14184D890 + v6 + 417) == 18 )
    {
      v4 += 32;
    }
    else
    {
      v11 = *(_WORD *)((char *)&unk_14184D890 + v6 + 418);
      *(_BYTE *)(a4 + 4LL * v8 + 1) = v11;
      if ( v11 > 255 )
        v4 += 0x80;
    }
  }
  *(_BYTE *)(a4 + 4LL * v8) = v4;
LABEL_13:
  LOBYTE(v7) = v8 != 40;
  return v7;
}

