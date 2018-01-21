#include "Intellect.h"

namespace std
{
	vector<unsigned int> distinct_by_two_digits_swapped(const vector<int>& g1, const vector<int>& g2)
	{
		vector<unsigned int> distinct_dig_orders;

		if (g1.size() != g2.size())
			return distinct_dig_orders;

		for (unsigned int i = 0; i < g1.size(); i++)
			if (g1[i] != g2[i])
				distinct_dig_orders.emplace_back(i);

		if (distinct_dig_orders.size() != 2
			|| g1[distinct_dig_orders[0]] != g2[distinct_dig_orders[1]]
			|| g1[distinct_dig_orders[1]] != g2[distinct_dig_orders[0]])
			distinct_dig_orders.clear();

		return distinct_dig_orders;
	}

	bool Intellect::ultimate_guess_ready()
	{
		for (int i : ultimate_guess)
			if (i < 0 || i > 9)
				return false;

		return true;
	}

	bool Intellect::guess_is_new(vector<int>& guess)
	{
		if (guess.size() != dig_cnt)
			return false;

		for (Information& info : infos)
			if (info.guess == guess)
				return false;

		return true;
	}

	vector<int> Intellect::make_guess(Cleverness c)
	{
		vector<int> guess;

		switch (c)
		{
			case DUMB:
				if (!infos.empty())
				{
					Information& last_info = infos.back();

					if (!digit_existence_probs.confident())
					{
						if (last_info.result.found() == 0)
							for (int i : last_info.guess)
								digit_existence_probs.change(i, 0.0);
					}
					else
					{
						for (unsigned int i = 0; i < infos.size(); i++)
							for (unsigned int j = i + 1; j < infos.size(); j++)
								if (abs(infos[i].result.hit - infos[j].result.hit) == 2)
								{
									vector<unsigned int> distinct_dig_orders =
										distinct_by_two_digits_swapped(infos[i].guess, infos[j].guess);

									if (!distinct_dig_orders.empty())
									{
										vector<int>& succ_guess = infos[infos[i].result.hit > infos[j].result.hit ? i : j].guess;

										ultimate_guess[distinct_dig_orders[0]] = succ_guess[distinct_dig_orders[0]];
										ultimate_guess[distinct_dig_orders[1]] = succ_guess[distinct_dig_orders[1]];

										if (ultimate_guess_ready())
											return ultimate_guess;
									}
								}
					}
				}

				while (!guess_is_new(guess))
				{
					guess.clear();

					if (!digit_existence_probs.confident())
					{
						vector<int> confidence_sorted_digs = digit_existence_probs.confidence_sorted();
						unsigned int sz = confidence_sorted_digs.size();
						unsigned int confident_absence_index = sz - 1;

						for (; digit_existence_probs.confident(confidence_sorted_digs[confident_absence_index]); confident_absence_index--)
							if (confident_absence_index > sz - dig_cnt)
								guess.emplace_back(confidence_sorted_digs[confident_absence_index]);

						while (guess.size() < dig_cnt)
						{
							int r_dig = confidence_sorted_digs[uniform_int_distribution<>(0, confident_absence_index)(random_engine)];
							if (!exists(guess, r_dig))
								guess.emplace_back(r_dig);
						}

						if (guess[0] == 0)
							swap(guess[0], guess[1]);
					}
					else
					{
						vector<int> confidence_sorted_digs = digit_existence_probs.confidence_sorted();

						for (unsigned int i = 0; i < dig_cnt; i++)
							guess.emplace_back(confidence_sorted_digs[i]);

						shuffle(guess.begin(), guess.end(), random_engine);

						if (guess[0] == 0)
							swap(guess[0], guess[1]);
					}
				}

				break;
			default:
				break;
		}

		return guess;
	}

	void Intellect::take_turn(Game& game)
	{
		vector<int> guess = make_guess(DUMB);

		if (loud) cout << "guessing... " << guess << endl;
		Result result = game.evaluate_guess(guess);

		if (result.valid)
			infos.emplace_back(guess, result);
	}

	Intellect::Intellect(unsigned int _dig_cnt, bool _loud)
		: dig_cnt(_dig_cnt)
		, loud(_loud)
		, digit_existence_probs(10, dig_cnt)
		, ultimate_guess(dig_cnt, -1)
		, random_engine(random_device()())
	{
	}

	Intellect::~Intellect()
	{
	}
}