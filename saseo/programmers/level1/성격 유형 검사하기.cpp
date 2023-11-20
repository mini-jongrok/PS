#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    vector<char> keys = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    map<char, int> indicator;
    
    for (char & k : keys)
        indicator[k] = 0;
    
    for (int i = 0; i < survey.size(); ++i)
    {
        if (choices[i] < 4)
            indicator[survey[i][0]] += (4 - choices[i]);
        else if (choices[i] > 4)
            indicator[survey[i][1]] += choices[i] - 4;
    }

    ostringstream oss;
    for (int i = 0; i < keys.size(); i += 2)
    {
        if (indicator[keys[i]] >= indicator[keys[i + 1]])
            oss << keys[i];
        else
            oss << keys[i + 1];
    }
    return oss.str();
}


// 1; [0] 3;
// 2; [0] 2;
// 3; [0] 1;
// 4; 0;
// 5; [1] 1;
// 6; [1] 2;
// 7; [1] 3;

// f(3) = 1;
// f(2) = 2;
// f(1) = 3;

// ax + b = 0;

// 3a + b = 1;
// 2a + b = 2;
// a = -1;

// -3 + b = 1;
// b = 4;

// a = -1;
// b = 4;

// f(x) = -x + 4;
// f(1) = 3;
// f(2) = 2;
// f(3) = 1;
