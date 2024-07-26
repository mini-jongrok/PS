#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool set[21];
int m;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

void solve() {
    cin >> m;
    string  _operator;
    int     operand;
    while (m--) {
        cin >> _operator;
        if (_operator.compare("all") == 0) {
            memset(set, true, sizeof(set));
            continue;
        } else if (_operator.compare("empty") == 0) {
            memset(set, false, sizeof(set));
            continue;
        }

        cin >> operand;
        if (_operator.compare("add") == 0)
            set[operand] = true;
        else if (_operator.compare("remove") == 0)
            set[operand] = false;
        else if (_operator.compare("toggle") == 0) {
            set[operand] = !set[operand];
        } else if (_operator.compare("check") == 0) {
            if (set[operand])
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
}