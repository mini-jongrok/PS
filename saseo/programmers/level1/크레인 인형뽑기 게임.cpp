#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> front_idx;
    stack<int> basket;
    int answer = 0;
    
    for (int col = 0; col < board[0].size(); ++col)
    {
        for (int row = 0; row < board.size(); ++row)
        {
            if (board[row][col] != 0)
            {
                front_idx.push_back(row);
                break;
            }
        }
        if (front_idx.size() != col + 1)
            front_idx.push_back(board[0].size());
    }
    
    int line_size = board.front().size();
    for(auto & m : moves){
        m--;
        int idx = front_idx[m];
        if (idx == line_size)
            continue;
        
        int tmp_doll = board[idx][m];
        front_idx[m] += 1;
        
        if (basket.size() && basket.top() == tmp_doll){
            answer += 2;
            basket.pop();
        }
        else
            basket.push(tmp_doll);
    }
    return answer;
}

// |---------------|
// |0 1 2 3 4| idx |
// |---------|-----|
// |0 0 0 0 0|  0  |
// |0 0 1 0 3|  1  |
// |0 2 5 0 1|  2  |
// |4 2 4 4 2|  3  |
// |3 5 1 3 1|  4  |
// |---------------|

// initial top indices for each column
// 3 2 1 3 1

// 처음에 각 컬럼의 top 인덱스를 저장해두었기 때문에,
// 이후 각 탐색에서 O(1) 시간에 접근할 수 있다.
// 맨 처음 2중 반복문을 돌며 인덱스를 찾아내는 데에는 최악의 경우, 30 * 30 = 900회이다.
// 이후 어떤 칸에서 뽑을지가 담긴 배열 moves을 순회하며 board에서 지정된 칸에 있는 인형을 순차적으로 뽑아 스택에 담는다.
//     이때 스택의 top에 moves에서 뽑은 아이템과 동일한 아이템이 있으면 두 아이템은 사라진다.
//                                                   없으면 스택에 push한다.

// 결론적으로 : 900 + 1000 회가 최악의 경우임. O(N+M) 

