#include <iostream>
using namespace std;

long long k, n, max_len;
long long lan[10001];

void input();
long long solve();
int main()
{
	input();
	cout << solve() << "\n";
	return 0;
}

long long solve()
{
	long long ret = 0;
	long long start = 0;
	long long end = max_len;
	long long half_size = (end - start + 1) / 2;
	while (half_size > 0)
	{
		long long mid = start + half_size;
		long long tmp = 0;
		for (long long j = 0; j < k; ++j)
			tmp += (lan[j] / mid);
		if (tmp < n)
			end -= half_size;
		else if (tmp >= n)
		{
			start += half_size;
			ret = max(ret, mid);
		}
		half_size = (end - start + 1) / 2;
	}
	return ret;
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> n;
	max_len = 0;
	for (long long i = 0; i < k; ++i)
	{
		cin >> lan[i];
		max_len = max(max_len, lan[i]);
	}
}
