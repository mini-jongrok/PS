#include <vector>
using namespace std;
void    make_sieve(vector<bool>& sieve);

int solution(vector<int> nums) {
    vector<bool> sieve(3001, true);
    make_sieve(sieve);
    int answer = 0;
    for (int i = 0; i < nums.size() - 2; ++i)
    {
        for (int j = i + 1; j < nums.size() - 1; ++j)
        {
            for (int k = j + 1; k < nums.size(); ++k)
            {
                int tmp = nums[i] + nums[j] + nums[k];
                if (sieve[tmp])
                    answer++;
            }
        }
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
