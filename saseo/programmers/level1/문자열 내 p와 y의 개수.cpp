#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int p = 0;
    int y = 0;
    
    for (int i = 0; i < s.size(); ++i)
    {
        char    tmp = s[i];
        if (tmp == 'p' || tmp == 'P')
            p++;
        if (tmp == 'y' || tmp == 'Y')
            y++;
    }
    
    if (p != y)
        answer = false;

    return answer;
}
