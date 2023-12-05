#include <iostream>
using namespace std;
bool arr[31];
int main()
{
	for (int i = 1; i < 29; ++i)
	{
		int tmp = 0;
		cin >> tmp;
		arr[tmp] = true;
	}

	for (int i = 1; i <= 30; ++i)
		if (arr[i] == false) cout << i << "\n";
	return 0;
}
