#include <iostream>
using namespace std;
int main(void)
{
	int Max=-1, Min=1001;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (Max < num)
			Max = num;
		if (Min > num)
			Min = num;
	}
	cout << Max - Min;

}