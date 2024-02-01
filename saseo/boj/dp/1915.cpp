#include <iostream>
using namespace std;

int n, m, Max;
int map[1001][1001];
int min3(int a, int b, int c);

void input();
int dp();
int main()
{
    input();
    if (Max == 0)
        cout << "0\n";
    else
        cout << dp() << "\n";

    return 0;
}

int dp()
{
    int di[] = {-1, -1, 0};
    int dj[] = {-1, 0, -1};

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (map[i][j] > 0)
            {
                int before = map[i + di[0]][j + dj[0]];
                int left = map[i + di[1]][j + dj[1]];
                int up = map[i + di[2]][j + dj[2]];
                if (before > 0 && left > 0 && up > 0)
                {
                    map[i][j] = min3(before, left, up) + 1;
                    Max = max(map[i][j], Max);
                }
            }
        }
    }
    return (Max*Max);
}

void input()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> m;
    char buff[1001];
    for (int i = 0; i < n; ++i) {
        cin >> buff;
        for (int j = 0; j < m; ++j) {
            map[i][j] = (int)(buff[j] - '0');
            if (Max == 0 && map[i][j] == 1)
                Max = 1;
        }
    }
}

int min3(int a, int b, int c)
{
    int ret = a;
    ret = min(ret, b);
    ret = min(ret, c);
    return ret;
}