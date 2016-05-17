#ifndef __BITMAP_H__
#define __BITMAP_H__
#include<iostream>
using namespace std;

#include<vector>

class BitMap
{
public:
	BitMap(size_t size = 0)
		:_size(0)
	{
		//_a开辟多一个空间，如size=36/32=1,需要两块空间才能放下
		_a.resize((size >> 5) + 1);
	}


	void Set(size_t x)
	{
		//size_t index = x / 32;
		size_t index = (x >> 5);
		size_t num = x % 32;

		//if(!(_a[index] & (1 << num))表示该二进制位不存在，则该位二进制置成1
		if (!(_a[index] & (1 << num)))
		{
			_a[index] |= (1 << num);
			++_size;
		}
	}


	void Reset(size_t x)
	{
		//size_t index = x / 32;
		size_t index = x >> 5;
		size_t num = x % 32;

		//该位存在则将该位二进制置为0
		if (_a[index] & (1 << num))
		{
			_a[index] &= ~(1 << num);
			--_size;
		}
	}


	bool Test(size_t x)
	{
		//size_t index = x / 32;
		size_t index = x >> 5;
		size_t num = x % 32;
		if (_a[index] & (1 << num))
		{
			return true;
		}
		return false;
	}


	void Resize(size_t size)
	{
		_a.resize(size);
	}
private:
	vector<size_t> _a;
	size_t _size;
};

#endif //__BITMAP_H__