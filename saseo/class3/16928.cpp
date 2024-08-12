#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
using ii = pair<int, int>;

map<int, int> ladder;
map<int, int> snake;
bool visit[101];
int start_point = 1;
int end_point = 100;

void input();
void solve();
int main() {
    input();
    solve();
    return 0;
}

void solve() {
    priority_queue<ii> q;
    vector<int> dist(101, 2147483647);
    q.push(make_pair(0, 1));
    int len = q.size();

    int tmp = 0;

    while(q.size()) {
        if (tmp++ > 100)
            break;
        ii cur = q.top();
        visit[cur.second] = true;
        q.pop();

        // cout << "pop (" << cur.second << " : " << -cur.first << ")\n";

        if (-cur.first > dist[cur.second]) {
            // cout << "\tbigger than dist[cur.first] = " << dist[cur.second] << ", continue\n";
            continue;
        }

        for (int i = 1; i < 7; ++i) {
            int next = cur.second + i;
            if (next > 100)
                break;

            if (visit[next] == true)
                continue;

            if (ladder.find(next) != ladder.end() && (ladder[next] <= end_point)) {
                next = ladder[next];
            } else if (snake.find(next) != snake.end() && (snake[next] >= start_point)) {
                next = snake[next];
            }
            if (dist[next] > -cur.first + 1) {
                dist[next] = min(dist[next], -cur.first + 1);
                q.push(make_pair(-dist[next], next));
                // cout << "\tpush (" << next << " : " << dist[next] << ")\n";
            }
        }
    }
    cout << dist[100] << "\n";
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, start, end;
    cin >> n >> m;
    while (n--) {
        cin >> start >> end;
        ladder.insert({start, end});
    }

    while (m--) {
        cin >> start >> end;
        snake.insert({start, end});
    }
}