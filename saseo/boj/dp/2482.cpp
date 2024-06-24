#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
int cache[1001][1001];
int mod = 1000000003;

void input();
void solve();
int dp(int, int);

int main() {
	input();
	solve();
	return 0;
}

void solve() {
	cout << (dp(n - 3, k - 1) + dp(n - 1, k)) % mod << "\n";
}

int dp(int len, int pick) {
	int &ret = cache[len][pick];
	if (ret != -1)
		return ret;

	if (pick == 0)
		ret = 1;
	else if (pick == 1)
		ret = len;
	else if (len == pick * 2 - 1)
		ret = 1;
	else if (len < pick * 2)
		ret = 0;
	else
		ret = dp(len - 2, pick - 1) + dp(len - 1, pick);

	ret %= mod;
	return ret;
}

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	memset(cache, -1, sizeof(cache));
}
