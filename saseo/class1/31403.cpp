#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;

    auto ia = stoi(a, nullptr, 10);
    auto ib = stoi(b, nullptr, 10);
    auto ic = stoi(c, nullptr, 10);
    cout << ia + ib - ic << "\n";

    string ab = a + b;
    auto iab = stoi(ab, nullptr, 10);
    cout << iab - ic << "\n";
}