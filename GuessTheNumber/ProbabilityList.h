#pragma once

#include <vector>

namespace std
{
	class ProbabilityList : public vector<double>
	{
	public:
		static constexpr double confidence_threshold = 0.01;

		ProbabilityList(int n, double total);
		~ProbabilityList();

		void change(int n, double to);
		bool confident();
		bool confident(unsigned int n);
		vector<int> confidence_sorted();

	private:
		const double total;

		void normalize();
	};
}