#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    size_t  len = s.size();
    size_t  half = len / 2;
    if (len % 2 == 0)
    {
        answer  = s[half - 1];
        answer += s[half];
    }
    else
        answer = s[half];
    return answer;
}