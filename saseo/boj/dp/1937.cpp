#include <iostream>
#include <cstring>
using namespace std;

int n;
int map[501][501];
int cache[501][501];

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

void print();

void input();
void solve();
void dp(int i, int j);

int main()
{
    input();
    solve();
    return 0;
}

void solve()
{
    int max_forest = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (cache[i][j] == -1)
                dp(i, j);
            max_forest = max(max_forest, cache[i][j]);
        }
    }
    cout << ++max_forest << "\n";
}

void dp(int i, int j)
{
    int ret = 0;
    
    for (int d = 0; d < 4; ++d)
    {
        int next_i = i + di[d];
        int next_j = j + dj[d];

        if (next_i < 0 || next_j < 0 || next_i >= n || next_j >= n || map[next_i][next_j] <= map[i][j])
            continue;

        if (cache[next_i][next_j] == -1)
            dp(next_i, next_j);
        ret = max(ret, 1 + cache[next_i][next_j]);
    }
    cache[i][j] = ret;
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> map[i][j];
    }
    memset(cache, -1, sizeof(cache));
}