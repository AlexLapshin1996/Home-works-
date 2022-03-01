#pragma once
#include<iostream>
#include"Deck.h"
#include"House.h"
#include"Player.h"

class Game
{
public:
	Game(const vector<string> &names);

	void Play();

	~Game();

private:

	Deck deck_game;
	House house_game;
	vector<Player> player_game;
};

void PlayAgain(Game& newGame);