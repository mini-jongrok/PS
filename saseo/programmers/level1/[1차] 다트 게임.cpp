#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

typedef enum {
    NONE,
    SCORE,
    BONUS,
    OPTION
} TYPE;

TYPE    getType(const char& c);
int     getPower(int a, int p);
int     getBonusPower(const char& c);

int solution(string dartResult) {
    vector<int> scores;
    char *str = dartResult.data();
    char c;
    int cur_score = 0;
    
    while (*str){
        TYPE type = getType(*str);
        if (type == SCORE)
            cur_score = (cur_score * 10) + (*str) - '0';
        else{
            if (type == BONUS)
                scores.push_back(getPower(cur_score, getBonusPower(*str)));
            if (type == OPTION){
                if (*str == '*') {
                    scores[scores.size() - 1] *= 2;
                    if (scores.size() > 1)
                        scores[scores.size() - 2] *= 2;
                }
                else if (*str == '#')
                    scores[scores.size() - 1] *= -1;
            }
            cur_score = 0;//initialize agin for the next stage
        }
        str++;
    }
    
    int answer = 0;
    for (auto & itr : scores)
        answer += itr;
    return answer;
}

int getPower(int a, int p){
    int ret = 1;
    while (p--)
        ret *= a;
    return ret;
}

int  getBonusPower(const char& c){
    if (c == 'S') return 1;
    if (c == 'D') return 2;
    if (c == 'T') return 3;
    return 0;
}

TYPE    getType(const char& c){
    if (isdigit(c) == true)
        return SCORE;
    if (c == 'S' || c == 'D' || c == 'T')
        return BONUS;
    if (c == '*' || c == '#')
        return OPTION;
    return NONE;
}