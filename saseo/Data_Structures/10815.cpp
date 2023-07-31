#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int tmp;
	unordered_set<int> ns;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		ns.insert(tmp);
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		unordered_set<int>::const_iterator got;
		cin >> tmp;
		got = ns.find(tmp);
		if (got != ns.end())
			cout << "1 ";
		else
			cout << "0 ";
	}
	return 0;
}
