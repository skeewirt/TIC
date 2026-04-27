// __Z10event_initv @ 0x5F404 (500 bytes)
// WotL iOS - debug symbols, no obfuscation

void *__fastcall event_init()
{
  int TPage; // r0
  char *v1; // r4
  void *result; // r0
  int v3; // r2
  _WORD *v4; // r3
  _BOOL2 v5; // r1
  int i; // [sp+4h] [bp-1Ch]

  event_init_memory();
  send_sttslinecol(byte_2932C4);
  makemessagestructure();
  event_init_system();
  event_init_light();
  TPage = GetTPage(0, 2, 960, 256);
  v1 = (char *)&half;
  SetDrawMode(&half, 0, 0, TPage, &fullround);
  SetTile(&unk_CFB5A8);
  byte_CFB5B0 = 0;
  byte_CFB5B1 = 0;
  byte_CFB5B2 = 0;
  SetSemiTrans(&unk_CFB5A8, 1);
  word_CFB5B4 = 135;
  word_CFB5BA = 50;
  word_CFB5B6 = 163;
  word_CFB5B8 = 246;
  for ( i = 0; i != 9; ++i )
  {
    SetTile((char *)&half + 20 * i + 36);
    v1[44] = 0;
    v1[45] = 0;
    v1[46] = 0;
    SetSemiTrans((char *)&half + 20 * i + 36, 1);
    *((_WORD *)v1 + 24) = 135;
    *((_WORD *)v1 + 27) = 1;
    *((_WORD *)v1 + 26) = 246;
    *((_WORD *)v1 + 25) = i + 154;
    SetTile((char *)&half + 20 * i + 216);
    v1[224] = 0;
    v1[225] = 0;
    v1[226] = 0;
    SetSemiTrans((char *)&half + 20 * i + 216, 1);
    *((_WORD *)v1 + 116) = 246;
    *((_WORD *)v1 + 114) = 135;
    *((_WORD *)v1 + 117) = 1;
    *((_WORD *)v1 + 115) = i + 213;
    v1 += 20;
  }
  result = memcpy(&unk_CFB724, &half, 0x18Cu);
  v3 = 0;
  v4 = &comtest;
  do
  {
    v5 = v3 >= 24 && (v3 <= 25 || v3 == 58);
    ++v3;
    v4[28] = v5;
    v4 += 32;
  }
  while ( v3 != 67 );
  return result;
}

