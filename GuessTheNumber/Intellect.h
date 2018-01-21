#pragma once

#include <vector>
#include <random>
#include <algorithm>
#include <random>

#include "Game.h"
#include "UsefulStuff.h"
#include "ProbabilityList.h"
#include "Result.h"

namespace std
{
	struct Information
	{
		vector<int> guess;
		Result result;

		Information(vector<int> g, Result r)
			: guess(g)
			, result(r)
		{
		}
	};

	enum Cleverness
	{
		DUMB
	};

	class Intellect
	{
	public:
		void take_turn(Game&);
		Intellect(unsigned int, bool = false);
		~Intellect();

	private:
		const unsigned int dig_cnt;
		const bool loud;

		mt19937 random_engine;
		ProbabilityList digit_existence_probs;
		vector<int> ultimate_guess;

		vector<Information> infos;

		bool guess_is_new(vector<int>& guess);
		bool ultimate_guess_ready();
		vector<int> make_guess(Cleverness);
	};
}