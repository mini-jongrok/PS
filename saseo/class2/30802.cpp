#include <iostream>
using namespace std;

int n;
int sizes[6];
int t, p;

int tres;

void input();
int main() {
    input();
    for (int i = 0; i < 6; ++i) {
        int tmp = sizes[i] / t;
        if (sizes[i] % t > 0) tmp++;
        tres += tmp;
    }
    cout << tres << "\n" << n / p << " " << n % p << "\n";
    return 0;
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < 6; ++i)
        cin >> sizes[i];
    cin >> t >> p;
}