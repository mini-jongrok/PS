#include <iostream>
using namespace std;
int n, m, x, y, dir, res;
char room[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void input();
void solve();
int main()
{
	input();
	solve();
	return 0;
}

void dfs(int ix, int iy, int idir);
void solve()
{
	dfs(x, y, dir);
	cout << res << "\n";
}

void dfs(int ix, int iy, int idir)
{
	// check 4 points around the initial point.
	bool dirtyLeft = false;
	for (int i = 0; i < 4; ++i)
	{
		int tmpx, tmpy;
		tmpx = ix + dx[i];
		tmpy = iy + dy[i];
		if (tmpx > 0 && tmpx < n && tmpy > 0 && tmpy < m \
			 && room[tmpx][tmpy] == '0')
		{
			dirtyLeft = true;
			break ;
		}
	}

	// 1. clean cur. position if it's dirty yet.
	if (room[ix][iy] == '0')
	{
		res++;
		room[ix][iy] += 1;
	}

	if (dirtyLeft == false)
	{
		int behind_x, behind_y;
		int behind_dir = (idir + 2) % 4;
		behind_x = ix + dx[behind_dir];
		behind_y = iy + dy[behind_dir];
		// range check && wall or space
		if (behind_x > 0 && behind_x < n && behind_y > 0 && behind_y < m && \
			room[behind_x][behind_y] != '2')
			dfs(behind_x, behind_y, idir);
		else
			return ;
	} else {
		// find first dirty side
		int loop = 4;
		int next_x, next_y;
		while (loop--)
		{
			idir = (idir + 3) % 4;
			next_x = ix + dx[idir];
			next_y = iy + dy[idir];
			if (next_x > 0 && next_x < n && next_y > 0 && next_y < m && \
				room[next_x][next_y] == '0')
				break;
		}
		dfs(next_x, next_y, idir);
	}
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> x >> y >> dir;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> room[i][j];
			if (room[i][j] == '1')
				room[i][j]++;
		}
	}
	res = 0;
}
