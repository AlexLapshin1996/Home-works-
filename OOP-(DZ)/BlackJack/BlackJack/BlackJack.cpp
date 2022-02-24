#include <iostream>
#include<string>
#include<vector>

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

	Card(CardMeaning value,Suit suit,bool position = true) : znachenie(value),masti(suit),cardPosition(position)
	{}
	
	bool Flip()
	{
		cardPosition = false;
		return cardPosition;
	}

	int getValue()
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

	friend ostream& operator << (ostream& abb,const Card& card)
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
		return abb;
	}
	~Card()
	{

	}

private:
	Suit masti;
	CardMeaning znachenie;
	bool cardPosition;

};

class Hand
{
protected:
	vector<Card*> vec_cards;

public:
	Hand()
	{}
	void Add(Card* newcard)
	{
		vec_cards.push_back(newcard);
	}
	void Clear()
	{
		for(auto card : vec_cards)
		{
			delete card;
		}
		vec_cards.clear();
	}
	int GetTotal() const
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
				total += vec_cards[i]->getValue();
			}
			if (total <= MaxPoints && total > 21)
			{
				for (unsigned int i = 0; i < unsigned(vec_cards.size()); i++)
				{
					if (vec_cards[i]->getValue() == Card::Ace)
					{
						total -= vec_cards[i]->getValue();
						total += NewAceValue;
					}
				}
			}

			return total;
		}
	}

	~Hand()
	{}

};

class GenericPlayer : public Hand
{
public:
	GenericPlayer(const string& name) : p_Name(name) {}
	GenericPlayer()
	{}
	virtual bool IsHitting() =0;
	bool IsBoosted()
	{
		return (GetTotal() > 21);
	}
	void Bust()
	{
		cout << p_Name << " bust " << endl;
	}
	friend ostream& operator<<(ostream& os, const GenericPlayer& genericPlayer)
	{
		os << genericPlayer.p_Name << ":\t";
		vector<Card*>::const_iterator itCard;
		if (!genericPlayer.vec_cards.empty())
		{
			for (itCard = genericPlayer.vec_cards.begin();itCard != genericPlayer.vec_cards.end();++itCard)
			
			{
				os << *(*itCard) << "\t";
			}
			if (genericPlayer.GetTotal() != 0)
			{
				cout << "(" << genericPlayer.GetTotal() << ")";
			}
			else
			{
				os << "<Empty>";
			}
			return os;
		}
	}
	virtual ~GenericPlayer()
	{}

protected:
	string p_Name;

};

class Player : public GenericPlayer
{
public:
	Player(const string& name) : GenericPlayer(name)
	{
		p_Name = name;
	}
	void Win() const
	{
		cout << p_Name << " - you win" << endl;
	}
	void Lose() const
	{
		cout << p_Name << " - you lose" << endl;
	}
	void Push() const
	{
		cout << p_Name << " - you have a draw" << endl;
	}
	bool IsHitting() override
	{
		char answ;
		cout << p_Name << " do you need another card? (Y or N) :" << endl;
		cin >> answ;
		if (answ == 'Y' || answ == 'y')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	virtual ~Player()
	{}

};

class House : public GenericPlayer
{
public:
	House(const string&name = "Dealer"){}
	bool IsHitting() override
	{
		if(GetTotal() <=16)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void FlipFirstCard()
	{
		if(vec_cards.empty() == false)
		{
			vec_cards[0]->Flip();
		}
		else
		{
			cout << "All cards is flipped " << endl;
		}
	}
	virtual ~House()
	{}

private:

};





int main()
{

	
    
}


