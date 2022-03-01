#include"GenericPlayer.h"

	GenericPlayer::GenericPlayer(const string& name) : p_Name(name) {}

	GenericPlayer:: GenericPlayer() {}

	bool GenericPlayer::IsBoosted()

	{
		return (GetTotal() > 21);
	}

	void GenericPlayer::Bust()

	{
		cout << p_Name << " bust " << endl;
	}

	ostream& operator<<(ostream& os, const GenericPlayer& genericPlayer)
	{
		os << genericPlayer.p_Name << ":\t";
		vector<Card*>::const_iterator itCard;
		if (!genericPlayer.vec_cards.empty())
		{
			for (itCard = genericPlayer.vec_cards.begin(); itCard != genericPlayer.vec_cards.end(); ++itCard)

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

	GenericPlayer::~GenericPlayer() {}

	

