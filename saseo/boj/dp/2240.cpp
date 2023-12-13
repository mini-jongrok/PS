#include <iostream>
#include <cstring>
using namespace std;
int t, w;
int numbers[1001];
int cache[1001][2][31];
void init();
int dp(int time, int pos, int left);
int main()
{
	init();
	cout << dp(1, 0, w) << "\n";
	return 0;
}

int dp(int time, int pos, int left)
{
	if (time > t) return 0;
	int & ret = cache[time][pos][left];
	if (ret != -1) return ret;

	if (left > 0)
	{
		int stay = dp(time + 1, pos, left);
		int move = dp(time + 1, (pos + 1) % 2, left - 1);
		if (numbers[time] == pos) stay++;
		else move++;
		ret = max(stay, move);
	}
	else
	{
		ret = dp(time + 1, pos, left);
		if (numbers[time] == pos) ret++;
	}
	return ret;
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t >> w;
	for (int i = 1; i <= t; ++i){
		cin >> numbers[i];
		numbers[i]--;
	}
	memset(cache, -1, sizeof(cache));
}
