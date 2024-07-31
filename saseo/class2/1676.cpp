#include <iostream>
#include <complex>
using namespace std;

int n;
int x[2];

void solve();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    solve();
    return 0;
}

void solve() {
    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 0) {
            int tmp = i;
            int tmp2 = 0;
            while (tmp % 2 == 0) {
                tmp2++;
                tmp /= 2;
            }
            x[0] += tmp2;
        }
        if (i % 5 == 0) {
            int tmp = i;
            int tmp5 = 0;
            while (tmp % 5 == 0) {
                tmp5++;
                tmp /= 5;
            }
            x[1] += tmp5;
        }
    }
    if (x[0] < x[1]) cout << x[0] << "\n";
    else cout << x[1] << "\n";
}