#pragma once
#include<iostream>
#include<cstring>
#include<vector>
#include"GenericPlayer.h"

using namespace std;

class House : public GenericPlayer
{
public:

	House(const string &name);

	House();

	bool IsHitting() override;

	void FlipFirstCard();

	virtual ~House();

private:

};
