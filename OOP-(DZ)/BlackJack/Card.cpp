#include"Card.h"



	Card:: Card(CardMeaning value, Suit suit, bool position) : znachenie(value), masti(suit), cardPosition(position)
	{}

	bool Card::Flip()
	{
		cardPosition = false;
		return cardPosition;
	}

	int Card::GetValue()
	{
		int value = 0;
		if (cardPosition)
		{
			value = znachenie;
			if (value > 10)
			{
				value = 10;
			}
		}
		return value;
	}

	 ostream& operator << (ostream& abc, const Card& card)

	 {
		const string CardValue[] = { "0","Ace","One","Two","Three","Four","Five","Six","Seven","Eignt","Nine","Ten","Jack","Queen","King" };
		const string Suits[] = { "Diamonds","Hearts","Spades","Clubs" };
		if (card.cardPosition == true)
		{
			cout << CardValue[card.znachenie] << " " << Suits[card.masti];
		}
		else
		{
			cout << "XX";
		}
		return abc;
	  }

	 Card::~Card() {}
	

