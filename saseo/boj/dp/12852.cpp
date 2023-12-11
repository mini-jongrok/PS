#include <iostream>
#include <cstring>
using namespace std;
int n;
int cache[1000001];
int dp(int n);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << dp(n) << "\n";
	while (n >= 1)
	{
		cout << n << " ";
		int tmp = n - 1;
		if (n % 3 == 0 && cache[tmp] > cache[n/3]) tmp = n/3;
		if (n % 2 == 0 && cache[tmp] > cache[n/2]) tmp = n/2;
		n = tmp;
	}
	return 0;
}

int dp(int n)
{
	if (n == 1) return 0;
	int& ret = cache[n];
	if (ret != -1) return ret;

	ret = 1 + dp(n - 1);
	if (n % 3 == 0) ret = min(ret, 1 + dp(n / 3));
	if (n % 2 == 0) ret = min(ret, 1 + dp(n / 2));
	return ret;
}
