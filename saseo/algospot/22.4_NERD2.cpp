#include <iostream>
#include <map>
#include <deque>
using namespace std;

int c, n;
map<int, int> tree;
deque<int> ans;

void input();
void solve();

int main()
{
    input();
    while (c--)
        solve();
    for (auto & a : ans)
        cout << a << "\n";
    return 0;
}

void solve() {
    tree.clear();
    map<int, int>::iterator itr;
    int key, value, sum;
    sum = 1;
    cin >> n >> key >> value;
    tree[key] = value;

    for (int i = 1; i < n; ++i)
    {
        cin >> key >> value;
        itr = tree.lower_bound(key);
        if (itr != tree.end() && itr->second > value) {
            sum += tree.size();
            continue;
        }

        map<int,int>::iterator  remove_begin = itr;
        while (remove_begin != tree.begin()) {
            remove_begin--;
            if (remove_begin->second > value) {
                remove_begin++;
                break;
            }
        }
        tree.erase(remove_begin, itr);
        tree[key] = value;
        sum += tree.size();
    }
    ans.push_back(sum);
}

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> c;
}

// 2
// 4
// 72 50
// 57 67
// 74 55
// 64 60
// 5
// 1 5
// 2 4
// 3 3
// 4 2
// 5 1