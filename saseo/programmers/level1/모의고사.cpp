#include <algorithm>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    map<int, int> scores;
    vector<int> giveUp_1 = {1, 2, 3, 4, 5};
    vector<int> giveUp_2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> giveUp_3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    for (int i = 0; i < answers.size(); ++i)
    {
        scores[1] += (answers[i] == giveUp_1[i % giveUp_1.size()]) ? 1 : 0;
        scores[2] += (answers[i] == giveUp_2[i % giveUp_2.size()]) ? 1 : 0;
        scores[3] += (answers[i] == giveUp_3[i % giveUp_3.size()]) ? 1 : 0;
    }
    
    int max_id = (scores.begin()->second > (++scores.begin())->second) ? 1 : 2;
    max_id = scores[max_id] > scores[3] ? max_id : 3;
    answer.push_back(max_id);
    for (int i = 0; i < scores.size(); ++i)
    {
        if (i != max_id && scores[i] == scores[max_id])
            answer.push_back(i);
    }
    sort(answer.begin(), answer.end());
    return answer;
}
