#include <iostream>
#include <map>
using namespace std;

int n, m;
map<int, int> tree;
uint64_t res;

void input();
void solve();

int main() {
    input();
    solve();
    cout << res << "\n";
    return 0;
}

void solve() {
    int max_tree_height = -(tree.begin()->first);
    uint64_t total = 0;
    uint64_t diff_acc = 0;
    uint64_t tree_num_acc = 0;

    for (map<int, int>::iterator h = tree.begin(); h != tree.end(); ++h) {
        int height = -h->first;
        tree_num_acc += h->second;
        if (height == 0) break;

        map<int, int>::iterator next = ++h;
        --h;
        int diff = height + next->first;
        uint64_t tmp_total = total + (diff * tree_num_acc);
 
        if (tmp_total == m) {
            res = max_tree_height - diff_acc - diff;
            return;
        } else if (tmp_total > m) {
            int remain_len = m - total;
            int len_per_tree = remain_len / tree_num_acc;
            if (remain_len % tree_num_acc > 0) ++len_per_tree;
            diff_acc += len_per_tree;
            res = max_tree_height - diff_acc;
            return;
        }

        total = tmp_total;
        diff_acc += diff;
    }
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int height;
        cin >> height;
        tree[-height] += 1;
    }
    tree[0] = 0;
}