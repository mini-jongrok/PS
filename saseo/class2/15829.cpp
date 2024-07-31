#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int l;
int Hash(string& str);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin >> l >> str;
    cout << Hash(str) << "\n";
    return 0;
}

int Hash(string& str) {
    long long H = 0;
    long long r = 1;
    int mod = 1234567891;

    for (int i = 0; i < l; ++i) {
        int tmp = static_cast<int>(str[i] - 'a') + 1;
        H += r * tmp;
        r *= 31;
        r %= mod;
    }
    return H % mod;
}