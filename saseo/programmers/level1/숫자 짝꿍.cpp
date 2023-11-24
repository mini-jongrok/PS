#include <string>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    multiset<char> xs;
    multiset<int, greater<int> > common;
    bool only_zero = true;
    
    int tmp = 0;
    for (int i = 0; i < X.size(); ++i){
        tmp = X[i];
        xs.insert(tmp);
    }
    
    for (int i = 0; i < Y.size(); ++i){
        multiset<char>::iterator itr = xs.find(Y[i]);
        if (itr != xs.end()){
            if (Y[i] != '0')
                only_zero = false;
            common.insert(Y[i] - '0');
            xs.erase(itr);
        }
    }
    
    if (common.size() == 0)
        return "-1";
    if (only_zero)
        return "0";

    ostringstream oss;
    for (auto & itr : common){
        oss << itr;
    }
    
    answer = oss.str();
    return answer;
}

