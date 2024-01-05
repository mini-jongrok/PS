#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int n, m;
char paper[501][501];
bool visit[501][501];

void input();
void solve();
int bfs(int, int);
int main()
{
	input();
	solve();
	return 0;
}

void solve()
{
	int numberOfPaints = 0;
	int maxSize = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (paper[i][j] == '1' && visit[i][j] == false)
			{
				numberOfPaints++;
				maxSize = max(maxSize, bfs(i, j));
			}
		}
	}
	cout << numberOfPaints << "\n" << maxSize << "\n";
}

int bfs(int i, int j)
{
	int res = 0;
	int di[] = {-1, 0, 1, 0};
	int dj[] = {0, 1, 0, -1};
	deque<pair<int, int> > q;
	q.push_back(make_pair(i, j));
	visit[i][j] = true;
	res++;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop_front();
		for (int d = 0; d < 4; ++d)
		{
			pair<int, int> near = make_pair(cur.first + di[d], cur.second + dj[d]);
			if (near.first >= 0 && near.first < n && \
				near.second >= 0 && near.second < m && \
				paper[near.first][near.second] == '1' && \
				visit[near.first][near.second] == false)
			{
				visit[near.first][near.second] = true;
				q.push_back(near);
				res++;
			}
		}
	}
	return res;
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> paper[i][j];
	}
	memset(visit, false, sizeof(visit));
}
