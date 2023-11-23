#include <string>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i = 0; i < s.size(); ++i)
    {
        if (!isalpha(s[i]))
        {
            answer += s[i];
            continue;
        }
        char    tmp = islower(s[i]) ? 'a' : 'A';
        tmp += ((s[i] - tmp) + n) % 26;
        answer += tmp;
    }
    return answer;
}
/*
0   1       2           10
x (x + 1) (x + 2) ... (x + 10)
    

5 + 10
    
(x + 5) + 5 = (x + 10)
(x + 10) + 5 = x + (15 % 11) = x + 4
*/