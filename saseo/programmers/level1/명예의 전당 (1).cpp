#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> heap;
    for (int i = 0; i < score.size(); ++i)
    {
        heap.push_back(-score[i]);
        push_heap(heap.begin(), heap.end());
        if (heap.size() > k)
        {
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }
        answer.push_back(-heap.front());
    }
    return answer;
}