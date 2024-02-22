#include <iostream>
#include <cstring>
#include <deque>
#include <utility>

using namespace std;
int n, m, k;
int map[301][301];
deque<pair<int, int> > cases;

void input();
void solve();
void print();

int main()
{
    input();
    solve();
    return 0;
}

void solve()
{
    for (int c = 0; c < k; ++c)
    {
        pair<int, int> start = cases.front();
        cases.pop_front();
        pair<int, int> end = cases.front();
        cases.pop_front();
        int ret = map[end.first][end.second] - map[start.first - 1][end.second];
        ret -= map[end.first][start.second - 1];
        ret += map[start.first - 1][start.second - 1];
        cout << ret << "\n";
    }
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < m + 1; ++j)
        {
            cin >> map[i][j];
            map[i][j] += map[i][j - 1];
        }
    }

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < m + 1; ++j)
            map[i][j] += map[i - 1][j];
    }

    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        pair<int, int> start;
        pair<int, int> end;
        cin >> start.first >> start.second >> end.first >> end.second;
        cases.push_back(start);
        cases.push_back(end);
    }
}