#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
bool    move(vector<string>& park, vector<int>& coordinate, const string& op);
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2, 0);
    
    // find Start point
    for (int h = 0; h < park.size(); ++h)
    {
        for (int w = 0; w < park[0].size(); ++w)
        {
            if (park[h][w] == 'S')
            {
                answer[0] = h;
                answer[1] = w;
                h += park.size();
                break;
            }
        }
    }
    
    for (string & dir : routes)
    {
        // need to optimize this solution
        vector<int> tmp = answer;
        vector<int> target = answer;
        int distance = atoi(&(dir[2]));
        bool move_flag = true;
    
        if (dir[0] == 'E')
            target[1] = answer[1] + distance;
        else if (dir[0] == 'W')
            target[1] = answer[1] - distance;
        else if (dir[0] == 'S')
            target[0] = answer[0] + distance;
        else if (dir[0] == 'N')
            target[0] = answer[0] - distance;
        
        // out of park range. do nothing, move to next.
        if (target[0] < 0 || target[1] < 0 ||\
            target[0] >= park.size() || target[1] >= park[0].size())
            continue;
        
        // if the target is in park range, check all the routes.
        for (int m = 1; m <= distance; ++m)
        {
            if (tmp[0] != target[0])
                tmp[0] = tmp[0] > target[0] ? answer[0] - m : answer[0] + m;
            else if (tmp[1] != target[1])
                tmp[1] = tmp[1] > target[1] ? answer[1] - m : answer[1] + m;

            if (park[tmp[0]][tmp[1]] == 'X')
            {
                move_flag = false;
                break;
            }
        }
        if (move_flag)
            answer = target;
    }
    return answer;
}

