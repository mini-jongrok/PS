#include <iostream>
#include <cstring>
#include <string>

using namespace std;
int cache[1001][1001];
string a, b;
int dp(int a_idx, int b_idx);
string getLcs();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	
	cin >> a >> b;
	cout << dp(0, 0) << "\n";
	if (cache[0][0]) cout << getLcs() << "\n";
	return 0;
}

int dp(int a_idx, int b_idx)
{
	if (a.size() == a_idx || b.size() == b_idx) return 0;
	int& ret = cache[a_idx][b_idx];
	if (ret != -1) return ret;

	ret = 0;
	if (a[a_idx] == b[b_idx]) ret = 1 + dp(a_idx + 1, b_idx + 1);
	else ret = max(dp(a_idx + 1, b_idx), dp(a_idx, b_idx + 1));

	return ret;
}

string getLcs()
{
	string answer = "";
	int i = 0; int j = 0;
	int len = cache[i][j];
	while (len > 0)
	{
		if (a[i] == b[j])
		{
			answer += a[i];
			i++; j++;
		}
		else if (a[i] != b[j])
		{
			int tmp_i = (i + 1 < a.size()) ? cache[i + 1][j] : 0;
			int tmp_j = (j + 1 < b.size()) ? cache[i][j + 1] : 0;
			if (tmp_i > tmp_j) i++;
			else j++;
		}
		len = cache[i][j];
	}
	return answer;
}
