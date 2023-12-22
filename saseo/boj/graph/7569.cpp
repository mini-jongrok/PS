#include <queue>
#include <iostream>
using namespace std;

typedef struct {
	char hi;
	char ni;
	char mi;
} coordinate;

int n, m, h, whole, zero;
char box[101][101][101];
queue<coordinate> q;
char dh[] = {-1,1,0,0,0,0};
char dn[] = {0,0,0,0,-1,1};
char dm[] = {0,0,-1,1,0,0};

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
    if (whole == zero)
    {
        cout << "-1\n";
        return ;
    }
	int result = bfs();
	if (zero == 0)
		cout << result << "\n";
	else
		cout << "-1\n";
}

int bfs()
{
	int ret = -1;
	int len = q.size();
	while (len)
	{
		ret++;
		for (int node = 0; node < len; ++node)
		{
			coordinate cur = q.front();
			q.pop();
			for (int i = 0; i < 6; ++i)
			{
				coordinate next = {cur.hi + dh[i],
									cur.ni + dn[i],
									cur.mi + dm[i]};
				if (next.hi > -1 && next.hi < h &&
					next.ni > -1 && next.ni < n &&
					next.mi > -1 && next.mi < m &&
					box[next.hi][next.ni][next.mi] == '0')
				{
					box[next.hi][next.ni][next.mi] = '1';
					q.push(next);
					zero--;
				}
			}
		}
		len = q.size();
	}
	return ret;
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	zero = 0;
	cin >> m >> n >> h;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				char tmp;
				char trash;
				cin >> tmp;
				if (tmp == '-')
					cin >> trash;
                else
                {
                    whole++;
				    box[i][j][k] = tmp;
				    coordinate coor = {i, j, k};
				    if (tmp == '1')
				    	q.push(coor);
				    else if (tmp == '0')
					    zero++;
                }
			}
		}
	}
}
