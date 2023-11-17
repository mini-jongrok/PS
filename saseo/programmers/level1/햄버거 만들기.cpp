#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    stack<int>  patterns;
    patterns.push(-1);
    int answer = 0;

    for (int item : ingredient)
    {
        if (patterns.top() == 1 && item == 2)
            patterns.top() = 12;
        else if (patterns.top() == 12 && item == 3)
            patterns.top() = 123;
        else if (patterns.top() == 123 && item == 1)
        {
            patterns.pop();
            answer++;
        }
        else
            patterns.push(item);
    }
    return answer;
}
