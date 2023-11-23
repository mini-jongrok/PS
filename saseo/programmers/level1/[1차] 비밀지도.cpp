#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; ++i)
    {
        string  line = "";
        int tmp = arr1[i] ^ arr2[i];
        for (int j = n - 1; j >= 0; --j)
        {
            if (!(tmp & (1 << j)))
            {
                if (arr1[i] & (1 << j))
                    line += "#";
                else
                    line += " ";
            }
            else
                line += "#";
        }
        answer.push_back(line);
    }
    return answer;
}