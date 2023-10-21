#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<bool> v(10, false);
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        v[numbers[i]] = true;
    }
    
    for (int i = 0; i < v.size(); ++i)
    {
        if (!v[i])
            answer += i;
    }
    
    return answer;
}