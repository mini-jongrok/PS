#include <iostream>
#include <cstring>
using namespace std;
int m, n;
int map[501][501];
int cache[501][501];
void input();
int dp(int r, int c);
int main()
{
	memset(cache, -1, sizeof(cache));
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	cout << dp(0,0) << "\n";
	return 0;
}

int dp(int r, int c)
{
	if (r < 0 || c < 0 || r >= m || c >= n) return 0;
	if (r == m - 1 && c == n - 1) return 1;
	int & ret = cache[r][c];
	if (ret != -1) return ret;
	// 상하좌우, 움직일 수 있으면 움직이기.
	ret = 0;
	if (r > 0 && map[r - 1][c] < map[r][c]) ret += dp(r - 1, c);
	if (c > 0 && map[r][c - 1] < map[r][c]) ret += dp(r, c - 1);
	if (r < m - 1 && map[r + 1][c] < map[r][c]) ret += dp(r + 1, c);
	if (c < n - 1 && map[r][c + 1] < map[r][c]) ret += dp(r, c + 1);
	return ret;
}

void input()
{
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
}
