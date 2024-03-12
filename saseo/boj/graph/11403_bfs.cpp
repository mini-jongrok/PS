#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int n;
int graph[101][101];
bool answers[101][101];

void input();
void solve();
void bfs(int start);
int main()
{
    input();
    solve();
    return 0;
}

void solve() {
    for (int i = 1; i < n + 1; ++i) {
        bfs(i);
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j)
            cout << answers[i][j] << " ";
        cout << "\n";
    }
}

void bfs(int start) {
    deque<int> q;
    q.push_back(start);
    bool visit[101];
    memset(visit, false, sizeof(visit));

    while (q.size()) {
        int p = q.front();
        q.pop_front();

        for (int i = 1; i < n + 1; ++i) {
            if (p == i)
                continue;
            if (graph[p][i] == true && visit[i] == false) {
                q.push_back(i);
                visit[i] = true;
                answers[start][i] = true;
                answers[p][i] = true;
            }
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
