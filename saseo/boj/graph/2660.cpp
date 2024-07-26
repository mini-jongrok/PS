#include <cstring>
#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;

int n, score;
vector<int> graph[52];
bool visit[52];
map<int, vector<int> > candi; // <score, candi_numbers>

void    input();
void    solve();
int     bfs(int);

int main() {
    input();
    solve();
    return 0;
}

void solve() {
    score = n + 1;
    for (int i = 1; i <= n; ++i) {
        memset(visit, false, sizeof(visit));
        int cur_score = bfs(i);
        candi[cur_score].push_back(i);
        if (cur_score < score)
            score = cur_score;
    }

    cout << score << " " << candi[score].size() << "\n";
    for (auto & c : candi[score]) {
        cout << c << " ";
    }
    cout << "\n";
}

int bfs(int start) {
    deque<int> q;
    q.push_back(start);
    visit[start] = true;
    int around_len = q.size();
    int depth = 0;

    while (q.size()) {
        depth++;
        while (around_len--) {
            int p = q.front();
            q.pop_front();

            for (auto around : graph[p]) {
                if (visit[around] == false) {
                    q.push_back(around);
                    visit[around] = true;
                }
            }
        }
        around_len = q.size();
    }
    return depth - 1;
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    int a, b;
    cin >> a >> b;
    while (!(a == -1 && b == -1)) {
        graph[a].push_back(b);
        graph[b].push_back(a);
        cin >> a >> b;
    }
}