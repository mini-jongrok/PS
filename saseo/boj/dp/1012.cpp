#include <iostream>
#include <deque>
#include <utility>
#include <cstring>
using namespace std;

int T, m, n, k;
int map[51][51];
bool visit[51][51];

void    input();
void    solve();
void    bfs(int i, int j);

int main()
{
    input();
    while (T--)
        solve();
    return 0;
}

void    solve()
{
    int ret = 0;
    memset(map, 0, sizeof(map));
    memset(visit, false, sizeof(visit));
    cin >> m >> n >> k;
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        map[y][x] = 1;
    }

    //solve here for each test case
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (visit[i][j] == false && map[i][j] == 1)
            {
                bfs(i, j);
                ret++;
            }
        }
    }

    cout << ret << "\n";
}

void    bfs(int i, int j)
{
    int di[] = {0, 0, -1, 1};
    int dj[] = {-1, 1, 0, 0};
    deque<pair<int, int> >  q;
    q.push_back(make_pair(i, j));
    visit[i][j] = true;
    while (q.size() > 0)
    {
        pair<int, int>  p = q.front();
        q.pop_front();

        for (int d = 0; d < 4; ++d)
        {
            pair<int, int> dpoint = make_pair(p.first + di[d], p.second + dj[d]);
            if (dpoint.first >= 0 && dpoint.first < n && \
             dpoint.second >= 0 && dpoint.second < m && \
             visit[dpoint.first][dpoint.second] == false && \
             map[dpoint.first][dpoint.second] == 1)
            {
                q.push_back(dpoint);
                visit[dpoint.first][dpoint.second] = true;
            }
        }
    }
}

void    input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
}