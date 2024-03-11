#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, m; //1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2
vector<int> graph[1001];
bool visit[1001];

void input();
void solve();
void dfs(int start);

int main()
{
    input();
    solve();
    return 0;
}

void solve() {
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (visit[i] == false) {
            dfs(i);
            ret++;
        }
    }
    cout << ret << "\n";
}

void dfs(int start) {
    if (visit[start] == true)
        return;
    visit[start] = true;
    vector<int>& conn = graph[start];
    for (auto & vertex : conn) {
        if (visit[vertex] == false)
            dfs(vertex);
    }
}

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(visit, false, sizeof(visit));
}