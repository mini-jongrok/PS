#include <cstdio>
#include <deque>
using namespace std;

typedef struct {
	char hi;
	char ni;
	char mi;
} coordinate;

int n, m, h, zero;
int box[101][101][101];
deque<coordinate> q;
int dh[] = {-1,1,0,0,0,0};
int dn[] = {0,0,0,0,-1,1};
int dm[] = {0,0,-1,1,0,0};

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
	int result = bfs();
	if (zero == 0)
		printf("%d\n", result);
	else
		printf("-1\n");
}

int bfs()
{
	int ret = 0;
	while (!q.empty())
	{
		coordinate cur = q.front();
		q.pop_front();
		int cur_value = box[cur.hi][cur.ni][cur.mi];
		for (int i = 0; i < 6; ++i)
		{
			coordinate next = {cur.hi + dh[i],
								cur.ni + dn[i],
								cur.mi + dm[i]};
			if (next.hi > -1 && next.hi < h &&
				next.ni > -1 && next.ni < n &&
				next.mi > -1 && next.mi < m &&
				box[next.hi][next.ni][next.mi] == 0)
			{
				box[next.hi][next.ni][next.mi] = cur_value + 1;
				q.push_back(next);
				ret = max(cur_value + 1, ret);
				zero--;
			}
		}
	}
	return ret > 0 ? ret - 1 : 0;
}

void input()
{
	zero = 0;
	scanf("%d %d %d", &m, &n, &h);
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				scanf("%d", &box[i][j][k]);
				if (box[i][j][k] == 1)
				{
					coordinate tmp = {i, j, k};
					q.push_back(tmp);
				}
				if (box[i][j][k] == 0)
					zero++;
			}
		}
	}
}
