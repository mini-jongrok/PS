#include <string>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long i_p = stoll(p);
    long long tmp;
    int loop = t.size() - p.size() + 1;
    
    for (int i = 0; i < loop; ++i)
    {
        string sub = t.substr(i, p.size());
        tmp = stoll(sub);
        if (tmp <= i_p)
            answer++;
    }
    return answer;
}