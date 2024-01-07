#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

deque<pair<int, int> > q;
int m, n, unripe;
int box[1001][1001];
bool visit[1001][1001];

void input();
void solve();
int bfs();

int main()
{
	input();
	solve();
	return 0;
}

void solve()
{
	int day = bfs();
	if (unripe > 0)
		cout << "-1\n";
	else
		cout << day << "\n";
}

int bfs()
{
	int res = -1;
	int len = 0;
	int di[] = {0, 0, 1, -1};
	int dj[] = {1, -1, 0, 0};
	len = q.size();
	while (len)
	{
		res++;
		while (len)
		{
			pair<int, int> cur = q.front();
			q.pop_front();
			for (int d = 0; d < 4; ++d)
			{
				int tmp_i = cur.first + di[d];
				int tmp_j = cur.second + dj[d];
				if (tmp_i >= 0 && tmp_i < n && tmp_j >= 0 && tmp_j < m)
				{
					if (box[tmp_i][tmp_j] == 0 && visit[tmp_i][tmp_j] == false)
					{
						visit[tmp_i][tmp_j] = true;
						box[tmp_i][tmp_j] = 1;
						q.push_back(make_pair(tmp_i, tmp_j));
						unripe--;
					}
				}
			}
			len--;
		}
		len = q.size();
	}
	return res;
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	unripe = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> box[i][j];
			if (box[i][j] == 0)
				unripe++;
			else if (box[i][j] == 1)
				q.push_back(make_pair(i, j));
		}
	}
	memset(visit, false, sizeof(visit));
}
