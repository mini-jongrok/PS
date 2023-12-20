#include <iostream>
#include <queue>
using namespace std;
int n, m;
char graph[101][101];
int len[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int solve(int i, int j);
void input();
int main()
{
	input();
	printf("%d\n", solve(0, 0));
	return 0;
}

int solve(int i, int j)
{
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));
	len[i][j] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		graph[x][y] = 0;
		for (int k = 0; k < 4; ++k)
		{
			int rx = x + dx[k];
			int ry = y + dy[k];
			if (rx >= 0 && rx < n && ry >= 0 && ry < m && graph[rx][ry] == '1')
			{
				graph[rx][ry] = 0;
				q.push(make_pair(rx, ry));
				len[rx][ry] = len[x][y] + 1;
			}
		}
	}
	return len[n - 1][m - 1];
}

void input()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", graph[i]);
}
