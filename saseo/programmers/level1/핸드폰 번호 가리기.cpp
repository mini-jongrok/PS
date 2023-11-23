#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    
    size_t len = phone_number.length();
    int checker = 0;
    while (len--)
    {
        if (checker++ < 4)
            continue ;
        phone_number[len] = '*';
    }
    answer = phone_number;
    return answer;
}