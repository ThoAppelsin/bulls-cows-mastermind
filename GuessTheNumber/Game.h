#pragma once

#include <algorithm>
#include <random>
#include <vector>
#include <list>
#include <iostream>

#include "UsefulStuff.h"
#include "Result.h"

namespace std
{
	class Game
	{
	public:
		const unsigned int dig_cnt;

		Game(unsigned int, bool = false);
		~Game();
		Result evaluate_guess(const vector<int>&, bool = true);
		bool is_over(void);

	private:
		vector<int> digs;
		bool over;
	};
}