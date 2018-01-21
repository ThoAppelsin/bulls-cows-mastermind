#include "UsefulStuff.h"

namespace std
{
	bool valid_sequence(const vector<int>& seq)
	{
		if (seq.empty() || seq[0] == 0)
			return false;

		for (int i = seq.size() - 1; i >= 0; i--)
			for (int j = i - 1; j >= 0; j--)
				if (seq[i] == seq[j])
					return false;

		return true;
	}
}