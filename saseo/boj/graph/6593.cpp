#include <iostream>
#include <cstring>
#include <deque>
#include <string>
using namespace std;

typedef struct coor {
    int i;
    int j;
    int k;
} Coor;

int L, R, C;
char building[31][31][31];
bool visit[31][31][31];
Coor start;
int di[] = {0, 0, 0, 0, 1, -1};
int dj[] = {0, 0, 1, -1, 0, 0};
int dk[] = {1, -1, 0, 0, 0, 0};

void input();
void solve();
void case_input();
void bfs();
bool IsValidCoor(const Coor& coor);
int main()
{
    input();
    solve();
    return 0;
}

void solve() {
    while (true)
    {
        case_input();
        if (L == 0 && R == 0 && C == 0)
            break;
        bfs();
    }
}

void bfs()
{
    int len = 0;
    int around_len = 1;
    deque<Coor> q;
    q.push_back(start);
    visit[start.i][start.j][start.k] = true;

    while (q.size())
    {
        len++;
        for (int idx = 0; idx < around_len; ++idx)
        {
            Coor p = q.front();
            q.pop_front();
            for (int d = 0; d < 6; ++d)
            {
                Coor next = {p.i + di[d], p.j + dj[d], p.k + dk[d]};
                if (IsValidCoor(next) && visit[next.i][next.j][next.k] == false && building[next.i][next.j][next.k] != '#')
                {
                    if (building[next.i][next.j][next.k] == 'E')
                    {
                        cout << "Escaped in " << len << " minute(s).\n";
                        return;
                    }
                    visit[next.i][next.j][next.k] = true;
                    q.push_back(next);
                }
            }
        }
        around_len = q.size();
    }
    cout << "Trapped!\n";
}

void case_input()
{
    cin >> L >> R >> C;
    for (int i = 0; i < L; ++i)
    {
        for (int j = 0; j < R; ++j)
        {
            string tmp;
            cin >> tmp;
            for (int k = 0; k < C; ++k)
            {
                building[i][j][k] = tmp[k];
                if (tmp[k] == 'S')
                {
                    start.i = i;
                    start.j = j;
                    start.k = k;
                }
            }
        }
    }
    memset(visit, false, sizeof(visit));
}

bool IsValidCoor(const Coor& coor) {
    if (coor.i >= 0 && coor.i < L && \
        coor.j >= 0 && coor.j < R && \
        coor.k >= 0 && coor.k < C)
        return true;
    return false;
}

void input() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
