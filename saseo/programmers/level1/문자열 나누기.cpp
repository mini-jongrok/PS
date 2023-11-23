#include <string>

using namespace std;
string getRemainder(string s);

int solution(string s) {
    int answer = 0;
    while (s.size()){
        s = getRemainder(s);
        answer++;
    }
    return answer;
}

string getRemainder(string s){
    char x = s[0];
    int appearance_x = 1;
    int appearance_other = 0;
    int len;

    for (len = 1; len < s.size(); ++len){
        if (appearance_x == appearance_other)
            break ;
        if (s[len] != x)
            appearance_other++;
        else
            appearance_x++;
    }

    return s.substr(len);
}
