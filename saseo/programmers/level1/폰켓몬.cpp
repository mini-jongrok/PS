#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int>    poketmons(nums.begin(), nums.end());
    int answer = poketmons.size() > nums.size() / 2 ? nums.size() / 2 : poketmons.size();
    return answer;
}
