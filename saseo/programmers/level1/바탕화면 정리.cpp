#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = {100, 100, -100, -100};
    
    for (int x = 0; x < wallpaper.size(); ++x)
    {
        for (int y = 0; y < wallpaper[0].size(); ++y)
        {
            if (wallpaper[x][y] == '#')
            {
                answer[0] = min(answer[0], x);
                answer[1] = min(answer[1], y);
                answer[2] = max(answer[2], x + 1);
                answer[3] = max(answer[3], y + 1);
            }
        }
    }
    
    return answer;
}

    // 좌표 : (x, y)
    // 가장 위 첫 번째 파일 위치 -> S(x)
    // 가장 왼쪽 첫 번째 파일 위치 -> S(y)
    // 가장 오른쪽 첫 번째 파일 위치 -> E(x)
    // 가장 아래쪽 첫 번째 파일 위치 -> E(y)

// ".#...",
// "..#..",
// "...#.";


