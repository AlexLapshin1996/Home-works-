#include "HouseBilder.h"


void HouseBilder::SetHouse(House* PHouse)
{
	PHouse_memb = PHouse;
}

House* HouseBilder::GetResult()
{
	return PHouse_memb;
}