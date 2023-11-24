#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> keys;

    for (auto & mapping : keymap){
        for (int i = 0; i < mapping.size(); ++i){
            auto iter = keys.find(mapping[i]);
            if (iter == keys.end() || iter->second > i + 1)
                keys[mapping[i]] = i + 1;
        }
    }
    
    for (auto & str : targets){
        int tmp = 0;
        for (int i = 0; i < str.size(); ++i){
            auto iter = keys.find(str[i]);
            if (iter == keys.end()){
                tmp = -1;
                break;
            }
            tmp += keys[str[i]];
        }
        answer.push_back(tmp);
    }
    return answer;
}
