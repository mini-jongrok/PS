#include <string>
#include <algorithm>

using namespace std;

bool comp (char i,char j) { return (i > j); }

string solution(string s) {
    sort(s.begin(), s.end(), comp);
    return s;
}