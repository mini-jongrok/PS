#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    if (n % 2 == 1)
        return 2;

    for (int i = 3; i < n; i += 2)
    {
        if (n % i == 1)
            return i;
    }
    return answer;
}
