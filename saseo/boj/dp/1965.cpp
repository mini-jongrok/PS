#include <iostream>
#include <cstring>
using namespace std;

int n;
int box[1001];
int cache[1001];

void input();
void solve();
int main()
{
    input();
    solve();
    return 0;
}

void solve() {
    int global_max = 1;
    cache[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i)
    {
        int temp = 1;
        for (int next = i + 1; next < n; ++next)
        {
            if (box[i] < box[next])
                temp = max(temp, 1 + cache[next]);
        }
        cache[i] = temp;
        global_max = max(global_max, temp);
    }

    cout << global_max << "\n";
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> box[i];
    //memset(cache, -1, sizeof(cache));
}