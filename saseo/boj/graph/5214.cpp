#include <cstring>
#include <iostream>
#include <set>
#include <deque>
using namespace std;

int n, k, m;
set<int> hyperTube[1000];
set<int> station[100001];
bool vertex_visit[100001];
bool tube_visit[1001];

void input();
int main() {
    input();
    deque<int> queue;
    queue.push_back(1);
    vertex_visit[1] = true;
    int layer_len = queue.size();
    int dist = 0;

    while (queue.size()) {
        dist++;
        while (layer_len--) {
            int cur_sts = queue.front();
            queue.pop_front();

            if (cur_sts == n) {
                cout << dist << "\n";
                return 0;
            }

            for (const int & tube : station[cur_sts]) {
                if (tube_visit[tube] == false) {
                    tube_visit[tube] = true;
                    for (int sts : hyperTube[tube]) {
                        if (vertex_visit[sts] == false) {
                            queue.push_back(sts);
                            vertex_visit[sts] = true;
                        }
                    }
                }
            }
        }
        layer_len = queue.size();
    }
    cout << "-1\n";

    return 0;
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> m;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            int sts;
            cin >> sts;
            station[sts].insert(i);
            hyperTube[i].insert(sts);
        }
    }
    memset(tube_visit, false, sizeof(tube_visit));
    memset(vertex_visit, false, sizeof(vertex_visit));
}