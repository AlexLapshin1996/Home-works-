#pragma once
#include<iostream>
#include<algorithm>
#include"GenericPlayer.h"
#include"Hand.h"

using namespace std;

class Deck : public Hand
{
public:
	Deck();

	void Populate();

	void Shuffle();

	void Deal(Hand& hand_h);

	void AdditionalCards(GenericPlayer& generic_player);

	virtual ~Deck();
};

