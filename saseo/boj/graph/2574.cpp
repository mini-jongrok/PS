#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int n, m;
int map[2][301][301];
bool visit[301][301];
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

void input();
int solve();
void melt(int h);
int bfs(int h);
void _bfs(int year, int x, int y);

int main()
{
	input();
	cout << solve() << "\n";
	return 0;
}

int solve()
{
	melt(0);
	int year = 1;
	int next = 1;
	while (true)
	{
		int tmp = bfs(next);
		if (tmp > 1)
			return year;
		if (tmp == 0)
			return 0;
		melt(next);
		next = (next + 1) % 2;
		year++;
	}
	return 0;
}

void melt(int year)
{
	int next_year = (year + 1) % 2;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[year][i][j] > 0)
			{
				int dv = 0;
				for (int d = 0; d < 4; ++d)
				{
					int ri = i + di[d];
					int rj = j + dj[d];
					if (ri >= 0 && ri < n && rj >= 0 && rj < m && map[year][ri][rj] == 0)
						dv++;
				}
				int tmp = map[year][i][j] - dv;
				map[next_year][i][j] = tmp <= 0 ? 0 : tmp;
			}
			else
				map[next_year][i][j] = 0;
		}
	}
}

int bfs(int h)
{
	memset(visit, false, sizeof(visit));
	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[h][i][j] > 0 && visit[i][j] == false)
			{
				ret++;
				_bfs(h, i, j);
			}
		}
	}
	return ret;
}

void _bfs(int year, int x, int y)
{
	deque<pair<int, int> > q;
	q.push_back(make_pair(x, y));
	visit[x][y] = true;

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop_front();
		for (int d = 0; d < 4; ++d)
		{
			int ri = p.first + di[d];
			int rj = p.second + dj[d];
			if (ri >= 0 && ri < n && rj >= 0 && rj < m && \
				 visit[ri][rj] == false  && map[year][ri][rj] > 0)
			{
				visit[ri][rj] = true;
				q.push_back(make_pair(ri, rj));
			}
		}
	}
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> map[0][i][j];
	}
	memset(visit, false, sizeof(visit));
}
