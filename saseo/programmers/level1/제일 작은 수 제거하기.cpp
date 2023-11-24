#include <vector>
#include <limits>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if (arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
    
    int min = std::numeric_limits<int>::max();
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == min)
            continue ;
        
        answer.push_back(arr[i]);
    }
    return answer;
}