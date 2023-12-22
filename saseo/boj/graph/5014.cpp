#include <iostream>
#include <deque>
using namespace std;
int f, s, g, u, d;
int level[1000001];
int bfs();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> f >> s >> g >> u >> d;
	int ret = bfs();
	if (ret < 0)
		cout << "use the stairs\n";
	else
		cout << ret << "\n";
	return 0;
}

int bfs()
{
	int ret = -1;
	deque<int>	q;
	q.push_back(s);
	level[s] = 1;
	int len = q.size();
	while (len)
	{
		ret++;
		for (int i = 0; i < len; ++i)
		{
			int node = q.front();
			q.pop_front();
			if (node == g)
				return ret;
			if (node + u <= f && level[node + u] == 0)
			{
				level[node + u] = 1;
				q.push_back(node + u);
			}
			if (node - d > 0 && level[node - d] == 0)
			{
				level[node - d] = 1;
				q.push_back(node - d);
			}
		}
		len = q.size();
	}
	return -1;
}
