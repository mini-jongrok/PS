#include <iostream>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

int T, I;
bool visit[301][301];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
pair<int, int> cur;
pair<int, int> tar;

void    input();
int    bfs();
bool    IsValidPoint(int x, int y);

int main()
{
    cin >> T;
    while (T--)
    {
        input();
        if (cur.first == tar.first && cur.second == tar.second)
            cout << "0\n";
        else
            cout << bfs() << "\n";
    }
    return 0;
}

int    bfs()
{
    int len = 0;
    queue<pair<int, int> > q;
    q.push(cur);
    visit[cur.first][cur.second] = true;
    int loop = q.size();

    while (loop)
    {
        for (int i = 0; i < loop; ++i)
        {
            pair<int, int>  p = q.front();
            q.pop();
            for (int d = 0; d < 8; ++d)
            {
                int nx = p.first + dx[d];
                int ny = p.second + dy[d];
                if (nx == tar.first && ny == tar.second)
                    return len + 1;
                if (IsValidPoint(nx, ny) == false || visit[nx][ny] == true)
                    continue;
                q.push(make_pair(nx, ny));
                visit[nx][ny] = true;
            }
        }
        len++;
        loop = q.size();
    }
    return len;
}

bool    IsValidPoint(int x, int y)
{
    if (x >= 0 && x < I && y >= 0 && y < I)
        return true;
    return false;
}

void    input()
{
    cin >> I;
    cin >> cur.first >> cur.second;
    cin >> tar.first >> tar.second;
    memset(visit, false, sizeof(visit));
}