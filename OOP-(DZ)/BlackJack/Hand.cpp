#include"Hand.h"

	Hand::Hand()
	{}
	void Hand::Add(Card* newcard)
	{
		vec_cards.push_back(newcard);
	}
	void Hand::Clear()
	{
		for (auto card : vec_cards)
		{
			delete card;
		}
		vec_cards.clear();
	}
	int Hand::GetTotal() const
	{
		if (vec_cards.empty())
		{
			return 0;
		}
		else
		{
			int total = 0;
			const int MaxPoints = 11;
			const int NewAceValue = 11;
			for (unsigned int i = 0; i < unsigned(vec_cards.size()); i++)
			{
				total += vec_cards[i]->GetValue();
			}
			if (total <= MaxPoints && total > 21)
			{
				for (unsigned int i = 0; i < unsigned(vec_cards.size()); i++)
				{
					if (vec_cards[i]->GetValue() == Card::Ace)
					{
						total -= vec_cards[i]->GetValue();
						total += NewAceValue;
					}
				}
			}

			return total;
		}
	}

	Hand::~Hand() {}

