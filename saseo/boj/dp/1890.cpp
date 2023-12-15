#include <iostream>
#include <cstring>
using namespace std;
int n;
int board[101][101];
uint64_t cache[101][101];
void input();
uint64_t dp(int i, int j);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	input();
	cout << dp(0, 0) << "\n";
	return 0;
}

uint64_t dp(int i, int j)
{
	if (i >= n || j >= n) return 0;
	if (board[i][j] == 0 && i == n -1 && j == n - 1) return 1;
	else if (board[i][j] == 0) return 0;
	uint64_t & ret = cache[i][j];
	if (ret != -1) return ret;
	int distance = board[i][j];
	ret = dp(i + distance, j) + dp(i, j + distance);
	return ret;
}

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
}
