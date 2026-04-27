// __Z22iOS_RESUME_SET_UNIT_SDP23IOS_RESUME_DATA_UNIT_SD24IOS_RESUME_DATACOPY_MODE @ 0x1300C4 (152 bytes)
// WotL iOS - debug symbols

int __fastcall iOS_RESUME_SET_UNIT_SD(int a1, int a2)
{
  iOS_Resume_DataCopy(a2, a1, &UnitSaveData, 0x1C00u);
  iOS_Resume_DataCopy(a2, a1 + 7168, PartyItem, 0x13Cu);
  iOS_Resume_DataCopy(a2, a1 + 7484, &ShopItem, 0x13Cu);
  iOS_Resume_DataCopy(a2, a1 + 7800, &FindItem, 0x80u);
  return iOS_Resume_DataCopy(a2, a1 + 7928, &WeaveInCommand, 1u);
}

