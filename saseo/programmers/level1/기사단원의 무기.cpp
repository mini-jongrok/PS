#include <vector>
using namespace std;
void    setDivisor(vector<int>& v);

int solution(int number, int limit, int power) {
    vector<int> divisor(number + 1, 0);
    setDivisor(divisor);
    int answer = 0;
    
    for (int i = 1; i < number + 1; ++i){
        if (divisor[i] > limit)
            answer += power;
        else
            answer += divisor[i];
    }
    return answer;
}

void    setDivisor(vector<int>& v){
    for (int i = 1; i < v.size(); ++i){
        for (int j = i; j < v.size(); j += i){
            v[j] += 1;
        }
    }
}
