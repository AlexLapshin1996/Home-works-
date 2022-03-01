#include"Game.h"


	Game::Game(const vector<string>& names)
	{
		vector<string> ::const_iterator itNames;
		for (itNames = names.begin(); itNames != names.end(); itNames++)
		{
			player_game.push_back(Player(*itNames));
		}
		srand(static_cast<unsigned int>(time(NULL)));
		deck_game.Populate();
		deck_game.Shuffle();
	}

	void Game::Play()
	{
		vector<Player>::iterator itPlayer;
		for (int i = 0; i < 2; i++)
		{
			for (itPlayer = player_game.begin(); itPlayer != player_game.end(); itPlayer++)
			{
				deck_game.Deal(*itPlayer);
			}
			deck_game.Deal(house_game);
		}
		house_game.FlipFirstCard();

		for (itPlayer = player_game.begin(); itPlayer != player_game.end(); itPlayer++)
		{
			cout << *itPlayer << endl;
		}
		cout << house_game << endl;

		for (itPlayer = player_game.begin(); itPlayer != player_game.end(); itPlayer++)
		{
			deck_game.AdditionalCards(*itPlayer);
		}
		house_game.FlipFirstCard();
		cout << endl << house_game;
		deck_game.AdditionalCards(house_game);
		if (house_game.IsBoosted())
		{
			for (itPlayer = player_game.begin(); itPlayer != player_game.end(); itPlayer++)
			{
				if (!(itPlayer->IsBoosted()))
				{
					itPlayer->Win();
				}
			}
		}
		else
		{
			for (itPlayer = player_game.begin(); itPlayer != player_game.end(); itPlayer++)
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

		for (itPlayer = player_game.begin(); itPlayer != player_game.end(); itPlayer++)
		{
			itPlayer->Clear();
		}
		house_game.Clear();
	}

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

	Game::~Game() {}

