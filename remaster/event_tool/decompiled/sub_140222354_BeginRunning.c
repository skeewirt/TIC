// sub_140222354_BeginRunning @ 0x140222354 (240 bytes)

__int64 sub_140222354()
{
  sub_1402222DC();
  word_140D3A4B0 = 1;
  if ( (unsigned int)sub_14021F310(0x1FDu) )
  {
    sub_140226690();
    xmmword_140D3A430 = xmmword_14077E490;
    LODWORD(qword_140D3A488) = 0;
    xmmword_140D3A440 = xmmword_14077E4A0;
    WORD2(qword_140D3A488) = 0;
    xmmword_140D3A468 = xmmword_14077E4B0;
    *(_QWORD *)&xmmword_140D3A458 = 0x100000001000LL;
    xmmword_140D3A478 = xmmword_14077E4C0;
    DWORD2(xmmword_140D3A458) = 4096;
    word_140D3A4C8 = 0;
    dword_142FE5EB8 = 0;
  }
  dword_141843948 = 0;
  if ( (unsigned int)sub_14021F310(0x27u) )
  {
    word_140D3A4C8 = 0;
    dword_142FE5EB8 = 0;
    sub_1403113C4(2, 0, 0, 0);
    sub_1403047E8(1, sub_140226714);
  }
  return sub_1401DB8C0(qword_143CD37F0, 0);
}

