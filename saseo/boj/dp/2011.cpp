#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int cache[5005];
bool	err = false;
string str;
int mod = 1000000;
int dp(int idx);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	cin >> str;
	try {
		cout << dp(0) << "\n";
	} catch (int & e)
	{
		cout << "0\n";
	}
	return 0;
}

int dp(int idx)
{
	if (idx >= str.size()) return 1;
	int & ret = cache[idx];
	if (ret != -1) return ret;

	if (str[idx] == '0') throw 0;
	if (idx < str.size() - 1 && str[idx] <= '2' && str[idx+1] == '0')
		ret = dp(idx+2) % mod;
	else if (idx < str.size() - 1 && str[idx] > '2' && str[idx+1] == '0')
		throw 0;
	else if (idx < str.size() - 1 && str[idx] <= '2')
	{
		ret = dp(idx+1);
		if (!(idx < str.size() - 2 && str[idx+2] == '0'))
		{
			if ((str[idx] == '2' && str[idx+1] <= '6') || str[idx] == '1')
				ret += dp(idx+2);
		}
		ret %= mod;
	}
	else
		ret = dp(idx+1) % mod;
	return ret;
}
