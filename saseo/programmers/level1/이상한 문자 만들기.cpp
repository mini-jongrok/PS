#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    int word_idx = 0;
    
    for (int i = 0; i < s.size(); ++i)
    {
        if (isspace(s[i]))
        {
            word_idx = 0;
            continue;
        }
        if (word_idx % 2)
            s[i] = tolower(s[i]);
        else
            s[i] = toupper(s[i]);
        word_idx++;
    }
    answer = s;
    return answer;
}