#include <iostream>
#include <cstring>
#define _INT_MAX 2147483647
using namespace std;

int n;
int dist[101][101];

void input();
void solve();
void dfs(int, int);
int main()
{
    input();
    solve();
    return 0;
}

void solve() {
    for (int mid = 1; mid < n + 1; ++mid) {
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                int temp = dist[i][mid] + dist[mid][j];
                if (dist[i][mid] == _INT_MAX || dist[mid][j] == _INT_MAX)
                    temp = _INT_MAX;
                dist[i][j] = min(dist[i][j], temp);
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (dist[i][j] != _INT_MAX)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
                dist[i][j] = 1;
            else if (tmp == 0)
                dist[i][j] = _INT_MAX;
            else if (i == j)
                dist[i][j] = 0;
        }
    }
}
