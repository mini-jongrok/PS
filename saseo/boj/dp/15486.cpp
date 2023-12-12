#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n;
vector<pair<int, int> > table;
int cache[1500001];
int dp(int day);
void input();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	input();
	cout << dp(0) << "\n";
	return 0;
}

int dp(int day)
{
	if (day >= n) return 0;
	int & ret = cache[day];
	if (ret != -1) return ret;
	if (table[day].first + day <= n)
		ret = table[day].second + dp(table[day].first + day);
	ret = max(ret, dp(day + 1));
	return ret;
}

void input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int t, p;
		cin >> t >> p;
		table.push_back(make_pair(t, p));
	}
}
