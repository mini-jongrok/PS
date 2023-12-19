#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
int n, m, ret;
vector<int> graph[101];
bool visit[101];
void init();
void solve(int com);
int main()
{
	init();
	solve(1);
	printf("%d\n", ret);
	return 0;
}

void solve(int com)
{
	visit[com] = true;
	ret++;
	for (int& adj : graph[com])
	{
		if (visit[adj] == false)
			solve(adj);
	}
}

void init()
{
	ret = -1;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	memset(visit, false, sizeof(visit));
}
