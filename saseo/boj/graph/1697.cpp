#include <iostream>
#include <deque>
using namespace std;
int n, k;
int line[100001];
int MAX = 100000;

int bfs(const int& start);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	cout << bfs(n) << "\n";
	return 0;
}

int bfs(const int& start)
{
	int ret = -1;
	deque<int>	q;
	q.push_back(start);
	line[start] = 1;
	int len = q.size();
	while (len)
	{
		ret++;
		for (int i = 0; i < len; ++i)
		{
			int node = q.front();
			q.pop_front();
			if (node == k)
				return ret;
			if (node - 1 >= 0 && line[node - 1] == 0)
			{
				line[node - 1] = 1;
				q.push_back(node - 1);
			}
			if (node + 1 <= MAX && line[node + 1] == 0)
			{
				line[node + 1] = 1;
				q.push_back(node + 1);
			}
			if (node * 2 <= MAX && line[node * 2] == 0)
			{
				line[node * 2] = 1;
				q.push_back(node * 2);
			}
		}
		len = q.size();
	}
	return ret;
}
