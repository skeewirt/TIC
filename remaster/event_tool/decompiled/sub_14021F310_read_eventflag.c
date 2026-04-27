// sub_14021F310_read_eventflag @ 0x14021F310 (128 bytes)

__int64 __fastcall sub_14021F310(unsigned int a1)
{
  int v2; // esi
  __int64 v3; // rbx
  char v4; // al
  __int64 result; // rax

  v2 = *(_DWORD *)off_14077D0F8;
  if ( a1 == 34 )
  {
    v3 = sub_14021F310(36) & 1;
    v4 = sub_14021F310(35);
    sub_14021F390(34, ((unsigned __int8)(v4 & 7) << 12) + ((_DWORD)v3 << 15));
  }
  sub_14022E654(190, 0, 0);
  sub_14022E654(177, 0, a1);
  result = *(unsigned int *)off_14077D0F8;
  *(_DWORD *)off_14077D0F8 = v2;
  return result;
}

