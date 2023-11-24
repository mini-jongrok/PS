#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;

    int a = (n > m) ? n : m;
    int b = (n > m) ? m : n;
    int r = 1;
    
    while (a % b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    answer.push_back(b);
    answer.push_back(n * m / b);
    return answer;
}