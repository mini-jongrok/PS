#include <iostream>
#include <cstring>

using namespace std;
#define MAX 100001
int n;
int sticker[2][MAX];
int cache[3][MAX];// 0 : sticker[0][i] 를 사용했을 때의 최대
				  // 1 : sticker[1][i] 를 사용했을 때의 최대
				  // 2 : sticker[i] 열이 주어졌을 때의 최대 (max(0, 1))

int dp(int r0, int r1);
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		memset(cache, -1, sizeof(cache));
		//fill in sticker array
		for (int i = 0; i < n; ++i)
			cin >> sticker[0][i];
		for (int i = 0; i < n; ++i)
			cin >> sticker[1][i];
		cout << dp(0, 0) << "\n";
	}
	return 0;
}

int dp(int r0, int r1)
{
	// base
	if (r0 >= n && r1 == n - 1) return sticker[1][r1];
	if (r0 == n - 1 && r1 >= n) return sticker[0][r0];
	if (r0 == n - 1 && r1 == n - 1) return max(sticker[0][r0], sticker[1][r1]);

	int *tmp;
	if (r0 == r1) tmp = &cache[2][r0];
	else if (r0 > r1) tmp = &cache[1][r1];
	else tmp = &cache[0][r0];

	int & ret = *tmp;
	if (ret != -1) return ret;

	ret = 0;
	if (r0 == r1)
	{
		ret = max(sticker[0][r0] + dp(r0 + 2, r1 + 1), sticker[1][r1] + dp(r0 + 1, r1 + 2));
		ret = max(ret, dp(r0 + 1, r1 + 1));
	}
	else if (r0 < r1)
		ret = max(sticker[0][r0] + dp(r0 + 2, r1), dp(r0 + 1, r1));
	else
		ret = max(sticker[1][r1] + dp(r0, r1 + 2), dp(r0, r1 + 1));
	return ret;
}
