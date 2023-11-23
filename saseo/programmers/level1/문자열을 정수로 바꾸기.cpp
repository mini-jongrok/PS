#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    istringstream   iss(s);
    int answer = 0;
    iss >> answer;
    return answer;
}
