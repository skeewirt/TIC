// __Z21set_event_table_skillP5BWORKP3ACTP10TURN_TABLE @ 0x11E5D8 (228 bytes)
// WotL iOS - debug symbols, no obfuscation

int __fastcall set_event_table_skill(_BYTE *a1, int a2, int a3)
{
  char v6; // r11
  int v7; // r8
  int ability_turn; // r5
  _BYTE *v10; // [sp+0h] [bp-3Ch]
  char v11; // [sp+4h] [bp-38h]
  char v12; // [sp+8h] [bp-34h]
  char v13; // [sp+Ch] [bp-30h]
  _BYTE v14[20]; // [sp+10h] [bp-2Ch] BYREF

  v10 = a1 + 400;
  copyACTst(a1 + 400, v14);
  v6 = a1[426];
  v11 = a1[381];
  v12 = a1[479];
  v13 = a1[425];
  v7 = CalcForThink;
  CalcForThink = 2;
  if ( setskilldata(a2) == 1 )
    a1[381] = 0;
  ability_turn = set_event_table(a3, 3);
  if ( ability_turn != -1 )
    ability_turn = get_ability_turn((unsigned __int8)a1[428], (unsigned __int8)a1[381], a3);
  CalcForThink = v7;
  a1[426] = v6;
  a1[425] = v13;
  a1[479] = v12;
  adjust_entry_status(a1);
  a1[381] = v11;
  copyACTst(v14, v10);
  return ability_turn;
}

