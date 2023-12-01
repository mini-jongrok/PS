#include <iostream>
using namespace std;
int n, k;
int cache[1001][1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	cache[0][0] = 1;
	cache[0][1] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0 || j == i)
				cache[i][j] = 1;
			else
				cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j]) % 10007;
		}
	}
	cout << cache[n][k] << "\n";
	return 0;
}
