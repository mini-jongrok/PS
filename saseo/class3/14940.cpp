#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using namespace std;
typedef pair<int, int> point;

int n, m;
vector<int> map[1001];
vector<int> res[1001];
bool visit[1001][1001];
point start;

void input();
void solve();

int main() {
    input();
    solve();
    return 0;
}

void solve() {
    deque<point> q;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    q.push_back(start);
    visit[start.first][start.second] = true;
    res[start.first][start.second] = -1;
    int dist = 0;
    int bound = q.size();

    while(q.size()) {
        dist++;
        while (bound--) {
            point p = q.front();
            q.pop_front();

            for (int d = 0; d < 4; ++d) {
                point tmp = make_pair(p.first + dx[d], p.second + dy[d]);
                if (tmp.first < 0 || tmp.first >= n || tmp.second < 0 || tmp.second >= m || map[tmp.first][tmp.second] == 0)
                    continue;

                bool& visited = visit[tmp.first][tmp.second];
                if (visited == false) {
                    visited = true;
                    res[tmp.first][tmp.second] = dist;
                    q.push_back(tmp);
                }
            }
        }
        bound = q.size();
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int& d = res[i][j];
            int& val = map[i][j];
            if (d == 0 && val == 0) cout << "0 ";
            else if (d == 0) cout << "-1 ";
            else if (d == -1) cout << "0 ";
            else cout << d << " ";
        }
        cout << "\n";
    }
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        map[i].resize(m, 0);
        res[i].resize(m, 0);
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                start.first = i;
                start.second = j;
            }
        }
    }
}