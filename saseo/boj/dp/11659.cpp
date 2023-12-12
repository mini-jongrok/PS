#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<pair<int, int> > range;
int number[100001];
void init();
int dp(int i, int j);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	for (auto & p : range)
		cout << number[p.second] - number[p.first - 1] << "\n";
	return 0;
}

void init()
{
	int f, s;
	cin >> n >> m;
	number[0] = 0;
	cin >> number[1];
	for (int i = 2; i < n + 1; ++i)
	{
		cin >> number[i];
		number[i] += number[i - 1];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> f >> s;
		range.push_back(make_pair(f, s));
	}
}
