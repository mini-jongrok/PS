#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

int n, m;
vector<int> graph[101];
int kevin[101][101];
vector<pair<int, int> > answer;

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
    for (int i = 1; i < n + 1; ++i)
        bfs(i);
    sort(answer.begin(), answer.end());
    cout << answer.front().second << "\n";
}

void bfs(int start) {
    bool visit[101];
    deque<int> q;
    int ans = 0;

    memset(visit, false, sizeof(visit));
    q.push_back(start);
    int child_len = q.size();
    int len = 0;
    visit[start] = true;
    while (!q.empty()) {
        len++;
        while (child_len--) {
            int p = q.front();
            q.pop_front();
            for (int child : graph[p]) {
                if (visit[child] == false) {
                    ans += len;
                    q.push_back(child);
                    visit[child] = true;
                }
            }
        }
        child_len = q.size();
    }
    answer.push_back(make_pair(ans, start));
}

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    memset(kevin, -1, sizeof(kevin));
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        kevin[a][b] = 1;
        kevin[b][a] = 1;
    }
}
