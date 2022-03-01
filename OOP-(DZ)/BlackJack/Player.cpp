#include"Player.h"


	Player:: Player(const string& name) : GenericPlayer(name)
	{
		p_Name = name;
	}
	void Player::Win() const
	{
		cout << p_Name << " - you win" << endl;
	}
	void Player::Lose() const
	{
		cout << p_Name << " - you lose" << endl;
	}
	void Player::Push() const
	{
		cout << p_Name << " - you have a draw" << endl;
	}

	bool Player::IsHitting() 
	{
		char answ;
		cout << p_Name << " do you need another card? (Y or N) :" << endl;
		cin >> answ;
		cout << "\n";
		if (answ == 'Y' || answ == 'y')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Player::~Player() {}
