#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto & comm : commands)
    {
        vector<int> tmp(array.begin() + (comm[0] - 1), array.begin() + comm[1]);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[comm[2] - 1]);
    }
    return answer;
}