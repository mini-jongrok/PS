#include <iostream>
using namespace std;

int n, m;
int _fixed[50];
int cache[50];
void input();

int main()
{
	int ret = 1;
	input();
	cache[0] = 1;
	cache[1] = 1;
	cache[2] = 2;
	for (int i = 3; i <= n; ++i)
		cache[i] = cache[i - 1] + cache[i - 2];

	for (int i = 1; i <= m + 1; ++i)
		ret *= cache[(_fixed[i] - _fixed[i-1] -1)];
	cout << ret << "\n";
	return 0;
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	_fixed[0] = 0;
	for (int i = 1; i <= m; ++i)
		cin >> _fixed[i];
	_fixed[m + 1] = n + 1;
}
