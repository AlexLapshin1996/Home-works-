#include "HouseConstructor.h"

void HouseConstructor::SetHouse(House* PHouse)
{
	houseBilder_memb.SetHouse(PHouse);
}

House* HouseConstructor::ConstructSpacer()
{
	houseBilder_memb.BuildPart1();
	houseBilder_memb.BuildPart2();
	houseBilder_memb.BuildPart3();
	houseBilder_memb.BuildPart4();
	houseBilder_memb.BuildPart5();
	houseBilder_memb.BuildPart6();
	houseBilder_memb.BuildPart7();
	houseBilder_memb.BuildPart8();

	return houseBilder_memb.GetResult();
}

House* HouseConstructor::ConstructWithoutSpacer()
{
	houseBilder_memb.BuildPart1();
	houseBilder_memb.BuildPart2();
	houseBilder_memb.BuildPart3();
	houseBilder_memb.BuildPart4();
	houseBilder_memb.BuildPart5();
	houseBilder_memb.BuildPart6();
	houseBilder_memb.BuildPart7();

	return houseBilder_memb.GetResult();
}