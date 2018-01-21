#pragma once

namespace std
{
	class Result
	{
	public:
		bool valid = true;
		int hit;
		int miss_hit;

		Result(int hit, int miss_hit);
		~Result();

		int found();
	};
}