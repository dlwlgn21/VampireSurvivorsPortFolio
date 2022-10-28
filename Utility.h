#pragma once
#include <cassert>

int yaClamp(int val, int _min, int _max)
{
	assert(_max > _min);
	int ret = val;
	if (ret <= _min)
	{
		ret = _min;
	}

	if (ret >= _max)
	{
		ret = _max;
	}
	return ret;
}
