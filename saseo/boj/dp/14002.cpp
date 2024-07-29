#include <iostream>

using namespace std;

int n, dp_max, max_idx;
int dp[1001];
int arr[1001];

void input();
void solve();
void dp_func();
void print();

int main() {
    input();
    solve();
}

void solve() {
    dp_func();
    print();
}

void dp_func() {
    dp_max = 1;
    max_idx = 0;
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        int max = 0;
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i] && dp[j] > max)
                max = dp[j];
        }
        dp[i] += max + 1;
        if (max + 1 > dp_max) {
            max_idx = i;
            dp_max = max + 1;
        }
    }
}

void print() {
    int tmp[1001];

    tmp[dp_max] = arr[max_idx];
    int cur_idx = max_idx - 1;
    for (int len = dp_max - 1; len > 0; --len) {
        while (arr[cur_idx] >= tmp[len + 1] || dp[cur_idx] != len)
            cur_idx--;
        tmp[len] = arr[cur_idx];
    }

    cout << dp_max << "\n";
    for (int i = 1; i < dp_max + 1; ++i)
        cout << tmp[i] << " ";
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
}