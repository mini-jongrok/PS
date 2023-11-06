#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;
bool myComp(pair<int, double> a, pair<int, double> b);

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, double> stages_map;
    vector<pair<int, double> > answer_pair;
    
    for (int i = 0; i < stages.size(); ++i){
        stages_map[stages[i]] += 1;
    }
    
    double rate = 0;
    int m = stages_map[N + 1];
    for (int i = N; i > 0; --i){
        m += stages_map[i];
        if (m == 0)
            rate = 0;
        else
            rate = stages_map[i] / m;
        answer_pair.push_back(make_pair(i, rate));
    }
    
    sort(answer_pair.begin(), answer_pair.end(), myComp);
    for (auto & itr : answer_pair)
        answer.push_back(itr.first);
    return answer;
}

bool myComp(pair<int, double> a, pair<int, double> b){
    if (fabs(a.second - b.second) < numeric_limits<double>::min())
        return (a.first < b.first);
    return (a.second > b.second);
}
// 1 2 3 4 5 6;
// 1 3 2 1 0 1;

// 5 : 0 / (1 + 0) = 0;
// 4 : 1 / (1 + 0 + 1) = 1 / 2;
// 3 : 2 / (1 + 0 + 1 + 2) = 2 / 4;

