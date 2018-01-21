#include "ProbabilityList.h"

#include <numeric>
#include <algorithm>

namespace std
{
	ProbabilityList::ProbabilityList(int n, double _total)
		: vector<double>(n, _total / n)
		, total(_total)
	{
	}

	ProbabilityList::~ProbabilityList(){ }

	void ProbabilityList::change(int n, double to)
	{
		if (to < 0.0 || to > 1.0)
			return;

		at(n) = to;
		normalize();
	}

	bool ProbabilityList::confident()
	{
		for (double prob : *this)
			if (prob > confidence_threshold && prob < (1 - confidence_threshold))
				return false;

		return true;
	}

	bool ProbabilityList::confident(unsigned int n)
	{
		return n < size() && (at(n) <= confidence_threshold || at(n) >= (1 - confidence_threshold));
	}

	vector<int> ProbabilityList::confidence_sorted()
	{
		vector<pair<int, double>> digit_prob_pairs(size());

		for (unsigned int i = 0; i < size(); i++)
		{
			digit_prob_pairs[i].first = i;
			digit_prob_pairs[i].second = at(i);
		}

		sort(digit_prob_pairs.begin(), digit_prob_pairs.end(), [](pair<int, double>& p1, pair<int, double>& p2)
		{
			return p1.second > p2.second;
		});

		vector<int> result(size());

		for (unsigned int i = 0; i < size(); i++)
			result[i] = digit_prob_pairs[i].first;

		return result;
	}

	void ProbabilityList::normalize()
	{
		double scale_factor = total / accumulate(begin(), end(), 0.0);
		for (double& p : *this)
		{
			p *= scale_factor;
			if (p > 1.0) p = 1.0;
		}
	}
}