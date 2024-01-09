#include <iostream>
#include <cstring>
#include <deque>
#include <utility>
using namespace std;
int r, c;
char lab[1001][1001];
bool visit[1001][1001];
deque<pair<int, int> > q;
pair<int, int> j_init;
void input();
void solve();
bool isInLab(int, int);
bool canEscape(int i, int j);
int main()
{
	input();
	solve();
	return 0;
}

void solve()
{
	int dr[] = {0, 0, 1, -1};
	int dc[] = {1, -1, 0, 0};
	q.push_front(j_init);
	visit[j_init.first][j_init.second] = true;
	int time = 1;
	int loop = q.size();
	while (loop)
	{
		while (loop)
		{
			pair<int, int> p = q.front();
			q.pop_front();
			int tmp_r, tmp_c;
			if (lab[p.first][p.second] == 'J')
			{	// J move
				if (canEscape(p.first, p.second))
				{
					cout << time << "\n";
					return ;
				}
				for (int i = 0; i < 4; ++i)
				{
					tmp_r = p.first + dr[i];
					tmp_c = p.second + dc[i];
					if (isInLab(tmp_r, tmp_c) && lab[tmp_r][tmp_c] == '.' && visit[tmp_r][tmp_c] == false)
					{
						lab[tmp_r][tmp_c] = 'J';
						q.push_back(make_pair(tmp_r, tmp_c));
						visit[tmp_r][tmp_c] = true;
					}
				}
			}
			else if (lab[p.first][p.second] == 'F')
			{	// F move
				lab[p.first][p.second] = '#';
				for (int d = 0; d < 4; ++d)
				{
					tmp_r = p.first + dr[d];
					tmp_c = p.second + dc[d];
					if (isInLab(tmp_r, tmp_c) && lab[tmp_r][tmp_c] != '#')
					{
						lab[tmp_r][tmp_c] = 'F';
						q.push_back(make_pair(tmp_r, tmp_c));
					}
				}
			}
			loop--;
		}
		loop = q.size();
		time++;
	}
	cout << "IMPOSSIBLE\n";
}

bool isInLab(int i, int j)
{
	if (i >= 0 && i < r && j >= 0 && j < c)
		return true;
	return false;
}

bool canEscape(int i, int j)
{
	if (i == 0 || i == r -1 || j == 0 || j == c - 1)
		return true;
	return false;
}

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		cin >> lab[i];
		for (int j = 0; j < c; ++j)
		{
			if (lab[i][j] == 'J')
				j_init = make_pair(i, j);
			else if (lab[i][j] == 'F')
				q.push_back(make_pair(i, j));
		}
	}
}
