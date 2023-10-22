#include <string>

using namespace std;

string solution(int n) {
    string  first = "수";
    string  complete = "수박";
    string answer = "";
    
    int tmp = n;
    while (n > 1)
    {
        answer += complete;
        n -= 2;
    }
    
    if (tmp % 2 == 1)
        answer += first;
        
    return answer;
}