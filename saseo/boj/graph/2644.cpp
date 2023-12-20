#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n, m, start, target;
int visit[101];
vector<int> adj[101];

int bfs();
void input();
int main()
{
	input();
	printf("%d\n", bfs());
	return 0;
}

int bfs()
{
	bool met = false;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == target)
		{
			met = true;
			break ;
		}
		for (int & node : adj[cur])
		{
			if (visit[node] == 0)
			{
				q.push(node);
				visit[node] = visit[cur] + 1;
			}
		}
	}
	if (met)
		return visit[target];
	return -1;
}

void input()
{
	scanf("%d %d %d %d", &n, &start, &target, &m);
	for (int i = 0; i < m; ++i)
	{
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		adj[tmp1].push_back(tmp2);
		adj[tmp2].push_back(tmp1);
	}
	memset(visit, 0, sizeof(visit));
}
