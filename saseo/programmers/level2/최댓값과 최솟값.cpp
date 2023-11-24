#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector<int> v;
    istringstream iss(s);
    while (!iss.eof())
    {
        int tmp;
        iss >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    ostringstream oss;
    oss << *(v.begin()) << " " << *(--(v.end()));
    return oss.str();
}
