#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    vector<long long>   v;
    
    while(n)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < v.size(); ++i)
    {
        answer = answer * 10 + v[i];
    }
    return answer;
}
