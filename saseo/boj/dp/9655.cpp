#include <iostream>
using namespace std;
int n;
bool cache[1010];
void solve();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	solve();
	return 0;
}

void solve()
{
	// base case
	cache[0] = false;
	cache[1] = true;
	cache[2] = false;
	cache[3] = true;

	for (int i = 4; i <= n; ++i)
	{
		if (cache[i - 1] == true && cache[i - 3] == true)
			cache[i] = false;
		else
			cache[i] = true;
	}
	if (cache[n]) cout << "SK\n";
	else cout << "CY\n";
}
