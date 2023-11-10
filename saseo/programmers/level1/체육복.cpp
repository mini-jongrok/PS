#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> students(n + 2, 1);

    for (auto & itr : lost)
        students[itr] = 0;
    
    for (auto & itr : reserve)
        students[itr] += 1;

    for (int i = 0; i < students.size() - 1; ++i){
        if (students[i] < 1){
            if (students[i - 1] > 1){
                students[i - 1] -= 1;
                students[i] = 1;
            }
            else if (students[i + 1] > 1){
                students[i + 1] -= 1;
                students[i] = 1;
            }
            else
                answer--;
        }
    }
    
    return answer;
}