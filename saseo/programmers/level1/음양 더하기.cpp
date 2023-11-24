#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int64_t ans = 0;
    
    for (int i = 0; i < absolutes.size(); ++i)
    {
        if (signs[i])
            ans += absolutes[i];
        else
            ans -= absolutes[i];
    }
    return static_cast<int>(ans);
}
