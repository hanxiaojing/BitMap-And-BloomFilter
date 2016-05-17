#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <string>

#include "Common.h"
#include "BitMap.h"

template<class T=string,
		class HashFunc1 = __HashFunc1<T>,
		class HashFunc2 = __HashFunc2<T>,
		class HashFunc3 = __HashFunc3<T>,
		class HashFunc4 = __HashFunc4<T>,
		class HashFunc5 = __HashFunc5<T>>
class BloomFilter
{
public:

	BloomFilter(size_t capacity =0)
	{
		_capacity = _GetnewSize(capacity);
		_bm.Resize(capacity);
	}


	void Set(const T& key)
	{
		size_t index1 = HashFunc1()(key);
		size_t index2 = HashFunc2()(key);
		size_t index3 = HashFunc3()(key);
		size_t index4 = HashFunc4()(key);
		size_t index5 = HashFunc5()(key);
		_bm.Set(index1%_capacity);
		_bm.Set(index2%_capacity);
		_bm.Set(index3%_capacity);
		_bm.Set(index4%_capacity);
		_bm.Set(index5%_capacity);

	}


	bool Test(const T& key)
	{
		size_t index1 = HashFunc1()(key);
		if (!(_bm.Test(index1% _capacity)))
		{
			return false;
		}

		size_t index2 = HashFunc2()(key);
		if (!(_bm.Test(index2% _capacity)))
		{
			return false;
		}

		size_t index3 = HashFunc3()(key);
		if (!(_bm.Test(index3% _capacity)))
		{
			return false;
		}

		size_t index4 = HashFunc4()(key);
		if (!(_bm.Test(index4% _capacity)))
		{
			return false;
		}

		size_t index5 = HashFunc5()(key);
		if (!(_bm.Test(index5% _capacity)))
		{
			return false;
		}

		return true;
	}
private:
	BitMap _bm;
	size_t _capacity;//��¡������������
};



void TestBloomFilter()
{
	BloomFilter<> bf(100);
	bf.Set("Just Do IT!");
	bf.Set("��¡������");
	bf.Set("https://mail.google.com/mail/#inbox");


	cout << "Is exist?  :" << bf.Test("���Թ���ʦ") << endl;
	cout << "Is exist?  :" << bf.Test("��������ʦ") << endl;
	cout << "Is exist?  :" << bf.Test("IT") << endl;
	cout << "Is exist?  :" << bf.Test("��¡������") << endl;
	cout << "Is exist?  :" << bf.Test("BloomFilter") << endl;
	cout << "Is exist?  :" << bf.Test("https://mail.google.com/mail/#inbox") << endl;
	cout << "Is exist?  :" << bf.Test("https://mail.google.com/mail/#inbox111111") << endl;

}


int main()
{
	TestBloomFilter();
	system("pause");
	return 0;
}