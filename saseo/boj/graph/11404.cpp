#include <iostream>
#define NONE 20000000
using namespace std;

int n;
int dist[101][101];

void input();
void solve();
int main()
{
    input();
    solve();
    return 0;
}

void solve() {
    for (int k = 1; k < n + 1; ++k) {
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (dist[i][j] >= NONE)
                cout << "0 ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int m;
    cin >> n >> m;

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j)
            dist[i][j] = NONE;
    }

    for (int i = 0; i < m; ++i) {
        int a, b, cost;
        cin >> a >> b >> cost;
        if (dist[a][b] != NONE)
            dist[a][b] = min(cost, dist[a][b]);
        else
            dist[a][b] = cost;
    }
    for (int i = 1; i < n + 1; ++i)
        dist[i][i] = 0;
}
