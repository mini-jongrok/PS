#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int cache[1030][1030];
void input();
void solve();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(cache, 0, sizeof(cache));
	input();
	solve();
	return 0;
}

void solve()
{
	for (int i = 0; i < m; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
        int ret =  cache[x2][y2] - cache[x1 - 1][y2] - cache[x2][y1 - 1] + cache[x1 - 1][y1 - 1];
		cout << ret << "\n";
	}
}

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> cache[i][j];
			cache[i][j] += - cache[i - 1][j - 1] + cache[i - 1][j] + cache[i][j - 1];
		}
	}
}
