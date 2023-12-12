#include <iostream>
using namespace std;
int n, last;
int mod = 1000000009;
int m[1000000];
long long cache[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> m[i];
		last = max(last, m[i]);
	}

	cache[0] = 1;
	cache[1] = 1;
	cache[2] = 2;
	for (int i = 3; i <= last; ++i)
		cache[i] = (cache[i - 1] + cache[i - 2] + cache[i - 3]) % mod;
	for (int i = 0; i < n; ++i)
		cout << cache[m[i]] << "\n";
	return 0;
}
