#pragma once
#include"House.h"

class HouseBilder
{
public:
	void SetHouse(House* PHouse);

	House* GetResult();

	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual void BuildPart3() = 0;
	virtual void BuildPart4() = 0;
	virtual void BuildPart5() = 0;
	virtual void BuildPart6() = 0;
	virtual void BuildPart7() = 0;
	virtual void BuildPart8() = 0;

protected:
	House* PHouse_memb;
};

