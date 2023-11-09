#include <string>
#include <vector>

using namespace std;
typedef std::string::size_type size;

bool isValid(vector<string> pron, string word);
int getPronIdx(const vector<string>& pron, const string& word);

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> pron = {"aya", "ye", "woo", "ma"};
    for (int i = 0; i < babbling.size(); ++i){
        if (isValid(pron, babbling[i]))
            answer++;
    }
    return answer;
}

bool isValid(vector<string> pron, string word){
    vector<int> pron_used_idx(pron.size(), -2);
    int idx = -1;
    for (int i = 0; word.size(); ++i){
        idx = getPronIdx(pron, word);
        if (idx < 0)
            return false;
        if (pron_used_idx[idx] + 1 == i)
            return false;
        pron_used_idx[idx] = i;
        word = word.substr(pron[idx].size(), word.size() - pron[idx].size());
    }
    return true;
}

int getPronIdx(const vector<string>& pron, const string& word){
    for (int i = 0; i < pron.size(); ++i){
        if (word.find(pron[i]) == 0)
            return i;
    }
    return -1;
}