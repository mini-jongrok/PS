#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int n;
int graph[101][101];
bool answers[101][101];
bool visit[101];

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
    for (int i = 1; i < n + 1; ++i) {
        memset(visit, false, sizeof(visit));
        dfs(i, i);
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j)
            cout << answers[i][j] << " ";
        cout << "\n";
    }
}

void dfs(int origin, int cur) {
    for (int j = 1; j < n + 1; ++j) {
        if (graph[cur][j] == true && visit[j] == false) {
            answers[cur][j] = true;
            answers[origin][j] = true;
            visit[j] = true;
            dfs(origin, j);
        }
    }
 }

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cin >> graph[i][j];
        }
    }
    memset(answers, false, sizeof(answers));
}
