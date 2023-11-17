#include <string>
#include <set>

using namespace std;

string solution(string s, string skip, int index) {
    set<char> skip_set;
    string answer = s;
    string alphas = "abcdefghijklmnopqrstuvwxyz";
    
    for (int i = 0; i < skip.size(); ++i){
        int found = alphas.find(skip[i]);
        alphas.erase(alphas.begin() + found);
    }

    for (int i = 0; i < answer.size(); ++i){
        int cur_idx = alphas.find(answer[i]);
        answer[i] = alphas[(cur_idx + index) % alphas.size()];
    }
    return answer;
}
