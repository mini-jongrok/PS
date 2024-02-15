#include <cstring>
#include <iostream>
#include <deque>
#include <utility>
using namespace std;

typedef pair<int, int> Point;

int     t, w, h;    
char    map[1001][1001];
int     di[] = {0, 0, 1, -1};
int     dj[] = {1, -1, 0, 0};
deque<pair<int, int> >  q;

void input();
void solve();
void bfs();
bool is_valid_point(Point p);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    solve();
    return 0;
}

void solve()
{
    while (t--)
    {
        input();
        bfs();
    }
}

void bfs()
{
    int time = 0;
    int size = q.size();
    while (size)
    {
        time++;
        for (int s = 0; s < size; ++s)
        {
            Point cur = q.front();
            q.pop_front();
            char type = map[cur.first][cur.second];

            for (int d = 0; d < 4; ++d)
            {
                Point next = make_pair(cur.first + di[d], cur.second + dj[d]);
                char *next_point_ptr = nullptr;
                bool valid = is_valid_point(next);
                if (valid == false && type == '@')
                {
                    cout << time << "\n";
                    return;
                }
                else if (valid == false)
                    continue;
                next_point_ptr = &(map[next.first][next.second]);
                // check if this move can be done;
                if (type == '@' && *next_point_ptr == '.')
                {
                    q.push_back(next);
                    *next_point_ptr = '@';
                }
                else if (type == '*' && (*next_point_ptr == '.' || *next_point_ptr == '@'))
                {
                    q.push_back(next);
                    *next_point_ptr = '*';
                }
            }
        }
        size = q.size();
    }

    cout << "IMPOSSIBLE\n";
}

bool is_valid_point(Point p)
{
    if (p.first >= 0 && p.first < h && p.second >= 0 && p.second < w)
        return true;
    return false;
}

void input()
{
    q.clear();
    memset(map, 0, sizeof(map));
    cin >> w >> h;
    for (int i = 0; i < h; ++i) {
        cin >> map[i];
        for (int j = 0; j < w; ++j)
        {
            if (map[i][j] == '@')
                q.push_front(make_pair(i, j));
            else if (map[i][j] == '*')
                q.push_back(make_pair(i, j));
        }
    }
}