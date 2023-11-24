#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool	comp(const string& a, const string& b);
int	tmp = 0;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;;
    tmp = n;
    sort(answer.begin(), answer.end(), comp);
    return answer;
}

bool	comp(const string& a, const string& b)
{
    if(a[tmp] == b[tmp])
        return (a < b);
    return a[tmp] < b[tmp];
}