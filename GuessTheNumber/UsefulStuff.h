#pragma once

#include <vector>
#include <iostream>

namespace std
{
	bool valid_sequence(const vector<int>&);

	template<class T>
	inline bool exists(const vector<T>&, const T&);

	template<class T>
	void remove(vector<T>&, const T&);

	template<class T>
	void limit_val(T&, const T&&, const T&&);

	template<class T>
	ostream& operator << (ostream&, const vector<T>&);

	template<class T>
	inline bool exists(const vector<T>& v, const T& val)
	{
		return find(v.begin(), v.end(), val) != v.end();
	}

	template<class T>
	void remove(vector<T>& v, const T& val)
	{
		v.erase(remove(v.begin(), v.end(), val), v.end());
	}

	template<class T>
	void limit_val(T& val, const T&& min, const T&& max)
	{
		if (val > max)
		{
			val = max;
		}

		if (val < min)
		{
			val = min;
		}
	}

	template<class T>
	ostream& operator << (ostream& os, const vector<T>& v)
	{
		for (T dig : v)
		{
			os << dig << ' ';
		}

		return os;
	}
}