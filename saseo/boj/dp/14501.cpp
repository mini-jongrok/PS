#include <iostream>
#include <cstring>

#define MAX 30

using namespace std;
int cache[MAX];
int t[MAX];
int p[MAX];
int n;

int dp(const int& day);
int main()
{
	memset(cache, -1, sizeof(cache));
	int tmp_t, tmp_p;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp_t >> tmp_p;
		t[i] = tmp_t;
		p[i] = tmp_p;
	}
	cout << dp(0) << "\n";
	return 0;
}

int dp(const int& day)
{
	if (day >= n ) return 0;
	int & ret = cache[day];
	if (ret != -1) return ret;
	ret = dp(day + 1);
	if (day + t[day] - 1 < n)
		ret = max(p[day] + dp(day + t[day]), ret);
	return ret;
}
