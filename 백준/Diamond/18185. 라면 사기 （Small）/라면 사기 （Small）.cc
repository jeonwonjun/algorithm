#include <iostream>
using namespace std;

int factory[10002];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> factory[i];
	}

	int price = 0;
	for (int i = 0; i < N; ++i)
	{
		int num;
		if (factory[i + 1] > factory[i + 2])
		{
			num = min(factory[i], factory[i + 1] - factory[i + 2]);
			price += num * 5;
			factory[i] -= num;
			factory[i + 1] -= num;
		}

		num = min(factory[i], min(factory[i + 1], factory[i + 2]));
		price += num * 7;
		factory[i] -= num;
		factory[i + 1] -= num;
		factory[i + 2] -= num;

		price += factory[i] * 3;
	}

	cout << price;
}