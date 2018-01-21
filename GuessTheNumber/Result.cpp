#include "Result.h"

namespace std
{
	Result::Result(int _hit, int _miss_hit)
		: hit(_hit)
		, miss_hit(_miss_hit)
	{
	}

	Result::~Result()
	{
	}

	int Result::found()
	{
		return hit + miss_hit;
	}
}