#pragma once

#include"House.h"
#include"HouseBilderOne.h"

class HouseConstructor
{
public:
	HouseConstructor()
	{
		HouseBilderOne houseBilder;
	}
	
	void SetHouse(House* PHouse);
	House* ConstructSpacer();
	House* ConstructWithoutSpacer();

private:
	HouseBilderOne houseBilder_memb;
};

