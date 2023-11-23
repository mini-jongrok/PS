#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string answer = new_id;
    
    // 1 && 2
    for (int i = 0; i < answer.size(); ++i)
    {
        answer[i] = tolower(answer[i]);
        if (!isalpha(answer[i]) && !isdigit(answer[i]) && \
            answer[i] != '-' && answer[i] != '_' && answer[i] != '.')
        {
            answer.erase(answer.begin() + i);
            i--;
        }
    }
    
    // 3
    bool dot_flag = false;
    for (int i = 0; i < answer.size(); ++i)
    {
        if (i == 0 && answer[i] == '.')
        {
            answer.erase(answer.begin());
            i--;
        }
        else if (dot_flag && answer[i] == '.')
        {
            answer.erase(answer.begin() + i);
            i--;
        }
        else if (!dot_flag && answer[i] == '.')
            dot_flag = true;
        else if (answer[i] != '.')
            dot_flag = false;
    }
    
    // 4
    if (answer[answer.size() - 1] == '.')
        answer.erase(answer.begin() + answer.size() - 1);
    
    // 5
    if (answer.size() == 0)
        answer = "a";
    
    // 6
    if (answer.size() > 15)
    {
        answer = answer.substr(0, 15);
        if (answer[answer.size() - 1] == '.')
            answer.erase(answer.size() - 1);
    } else if (answer.size() < 3)
    {
        char tmp = answer[answer.size() - 1];
        while (answer.size() < 3)
            answer += tmp;
    }
    return answer;
}
