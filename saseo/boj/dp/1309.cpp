#include <iostream>
#include <cstring>
using namespace std;
int n;
int mod = 9901;
int cache[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	cin >> n;
	cache[0] = 1;
	cache[1] = 3;
	for (int i = 2; i <= n; ++i)
		cache[i] = (cache[i - 2] + (2 * cache[i - 1])) % mod;
	cout << cache[n] << "\n";
	return 0;
}
