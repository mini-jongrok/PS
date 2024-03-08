#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

typedef struct _Node {
    bool is_checked;
    bool has_team;
    bool visit;
    int point;
} Node;

int t, n, ret;
deque<int> answer;
Node student[100001];

void input();
void input_and_build_graph();
void solve();
void bfs(int start);

int main()
{
    input();
    solve();
    return 0;
}

void solve() {
    for (int tc = 0; tc < t; ++tc)
    {
        input_and_build_graph();
        ret = n;
        for (int i = 1; i < n + 1; ++i)
        {
            if (student[i].is_checked == false)
                bfs(i);
        }
        answer[tc] = ret;
    }

    for (int & a : answer)
        cout << a << "\n";
}

void bfs(int start) {
    deque<int> q;
    q.push_back(start);
    student[start].visit = true;

    int child = student[start].point;
    while (student[child].visit == false) {
        student[child].visit = true;
        q.push_back(child);
        child = student[child].point;
    }
    q.push_back(child);

    int met = q.back();
    bool loop_end = false;
    while (q.size()) {
        int p = q.back();
        q.pop_back();
        if (p == met && student[met].is_checked == false) {
            student[p].has_team = true;
            ret--;
        } else if (p == met && student[met].is_checked == true) {
            loop_end = true;
        } else if (loop_end == false) {
            student[p].has_team = true;
            ret--;
        } else if (loop_end == true) {
            student[p].has_team = false;
        }
        student[p].is_checked = true;
    }
}

void input_and_build_graph()
{
    cin >> n;
    for (int i = 1; i < n + 1; ++i) {
        cin >> student[i].point;
        student[i].is_checked = false;
        student[i].has_team = false;
        student[i].visit = false;
    }
}

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> t;
    answer.resize(t);
}