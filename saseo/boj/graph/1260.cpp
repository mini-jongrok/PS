#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;
void input();
void dfs(int vertex);
void bfs(int start);

int n, m, v;
vector<int> graph[1001];
bool visit[1001];

int main()
{
	input();
	memset(visit, 0, sizeof(visit));
	dfs(v);
	cout << "\n";
	memset(visit, 0, sizeof(visit));
	bfs(v);
	return 0;
}

void dfs(int vertex)
{
	visit[vertex] = true;
	cout << vertex << " ";
	for (int i = 0; i < graph[vertex].size(); ++i)
	{
		int tmp = graph[vertex][i];
		if (visit[tmp] == false)
			dfs(tmp);
	}
}

void bfs(int start)
{
	deque<int> q;
	q.push_back(start);
	visit[start] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop_front();
		cout << cur << " ";
		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int tmp = graph[cur][i];
			if (visit[tmp] == false)
			{
				visit[tmp] = true;
				q.push_back(tmp);
			}
		}
	}
	cout << "\n";
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> v;

	for (int i = 0; i < m; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for (int i = 1; i <= n; ++i)
		sort(graph[i].begin(), graph[i].end());
}
