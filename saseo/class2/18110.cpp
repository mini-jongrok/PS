#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
std::vector<int> opinion;

void input();
void solve();

int main() {
    input();
    solve();
    return 0;
}

void solve() {
    if (n == 0 ) {
        cout << "0\n";
        return;
    }
    int half = round(n * 0.15);
    int sum = 0;
    int tmpn = n - half;
    int tmphalf = half;

    while (tmpn--) {
        pop_heap(opinion.begin(), opinion.end());
        int tmp = opinion.back();
        opinion.pop_back();
        
        if (tmphalf) {
            tmphalf--;
            continue;
        }
        sum += tmp;
    }
    n -= half * 2;
    cout << round(sum / static_cast<double>(n)) << "\n";
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    make_heap(opinion.begin(), opinion.end());
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        opinion.push_back(tmp);
        push_heap(opinion.begin(), opinion.end());
    }
}