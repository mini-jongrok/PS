#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
	int hi;
	int ni;
	int mi;
} coordinate;

int n, m, h;
int box[101][101][101];
int dh[] = {-1,1,0,0,0,0};
int dn[] = {0,0,0,0,-1,1};
int dm[] = {0,0,-1,1,0,0};

void input();
void solve();
int bfs();
void init_queue(queue<coordinate>& q);
int min(int a, int b);
int max(int a, int b);
bool allGood();

int main()
{
	input();
	solve();
	return 0;
}

void solve()
{
	int result = bfs();
	if (allGood())
		printf("%d\n", result);
	else
		printf("-1\n");
}

int bfs()
{
	int ret = 0;
	queue<coordinate> q;
	init_queue(q);
	while (!q.empty())
	{
		coordinate cur = q.front();
		q.pop();
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
				q.push(next);
				ret = max(cur_value + 1, ret);
			}
		}
	}
	return ret > 0 ? ret - 1 : 0;
}

void init_queue(queue<coordinate>& q)
{
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				coordinate tmp = {i, j, k};
				if (box[i][j][k] == 1)
					q.push(tmp);
			}
		}
	}
}

bool allGood()
{
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
				if (box[i][j][k] == 0)
					return false;
		}
	}
	return true;
}

void input()
{
	scanf("%d %d %d", &m, &n, &h);
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
				scanf("%d", &box[i][j][k]);
		}
	}
}

int max(int a, int b)
{
	if (a >= b) return a;
	return b;
}

int min(int a, int b)
{
	if (a > b) return b;
	return a;
}
