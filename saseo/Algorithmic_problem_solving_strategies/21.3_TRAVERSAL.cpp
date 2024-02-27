#include <iostream>
#include <deque>
using namespace std;
#define RED "\033[31m"                /* Red */
#define RESET "\033[0m"

int tc, n;
deque<int> pre;
deque<int> in;
int pre_idx[1001];
int in_idx[1001];

void input();
void solve();
void input_case();
void print_post(pair<int, int> pre_range, pair<int, int> in_range);
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
        cout << RED;
        print_post(make_pair(0, n - 1), make_pair(0, n - 1));
        cout << RESET << "\n";
    }
}


void print_post(pair<int, int> pre_range, pair<int, int> in_range)
{
    if (pre_range.first == pre_range.second)
    {
        cout << pre[pre_range.first] << " ";
        return;
    }
    int root = pre[pre_range.first];
    int root_idx = in_idx[root];
    int left_len = root_idx - in_range.first;
    int right_len = in_range.second - root_idx;
    if (root_idx != in_range.first)
        print_post(make_pair(pre_range.first + 1, pre_range.first + left_len), make_pair(in_range.first, root_idx - 1));
    if (root_idx != in_range.second)
        print_post(make_pair(pre_range.first + left_len + 1, pre_range.second), make_pair(root_idx + 1, in_range.second));
    cout << root << " ";
}

void input_case()
{
    pre.clear();
    in.clear();
    cin >> n;
    int tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        pre.push_back(tmp);
        pre_idx[tmp] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        in.push_back(tmp);
        in_idx[tmp] = i;
    }
}

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> tc;
}


// 1
// 7
// 27 16 9 12 54 36 72
// 9 12 16 27 36 54 72

// 12 9 16 36 72 54 27