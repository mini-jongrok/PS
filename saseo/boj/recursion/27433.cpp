#include <iostream>
using namespace std;
long long rec(int n);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << rec(n) << "\n";
	return 0;
}

long long rec(int n)
{
	if (n == 1 || n == 0) return 1;
	return n * rec(n - 1);
}
