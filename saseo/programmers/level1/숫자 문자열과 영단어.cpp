#include <string>
#include <map>
#include <iostream>

using namespace std;

int solution(string s) {
    map<string, string> alpha;
    string  tmp = "";
    int answer = 0;
    
    alpha["zero"] = "0";
    alpha["one"] = "1";
    alpha["two"] = "2";
    alpha["three"] = "3";
    alpha["four"] = "4";
    alpha["five"] = "5";
    alpha["six"] = "6";
    alpha["seven"] = "7";
    alpha["eight"] = "8";
    alpha["nine"] = "9";
    
    while (s.size())
    {
        if (isdigit(s[0]))
        {
            tmp += s[0];
            s = s.substr(1, s.size() - 1);
            continue;
        }
        
        map<string, string>::iterator   iter = alpha.begin();
        while (iter != alpha.end())
        {
            size_t  pos = s.find(iter->first);
            if (pos == 0)
            {
                int len = (iter->first).size();
                tmp += iter->second;
                s = s.substr(len, s.size() - len + 1);
                break;
            }
            iter++;
        }
    }
    
    answer = stoi(tmp);
    
    return answer;
}