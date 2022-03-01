#include"Deck.h"

	Deck::Deck()
	{
		vec_cards.reserve(52);
		Populate();
	}
	void Deck::Populate()
	{
		Clear();
		for (int suit = Card::Diamonds; suit <= Card::Spades; suit++)
		{
			for (int cardValue = Card::Ace; cardValue <= Card::King; cardValue++)
			{
				Add(new Card(static_cast<Card::CardMeaning>(cardValue), static_cast<Card::Suit>(suit)));
			
			}
		}
	}

	void Deck::Shuffle()
	{
		random_shuffle(vec_cards.begin(), vec_cards.end());
	}

	void Deck::Deal(Hand& hand_h)
	{
		if (!vec_cards.empty())
		{
			hand_h.Add(vec_cards.back());
			vec_cards.pop_back();
		}
		else
		{
			cout << "The deck is out of cards" << endl;
		}
	}

	void Deck::AdditionalCards(GenericPlayer& generic_player)
	{
		while (!(generic_player.IsBoosted()) && generic_player.IsHitting())
		{
			Deck::Deal(generic_player);
			cout << generic_player << endl;
			if (generic_player.IsBoosted())
			{
				generic_player.Bust();
			}
		}
	}

	Deck::~Deck() {}
