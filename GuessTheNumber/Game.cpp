#include "Game.h"

namespace std
{
	Game::Game(unsigned int _dig_cnt, bool open)
		: dig_cnt(min(max(_dig_cnt, (unsigned) 2), (unsigned) 10))
	{
		random_device rd;
		mt19937 rng(rd());
		uniform_int_distribution<int> uni;

		vector<uniform_int_distribution<int>::param_type> ranges;
		ranges.emplace_back(1, 9);
		for (unsigned int i = 1; i < dig_cnt; i++)
		{
			ranges.emplace_back(0, 9 - i);
		}

		list<int> available_digs;
		for (int i = 0; i < 10; i++)
		{
			available_digs.push_back(i);
		}

		for (unsigned int i = 0; i < dig_cnt; i++)
		{
			int r_order = uni(rng, ranges[i]);
			list<int>::iterator victim = available_digs.begin();
			advance(victim, r_order);
			digs.push_back(*victim);
			available_digs.erase(victim);
		}

		if (open)
		{
			cout << digs << endl;
		}

		over = false;
	}

	Game::~Game()
	{
	}

	Result Game::evaluate_guess(const vector<int>& guess, bool loud)
	{
		Result result(0, 0);

		if (valid_sequence(guess))
		{
			for (int i = guess.size() - 1; i >= 0; i--)
				if (guess[i] == digs[i])
					result.hit++;
				else if (exists(digs, guess[i]))
					result.miss_hit++;

			if (loud)
			{
				cout << '+' << result.hit << " -" << result.miss_hit << endl;
				if (result.hit == dig_cnt)
				{
					cout << "congratz!" << endl;
					over = true;
				}
			}
		}
		else
		{
			result.valid = false;
			cout << "invalid guess" << endl;
		}

		return result;
	}

	bool Game::is_over(void)
	{
		return over;
	}
}