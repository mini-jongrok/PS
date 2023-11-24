#include <vector>

using namespace std;

void    make_sieve(vector<bool>& sieve);

int solution(int n) {
    vector<bool> sieve(n + 1, true);
    int answer = 0;
    make_sieve(sieve);
    
    for (int i = 1; i < sieve.size(); ++i)
    {
        if (sieve[i] == true)
            answer++;
    }
    return answer;
}

void    make_sieve(vector<bool>& sieve)
{
    sieve[1] = false;
    for (int i = 2; i < sieve.size(); ++i)
    {
        for (int j = 2 * i; j <sieve.size(); j += i)
            sieve[j] = false;
    }
}
