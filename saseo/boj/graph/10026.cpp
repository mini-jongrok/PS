#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int n;
char    paint[101][101];
bool    visit[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void    input();
void    solve();
int     RedGreenWeakness();
int     Non_RedGreenWeakness();
bool    IsValidPoint(int x, int y);
void    bfs(int i, int j, bool is_weakness = false);

int main()
{
    input();
    solve();
    return 0;
}

void    solve()
{
    memset(visit, false, sizeof(visit));
    cout << Non_RedGreenWeakness() << " ";
    memset(visit, false, sizeof(visit));
    cout << RedGreenWeakness() << "\n";
}

int Non_RedGreenWeakness()
{
    int ret = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (visit[i][j] == false)
            {
                bfs(i, j);
                ret++;
            }
        }
    }
    return ret;
}

int RedGreenWeakness()
{
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (visit[i][j] == false)
            {
                bfs(i, j, true);
                ret++;
            }
        }
    }
    return ret;
}

void    bfs(int i, int j, bool is_weakness)
{
    deque<pair<int, int> >  q;
    q.push_back(make_pair(i, j));
    char c = paint[i][j];
    visit[i][j] = true;

    while (q.size())
    {
        pair<int, int> p = q.front();
        q.pop_front();

        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> near = make_pair(p.first + dx[i], p.second + dy[i]);
            if (IsValidPoint(near.first, near.second) == true && visit[near.first][near.second] == false)
            {
                char near_c = paint[near.first][near.second];
                bool push = false;

                if (is_weakness && (c == 'R' || c == 'G') && (near_c == 'R' || near_c == 'G'))
                    push = true;
                else if (c == near_c)
                    push = true;
                
                if (push)
                {
                    q.push_back(near);
                    visit[near.first][near.second] = true;
                }
            }
        }
    }
}

bool    IsValidPoint(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n)
        return true;
    return false;
}

void    input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> paint[i];
    }
}