#include <iostream>
using namespace std;
int n;
int cache[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cache[0] = 0;
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 3;
	for (int i = 4; i <= n; ++i)
	{
		int tmp = 2147483647;
		for (int root = 2; root * root <= i; ++root)
			tmp = min(tmp, 1 + cache[i - (root * root)]);
		cache[i] = tmp;
	}
	cout << cache[n] << "\n";
	return 0;
}
