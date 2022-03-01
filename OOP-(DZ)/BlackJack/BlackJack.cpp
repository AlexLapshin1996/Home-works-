#include"Card.h"
#include"Hand.h"
#include"GenericPlayer.h"
#include"House.h"
#include"Player.h"
#include"Deck.h"
#include"Game.h"

using namespace std;

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


