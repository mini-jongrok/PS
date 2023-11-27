#include <iostream>
#include <cstring>
#include <string>

using namespace std;
int cache[1001][1001];
string a, b;
int dp(int a_idx, int b_idx);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	cin >> a >> b;
	cout << dp(0, 0) << "\n";
	return 0;
}

int dp(int a_idx, int b_idx)
{
	if (a.size() == a_idx || b.size() == b_idx) return 0;
	int& ret = cache[a_idx][b_idx];
	if (ret != -1) return ret;
	ret = 0;
	if (a[a_idx] == b[b_idx])
		ret = 1 + dp(a_idx + 1, b_idx + 1);
	int tmp = max(dp(a_idx + 1, b_idx), dp(a_idx, b_idx + 1));
	ret = max(ret, tmp);
	return ret;
}
