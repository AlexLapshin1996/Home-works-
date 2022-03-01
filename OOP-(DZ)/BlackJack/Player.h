#pragma once
#include<iostream>
#include<cstring>

#include"GenericPlayer.h"

using namespace std;

class Player : public GenericPlayer
{
public:

	Player(const string &name);

	void Win() const;

	void Lose() const;

	void Push() const;;

	bool IsHitting() override;

	virtual ~Player();

};
