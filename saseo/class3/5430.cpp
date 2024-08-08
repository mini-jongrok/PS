#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int t, n;
string func;
deque<string> arr;
bool isReversed = false;
int deleteNumber = 0;

void solve();
void doOperation();
void print();
void input();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}

void solve() {
    input();
    doOperation();
}

void doOperation() {
    for (int i = 0; i < func.size(); ++i) {
        char& op = func[i];
        if (op == 'R' && i < func.size() - 1 && func[i + 1] == 'R') {
            i++;
            continue;
        } else if (op == 'R') {
            isReversed = !isReversed;
        } else if (op == 'D' && arr.empty()) {
            cout << "error\n";
            return;
        } else if (op == 'D' && isReversed) {
            arr.pop_back();
        } else if (op == 'D') {
            arr.pop_front();
        }
    }
    print();
}

void print() {
    cout << "[";
    if (isReversed) {
        for (int i = arr.size() - 1; i >= 0; --i) {
            cout << arr[i];
            if (i != 0)
                cout << ",";
        }
    } else {
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i];
            if (i != arr.size() - 1)
                cout << ",";
        }
    }
    cout << "]\n";
}

void input() {
    isReversed = false;
    deleteNumber = 0;
    
    cin >> func >> n;
    arr.resize(n);
    char buff[10];
    string tmp = "";
    cin >> tmp;
    if (n == 0) return;

    int buff_idx = 0;
    int arr_idx = 0;
    for (int i = 1; i < tmp.size(); ++i) {
        if (tmp[i] == ',' || tmp[i] == ']') {
            string number(buff, buff_idx);
            arr[arr_idx++] = number;
            buff_idx = 0;
        } else {
            buff[buff_idx++] = tmp[i];
        }
    }
}