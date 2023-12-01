#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define INT_MAX 2147483647
using namespace std;
int n, k;
vector<int> coin;
int cache[10001];
void input();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	sort(coin.begin(), coin.end());
	cache[0] = 0;
	for (int i = 1; i <= k; ++i)
	{
		cache[i] = INT_MAX;
		for (int c = 0; c < n; ++c)
		{
			if (i - coin[c] < 0) break;
			int tmp = 1 + cache[i - coin[c]];
			if (tmp > 0) cache[i] = min(cache[i], tmp);
		}
		if (cache[i] == INT_MAX) cache[i] = -1;
	}
	cout << cache[k] << "\n";
	return 0;
}

void input()
{
	cin >> n >> k;
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		coin.push_back(tmp);
	}
}
