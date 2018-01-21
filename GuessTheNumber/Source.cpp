#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
#include <iterator>

#include "Game.h"
#include "Intellect.h"

using namespace std;

vector<int> let_guess(const int n)
{
	vector<int> guess;
	for (int i = n; i > 0; i--)
	{
		char a;
		cin >> a;
		int b = a - '0';

		guess.push_back(b);
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return guess;
}

void human_player(Game& game)
{
	while (!game.is_over())
	{
		vector<int> guess = let_guess(game.dig_cnt);
		game.evaluate_guess(guess);
	}
}

void alg_player(Game& game)
{
	Intellect intellect(game.dig_cnt, true);

	while (!game.is_over())
	{
		intellect.take_turn(game);
	}
}

int main()
{
	Game game(4, true);

	// human_player(game);
	alg_player(game);
	
	return 0;
}