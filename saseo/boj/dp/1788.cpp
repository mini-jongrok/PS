#include <iostream>
using namespace std;
int n;
int cache[1000001];
int mod = 1000000000;
int abs(int n);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cache[0] = 0; cache[1] = 1; cache[2] = 1;
	for (int i = 3; i <= abs(n); ++i)
		cache[i] = (cache[i - 1] + cache[i - 2]) % mod;
	
	if (n > 0)
		cout << "1\n" << cache[n] << "\n";
	else if (n == 0)
		cout << "0\n" << cache[0] << "\n";
	else if (n % 2 == 0)
		cout << "-1\n" << cache[(n * -1)] << "\n";
	else
		cout << "1\n" << cache[(n * -1)] << "\n";
	return 0;
}

int abs(int n)
{
	if (n >= 0) return n;
	return n * -1;
}
