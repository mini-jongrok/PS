#include <cstring>
#include <iostream>
#include <set>
#include <deque>
using namespace std;

int n, m;
bool    visit[20001];
set<int>    g_dist[20000];
set<int>    graph[20001];

void input();
void solve();

int main() {
    input();
    solve();
    return 0;
}

void solve() {
    deque<int> queue;
    queue.push_back(1);
    visit[1] = true;
    int _dist = -1;
    int around_size = 1;

    while (queue.size()) {
        _dist++;
        for (int i = 0; i < around_size; ++i) {
            int tmp = queue.front();
            queue.pop_front();
            g_dist[_dist].insert(tmp);

            for (auto & b : graph[tmp]) {
                if (visit[b] == false) {
                    queue.push_back(b);
                    visit[b] = true;
                }
            }
        }
        around_size = queue.size();
    }

    cout << *(g_dist[_dist].begin()) << " " << _dist << " " << g_dist[_dist].size() << "\n";
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    memset(visit, false, sizeof(visit));
}