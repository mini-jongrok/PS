#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    set<string> report_set(report.begin(), report.end()); // 중복 제거
    map<string, set<string> > ids;
    map<string, int> reported_num;

    for (auto id : id_list) reported_num[id] = 0;

    for (auto r : report_set)
    {
        istringstream iss(r);
        string user_id, reported_id;
        iss >> user_id >> reported_id;
        reported_num[reported_id] += 1;
        (ids[user_id]).insert(reported_id);
    }
    
    for (string id : id_list)
    {
        if (ids.find(id) == ids.end())
        {
            answer.push_back(0); continue;
        }

        int num = 0;
        for (string reported : ids[id])
        {
            if (reported_num[reported] >= k)
                num++;
        }
        answer.push_back(num);
    }

    return answer;
}
