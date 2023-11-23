#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_multiset<string> hash;
    string answer = "";
    for (auto & p : participant)
        hash.insert(p);

    for (auto & c : completion)
    {
        auto found = hash.find(c);
        if (found != hash.end()){
            hash.erase(found);
        }
    }
    answer = *(hash.begin());
    return answer;
}
