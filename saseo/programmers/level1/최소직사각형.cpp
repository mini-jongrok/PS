#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w_max = 0;
    int h_max = 0;

    for (auto itr : sizes)
    {
        sort(itr.rbegin(), itr.rend());
        w_max = (itr[0] > w_max) ? itr[0] : w_max;
        h_max = (itr[1] > h_max) ? itr[1] : h_max;
    }
    answer = w_max * h_max;
    return answer;
}