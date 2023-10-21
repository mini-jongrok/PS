#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int i;

    for (i = 0; i < seoul.size(); ++i)
    {
        if (seoul[i].compare("Kim") == 0)
            break ;
    }
    
    ostringstream oss;
    oss << "김서방은 " << i << "에 있다";
    answer = oss.str();
    
    return answer;
}
