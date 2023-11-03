#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int pointer1 = 0;
    int pointer2 = 0;
    
    for (int i = 0; i < goal.size(); ++i)
    {
        if (pointer1 < cards1.size() && goal[i].compare(cards1[pointer1]) == 0)
            pointer1++;
        else if (pointer2 < cards2.size() && goal[i].compare(cards2[pointer2]) == 0)
            pointer2++;
        else
            return "No";
    }
    return answer;
}