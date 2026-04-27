// __Z16event_init_lightv @ 0x5D874 (168 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall event_init_light()
{
  _DWORD *v0; // r0
  int v1; // r1
  int v2; // r2
  int v3; // r3
  int v4; // r1
  int v5; // r2
  int v6; // r3
  _DWORD *v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  _DWORD *v11; // lr
  int result; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3

  lightrot = 0;
  word_1200ECE = 0;
  word_1200ED0 = 0;
  lightscale = 4096;
  dword_1200ED8 = 4096;
  dword_1200EDC = 4096;
  v0 = (_DWORD *)ASHURA_SetMatrix(98, 0, 0, 0);
  v1 = v0[1];
  v2 = v0[2];
  v3 = v0[3];
  lightsrc = *v0;
  unk_1200E90 = v1;
  unk_1200E94 = v2;
  unk_1200E98 = v3;
  v4 = v0[5];
  v5 = v0[6];
  v6 = v0[7];
  unk_1200E9C = v0[4];
  unk_1200EA0 = v4;
  unk_1200EA4 = v5;
  unk_1200EA8 = v6;
  v7 = (_DWORD *)ASHURA_SetMatrix(97, v0, v0, 0);
  v8 = v7[1];
  v9 = v7[2];
  v10 = v7[3];
  v11 = v7 + 4;
  lightstr = *v7;
  unk_1200EB0 = v8;
  unk_1200EB4 = v9;
  unk_1200EB8 = v10;
  result = v7[4];
  v13 = v11[1];
  v14 = v11[2];
  v15 = v11[3];
  unk_1200EBC = *v11;
  unk_1200EC0 = v13;
  unk_1200EC4 = v14;
  unk_1200EC8 = v15;
  return result;
}

