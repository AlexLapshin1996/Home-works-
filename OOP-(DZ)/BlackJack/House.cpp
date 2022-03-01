#include"House.h"


	House::House(const string& name) : GenericPlayer(name) {}
	House::House()
	{
		p_Name = "Dealer";
	}
	bool House::IsHitting() 
	{
		if (GetTotal() <= 16)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void House::FlipFirstCard()
	{
		if (vec_cards.empty() == false)
		{
			vec_cards[0]->Flip();
		}
		else
		{
			cout << "All cards is flipped " << endl;
		}
	}
	House::~House()
	{}

;