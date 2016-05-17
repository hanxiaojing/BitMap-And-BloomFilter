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
		//_a���ٶ�һ���ռ䣬��size=36/32=1,��Ҫ����ռ���ܷ���
		_a.resize((size >> 5) + 1);
	}


	void Set(size_t x)
	{
		//size_t index = x / 32;
		size_t index = (x >> 5);
		size_t num = x % 32;

		//if(!(_a[index] & (1 << num))��ʾ�ö�����λ�����ڣ����λ�������ó�1
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

		//��λ�����򽫸�λ��������Ϊ0
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