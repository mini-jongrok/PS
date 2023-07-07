/*
   1)
   hash map 을 이용한 누군가의 풀이.
   참고로,	c 와 c++의 버퍼를 동기화시켜주는 작업을 취소하고(ios::sync_with_stdio(false))
   		cout 과 cin을 묶어주는 (다른 작업을 하기 전에 버퍼를 비워주는) 것을 취소하면(cin.tie(0))
   시간 초과 없이 잘 통과한다고 한다.
   하지만 위의 두 과정을 빼면 시간초과가 난다고 함.
   이는 O(logN)이 O(1) 보다 빠른 문제 케이스이기 때문.
   */

/*
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map <int, int> m;
int N, M, card;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> card;
		m[card]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> card;
		cout << m[card] << " ";
	}
}
*/

/*
   upper_bound, lower_bound 라는 함수는 이분탐색을 통해 값을 찾아준다.
   이를 이용해 카드가 총 몇 개 있는지 확인해줄 것이다.
   이분탐색을 해야하므로 이전에 미리 sort를 해주어야 한다.
   */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    
    cin >> T;
    vector<int> v(T);

    for (int i = 0; i < T; i++)
	    cin >> v[i];
    
    sort(v.begin(), v.end());
    cin >> T;

    vector<int> answer(T);
    for (int i = 0; i < T; i++) 
    {
        cin >> K;
        auto upper = upper_bound(v.begin(), v.end(), K);
        auto lower = lower_bound(v.begin(), v.end(), K);

        answer[i] = upper - lower;
    }

    for (auto n : answer)
        cout << n << " ";
        
    return 0;
}
