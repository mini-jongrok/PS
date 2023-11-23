#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    set<int> win_nums_set(win_nums.begin(), win_nums.end());
    vector<int> answer;
    int default_match = 0;
    int unknown = 0;

    for (int i = 0; i < lottos.size(); ++i){
        if (lottos[i] == 0)
            unknown++;
        else if(win_nums_set.find(lottos[i]) != win_nums_set.end())
            default_match++;   
    }
    int tmp = 7 - default_match - unknown;
    tmp = tmp == 7 ? 6 : tmp;
    answer.push_back(tmp);
    tmp = 7 - default_match;
    tmp = tmp == 7 ? 6 : tmp;
    answer.push_back(tmp);
    
    return answer;
}