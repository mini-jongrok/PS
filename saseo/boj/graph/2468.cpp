#include <iostream>
#include <set>
#include <deque>
using namespace std;

typedef struct _node
{
	int h;
	int x;
	int y;
} node;

int n;
int _map[101][101][101];
set<int> height;
void input();
int solve();
void bfs(node start);
int main()
{
	input();
	cout << solve() << "\n";
	return 0;
}

int solve()
{
	int ret = 1;
	for (auto h : height)
	{
		int cur_safe_zone = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (_map[h][i][j] > h)
				{
					node tmp = {h, i, j};
					bfs(tmp);
					cur_safe_zone++;
				}
			}
		}
		ret = max(ret, cur_safe_zone);
	}
	return ret;
}

void bfs(node start)
{
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};
	deque<node>	q;
	q.push_back(start);
	_map[start.h][start.x][start.y] = 0;

	while (!q.empty())
	{
		node p = q.front();
		q.pop_front();
		for (int i = 0; i < 4; ++i)
		{
			int h = p.h;
			int x = p.x + dx[i];
			int y = p.y + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < n && _map[h][x][y] > h)
			{
				_map[h][x][y] = 0;
				node next = {h, x, y};
				q.push_back(next);
			}
		}
	}
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> tmp;
			_map[0][i][j] = tmp;
			height.insert(tmp);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (auto & h : height)
				_map[h][i][j] = _map[0][i][j];
		}
	}
}
