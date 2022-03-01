#pragma once
#include<iostream>
#include<cstring>
#include<vector>
#include"Card.h"

using namespace std;

class Hand
{
public:

	Hand();

	void Add(Card* newcard);

	void Clear();
	int GetTotal() const;

	virtual ~Hand();

protected:
	vector<Card*> vec_cards;
};

