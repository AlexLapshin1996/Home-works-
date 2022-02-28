#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

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
		cout <<p_Name<<" do you need another card? (Y or N) :" << endl;
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
	House(const string &name ) : GenericPlayer(name) {}
	House()
	{
		p_Name = "Dealer";
	}
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

class Deck : public Hand
{
public:
	Deck()
	{
		vec_cards.reserve(52);
		Populate();
	}
	void Populate()
	{
		Clear();
		for (int suit = Card::Diamonds; suit <= Card::Spades; suit++)
		{
			for (int cardValue = Card::Ace; cardValue <= Card::King; cardValue++)
			{
				Add(new Card(static_cast<Card::CardMeaning>(cardValue),static_cast<Card::Suit>(suit)));
			}
		}
	}

	void Shuffle()
	{
		random_shuffle(vec_cards.begin(), vec_cards.end());
	}

	void Deal(Hand &hand_h)
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

	void AdditionalCards(GenericPlayer &generic_player)
	{
		while (!(generic_player.IsBoosted()) && generic_player.IsHitting())
		{
			Deal(generic_player);
			cout << generic_player << endl;
			if (generic_player.IsBoosted())
			{
				generic_player.Bust();
			}
		}
	}

	virtual ~Deck(){}
};

class Game
{
public:
	Game(const vector<string>& names)
	{
		vector<string> ::const_iterator itNames;
		for (itNames  = names.begin();itNames != names.end();itNames ++)
		{
			player_game.push_back(Player(*itNames));
		}
		srand(static_cast<unsigned int>(time(NULL)));
		deck_game.Populate();
		deck_game.Shuffle();
	}

	void Play()
	{
		vector<Player>::iterator itPlayer;
		for (int i = 0; i < 2; i++)
		{
			for (itPlayer  = player_game.begin();itPlayer!=player_game.end();itPlayer++)
			{
				deck_game.Deal(*itPlayer);
			}
			deck_game.Deal(house_game);
		}
		house_game.FlipFirstCard();

		for (itPlayer  = player_game.begin();itPlayer!=player_game.end();itPlayer++)
		{
			cout << *itPlayer << endl;
		}
		cout << house_game << endl;

		for (itPlayer = player_game.begin();itPlayer!=player_game.end();itPlayer++)
		{
			deck_game.AdditionalCards(*itPlayer);
		}
		house_game.FlipFirstCard();
		cout << endl << house_game;
		deck_game.AdditionalCards(house_game);
		if (house_game.IsBoosted())
		{
			for (itPlayer = player_game.begin();itPlayer!=player_game.end();itPlayer++)
			{
				if (!(itPlayer->IsBoosted()))
				{
					itPlayer->Win();
				}
			}
		}
		else
		{
			for (itPlayer = player_game.begin();itPlayer != player_game.end();itPlayer++)
			{
				if (!(itPlayer->IsBoosted()))
				{
					if (itPlayer->GetTotal() > house_game.GetTotal())
					{
						itPlayer->Win();
					}
					else if (itPlayer->GetTotal() < house_game.GetTotal())
					{
						itPlayer->Lose();
					}
					else
					{
						itPlayer->Push();
					}
				}
			}
		}

		for (itPlayer = player_game.begin();itPlayer!=player_game.end();itPlayer++)
		{
			itPlayer->Clear();
		}
		house_game.Clear();
	}
	
	~Game(){}

private:
	Deck deck_game;
	House house_game;
	vector<Player> player_game;
};

void PlayAgain(Game& newGame)
{
	char answer = 'y';
	while (answer == 'y' || answer == 'Y')
	{
		newGame.Play();
		cout << "Do you want play again?" << endl;
		cout << "(Y) or (N)" << endl;
		cin >> answer;
		cout << "\n";
		if (answer == 'n' || answer == 'N')
		{
			cout << "Thanks you for playing BlackJack,goodbye" << endl;
		}
	}
}


int main()
{
	
	int NumberofPlayers = 0;
	while (NumberofPlayers < 1 || NumberofPlayers > 7 )
	{
		cout << "How many players will play game,1 - 7 players?" << endl;
		while (!(cin>>NumberofPlayers))
		{
			cin.clear();
			while (cin.get() !='\n')
			{
				
			}
			cout << "Error,please enter count of players" << endl;
			cout << "How many players?" << endl;
		}
		
	}
	vector<string> names;
	string name;

	for (int i = 0; i < NumberofPlayers; i++)
	{
		cout << "Enter name of player : ";
		cin >> name;
		names.push_back(name);
	}
	cout << "\n\n";

	Game newGame(names);

	PlayAgain(newGame);
	
}


