#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, tmp;
int graph[26][26];
vector<int> answers;
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

void dfs(int i, int j);
void init();
void solve();
int main()
{
	init();
	solve();
	return 0;
}

void dfs(int i, int j)
{
	tmp++;
	for (int k = 0; k < 4; ++k)
	{
		int ri = i + di[k];
		int rj = j + dj[k];
		if (ri >= 0 && ri < n && rj >= 0 && rj < n && graph[ri][rj] == '1')
		{
			graph[ri][rj] = graph[i][j] + 1;
			dfs(ri, rj);
		}
	}
}

void solve()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (graph[i][j] == '1')
			{
				tmp = 0;
				graph[i][j] += 1;
				dfs(i, j);
				answers.push_back(tmp);
			}
		}
	}
	sort(answers.begin(), answers.end());
	printf("%lu\n", answers.size());
	for (int & item : answers)
		printf("%d\n", item);
}

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		char t[30];
		scanf("%s", t);
		for (int j = 0; j < n; ++j)
			graph[i][j] = t[j];
	}
}
