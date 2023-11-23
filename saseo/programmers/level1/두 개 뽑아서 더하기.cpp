#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int>    tmp;
    for (int i = 0; i < numbers.size() - 1; ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
            tmp.insert(numbers[i] + numbers[j]);
    }
    
    for (auto & itr : tmp)
        answer.push_back(itr);
    return answer;
}