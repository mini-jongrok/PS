#include <iostream>
#include <cstring>
int n;//(2 <= n <= 100,000)
long long graph[100001][3];
long long cache[100001][3];
bool visited[100001][3];

using namespace std;

void init();
void input();
void solve();
long long dp(int depth, int row);
void set_break_dp();

int main()
{
    init();
    solve();
    return 0;
}

void solve() {
    int i = 1;
    while (1) {
        input();
        if (n == 0)
            return;
        memset(visited, false, sizeof(visited));
        set_break_dp();
        cout << i << ". " << dp(1, 1) << "\n";
        i++;
    }
}

void set_break_dp() {
        visited[n][0] = true;
        visited[n][1] = true;
        visited[n][2] = true;
        visited[n-1][2] = true;

        cache[n][0] = graph[n][0] + graph[n][1];
        cache[n][1] = graph[n][1];
        cache[n][2] = 2147483647;
        cache[n-1][2] = graph[n-1][2] + graph[n][1];
}

long long dp(int depth, int row) {
    long long& ret = cache[depth][row];
    if (visited[depth][row] == true)
        return ret;

    if (row == 0) {
        ret = min(dp(depth, row + 1), dp(depth + 1, row));
        ret = min(ret, dp(depth + 1, row + 1));
    } else if (row == 1) {
        ret = min(dp(depth + 1, 0), dp(depth + 1, 1));
        ret = min(ret, dp(depth + 1, 2));
        ret = min(ret, dp(depth, 2));
    } else if (row == 2 && depth < n - 1) {
        ret = min(dp(depth + 1, row - 1), dp(depth + 1, row));
    }
    ret += graph[depth][row];
    visited[depth][row] = true;
    return ret;
}

void input() {
    cin >> n;
    for (int i = 1; i < n + 1; ++i)
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


// 4
// 13 7 -900
// 7 13 6
// 14 3 12
// 15 6 16

// 3
// -100 1 2
// -1  -2 -3
// -1   1 -200 