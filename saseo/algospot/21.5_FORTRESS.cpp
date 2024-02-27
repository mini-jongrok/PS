#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct _p {
    int x;
    int y;
    int r;
    int parent;
    deque<int> children;
} Circle;

int tc, n, Max;
deque<Circle> fortress;
bool visit[101];
deque<int> answers;

void input();
void input_case();
void solve();
void build_tree(int fortress_idx);
bool IsIn(Circle A, Circle B);
int dfs(int idx);
bool CircleCompare(Circle a, Circle b) {return (a.r > b.r);}

int main()
{
    input();
    solve();
    return 0;
}

void solve() {
    while (tc--)
    {
        input_case();
        if (n == 1)
        {
            answers.push_back(0);
            continue;
        }
        sort(fortress.begin(), fortress.end(), CircleCompare);
        build_tree(0);
        dfs(0);
        answers.push_back(Max);
    }

    for (auto & ans : answers)
        cout << ans << "\n";
}

int dfs(int idx)
{
    if (fortress[idx].children.empty())
        return 1;

    int first, second;
    first = 0;
    second = 0;

    for (auto & child : fortress[idx].children)
    {
        int tmp = dfs(child);
        if (tmp > first)
        {
            second = first;
            first = tmp;
        }
        else if (tmp > second)
            second = tmp;
    }
    Max = max(first + second, Max);
    return first + 1;
}

void build_tree(int parent)
{
    visit[parent] = true;
    for (int candi = parent + 1; candi < n; ++candi)
    {
        if (IsIn(fortress[parent], fortress[candi]) == true)
        {
            build_tree(candi);
            if (fortress[candi].parent == -1)
            {
                fortress[parent].children.push_back(candi);
                fortress[candi].parent = parent;
            }
        }
    }
}

bool IsIn(Circle A, Circle B)
{
    int dx = (A.x - B.x);
    int dy = (A.y - B.y);
    int dc_square = ((dx * dx) + (dy * dy));
    int dr_square = (A.r - B.r) * (A.r - B.r);
    if (dc_square > dr_square)
        return false;
    else if (dc_square < dr_square)
        return true;
    return false;
}

void input_case()
{
    fortress.clear();
    Max = -1;
    memset(visit, false, sizeof(visit));
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        Circle tmp;
        cin >> tmp.x >> tmp.y >> tmp.r;
        tmp.parent = -1;
        fortress.push_back(tmp);
    }
}

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> tc;
}