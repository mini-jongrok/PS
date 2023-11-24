#include <string>
#include <vector>

vector<long long> solution(int x, int n)
{
  vector<long long> answer;
  long long  tmp = x;
  while (n--)
  {
    answer.push_back(tmp);
    tmp += x;
  }
  return answer;
}
