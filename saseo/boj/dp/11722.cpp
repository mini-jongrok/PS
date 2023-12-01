#include <iostream>
using namespace std;
int n;
int arr[1001];
int cache[1001];

void input();
void solve();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
	return 0;
}

void solve()
{
	int ret = 1;
	cache[n - 1] = 1;
	for (int i = n - 2; i >= 0; --i)
	{
		cache[i] = 1;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[i])
				cache[i] = max(cache[i], 1 + cache[j]);
		}
		ret = max(ret, cache[i]);
	}
	cout << ret << "\n";
}

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
}
