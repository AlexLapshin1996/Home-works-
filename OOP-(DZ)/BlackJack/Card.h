#pragma once
#include<iostream>
#include<string>

using namespace std;

class Card
{
public:

	enum Suit
	{
		Diamonds,
		Hearts,
		Clubs,
		Spades
	};

	enum CardMeaning
	{
		Ace = 1,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King
	};

	Card(CardMeaning value, Suit suit, bool position = 1);

	bool Flip();

	int GetValue();

	friend ostream& operator<<(ostream& abc, const Card& card);

	virtual ~Card();

private:
	Suit masti;
	CardMeaning znachenie;
	bool cardPosition;

};

