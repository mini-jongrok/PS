#include <string>
#include <sstream>

using namespace std;

string atoi_base(int n, int base);

int solution(int n) {
    int answer = 0;
    string  toTri = atoi_base(n, 3);
    string  tmp = "";
    for (int i = toTri.size() - 1; i >= 0; --i)
        tmp += toTri[i];
    
    answer = stoi(tmp, nullptr, 3);
    return answer;
}

string atoi_base(int n, int base)
{
    string  ans = "";
    while (n)
    {
        char r = n % base + '0';
        ans = r + ans;
        n /= base;
    }
    return ans;
}