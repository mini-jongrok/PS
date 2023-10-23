#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    int idx = 0;
    while (idx < a.size())
    {
        answer += a[idx] * b[idx];
        idx++;
    }
    return answer;
}