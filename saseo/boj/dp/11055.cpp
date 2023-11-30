#include <iostream>
#include <cstring>
using namespace std;
int n;
int arr[1010];
int cache[1010];
int dp(int i);
int main()
{
	memset(cache, -1, sizeof(cache));
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	int ret = 0;
	for (int i = 1; i <= n; ++i) ret = max(ret, dp(i));
	cout << ret << "\n";
	return 0;
}

int dp(int i)
{
	if (i == n) return arr[i];
	int & ret = cache[i];
	if (ret != -1) return ret;

	ret = 0;
	for (int next = i + 1; next <= n; ++next)
	{
		int tmp = 0;
		if (arr[i] < arr[next]) tmp = dp(next);
		ret = max(ret, tmp);
	}
	ret += arr[i];
	return ret;
}
