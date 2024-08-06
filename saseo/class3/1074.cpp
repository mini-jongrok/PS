#include <cmath>
#include <iostream>
#include <utility>
using namespace std;
using pii = pair<int, int>;

int n, r, c;

void input();
int solve(pii top, int len);
int getRange(const pii *range);

int main() {
    input();
    int len = pow(2, n);
    cout << solve(make_pair(0, 0), len) << "\n";
    return 0;
}

int solve(pii top, int len) {
    if (len < 2)
        return 0;
    int half = len / 2;
    pii range[4];
    range[0] = top;
    range[1] = make_pair(top.first, top.second + half);
    range[2] = make_pair(top.first + half, top.second);
    range[3] = make_pair(range[2].first, range[1].second);

    int cur_range = getRange(range);
    int ret = cur_range * (half * half);
    int child_ret = solve(range[cur_range], half);

    return ret + child_ret;
}

int getRange(const pii *range) {
    int len = range[2].first - range[0].first;
    int ret = 0;
    if (r < range[2].first && c < range[1].second)
        ret = 0;
    else if (r < range[2].first && c >= range[1].second)
        ret = 1;
    else if (r >= range[2].first && c < range[1].second)
        ret = 2;
    else
        ret = 3;
    return ret;
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> r >> c;
}