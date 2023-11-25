#include <iostream>
#include <cstring>

using namespace std;

int cache[20];

int dp(int n);
int main()
{
	int T;
	cin >> T;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < T; ++i)
	{
		int tmp = 0;
		cin >> tmp;
		cout << dp(tmp) << "\n";
	}
	return 0;
}

int dp(int n)
{
	if (n < 0) return 0;
	if (n < 2) return 1;

	int& ret = cache[n];
	if (ret != -1) return ret;

	ret = dp(n - 3) + dp(n - 2) + dp(n - 1);
	return ret;
}
