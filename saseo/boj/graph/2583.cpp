#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

typedef pair<int, int> point;

enum STATUS {
    VOID,
    DRAW,
    VISIT
};

int m, n, k;
int paper[101][101];
vector<int> answers;

void input();
void solve();
int bfs(point p);
bool validatePoint(point p);
void print();

int main()
{
    input();
    solve();
    return 0;
}

void solve()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (paper[i][j] == VOID)
                answers.push_back(bfs(make_pair(i, j)));
        }
    }

    sort(answers.begin(), answers.end());
    cout << answers.size() << "\n";
    for (auto & a : answers)
        cout << a << " ";
}

int bfs(point p)
{
    int dn[] = {0, 0, 1, -1};
    int dm[] = {1, -1, 0, 0};
    int dir = (sizeof(dn) / sizeof(int));
    deque<point> q;
    q.push_back(p);
    paper[p.first][p.second] = VISIT;
    int ans = 0;
    while (q.size())
    {
        point cur = q.front();
        q.pop_front();
        ans++;
        for (int i = 0; i < dir; ++i)
        {
            point temp = make_pair(cur.first + dn[i], cur.second + dm[i]);
            if (validatePoint(temp) && paper[temp.first][temp.second] == VOID)
            {
                paper[temp.first][temp.second] = VISIT;
                q.push_back(temp);
            }
        }
    }
    return ans;
}

bool validatePoint(point p)
{
    if (p.first < 0 || p.first >= n || p.second < 0 || p.second >= m)
        return false;
    return true;
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;
    memset(paper, 0, sizeof(paper));
    for (int i = 0; i < k; ++i)
    {
        int sn, sm, en, em, tn, tm;
        cin >> sn >> sm >> en >> em;
        tn = sn;
        tm = sm;
        while (tn < en)
        {
            tm = sm;
            while (tm < em)
            {
                paper[tn][tm] = DRAW;
                tm++;
            }
            tn++;
        }
    }
}