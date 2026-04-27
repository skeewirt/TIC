// __Z11unit_isdarkv @ 0x106618 (92 bytes)
// WotL iOS - debug symbols

bool __fastcall unit_isdark()
{
  return RoundHelpFlag || Wtask_status(15) || wallgrayf || Wtask_status(6) != 0;
}

