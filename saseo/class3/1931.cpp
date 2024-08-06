#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<pair<int, int> > meeting;
vector<int> cache;

void input();
void solve();
int main() {
    input();
    solve();
    return 0;
}

void solve() {
    for (int i = n - 1; i >= 0; --i) {
        int & ret = cache[i];

        auto curr = meeting.begin() + i;
        auto next = lower_bound(curr + 1, meeting.end(), curr->second,
        [](const pair<int, int>& meeting, int value) {
            return meeting.first < value;
        });
        if (next != meeting.end() && next != curr) {
            ret = cache[static_cast<int>(next - meeting.begin())] + 1;
        } else
            ret = 1;
        ret = max(ret, cache[i + 1]);
    }

    sort(cache.begin(), cache.end());
    cout << cache.back() << "\n";
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    meeting.resize(n);
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        meeting[i] = make_pair(start, end);
    }
    sort(meeting.begin(), meeting.end());
    cache.resize(n + 1, -1);
    cache[n] = 0;
}