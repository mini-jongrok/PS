#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

int n, m;
vector<int> graph[501];
deque<int> q;
bool visit[501];

void input();
void solve();
int bfs(void);

int main()
{
    input();
    solve();
    return 0;
}

void solve() {
    q.push_back(1);
    visit[1] = true;
    cout << bfs() << "\n";
}

int bfs(void) {
    int ret = 0;
    int level = 0;
    int len = q.size();
    while (q.size()) {
        if (level == 3) {
            break;
        }
        for (int i = 0; i < len; ++i) {
            int p = q.front();
            q.pop_front();
            if (p != 1)
                ret++;
            for (auto & con : graph[p]) {
                if (visit[con] == false) {
                    visit[con] = true;
                    q.push_back(con);
                }
            }
        }
        len = q.size();
        level++;
    }
    return ret;
}

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(visit, false, sizeof(visit));
}
