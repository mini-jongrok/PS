#include <algorithm>
#include <vector>

using namespace std;

bool    comp(const int& a, const int& b)
{
    return a > b;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), comp);
    for (int i = 0; i <= score.size(); i += m)
        answer += score[i - 1] * m;
    return answer;
}
