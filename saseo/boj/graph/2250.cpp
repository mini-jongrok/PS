#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef struct Node {
    int left;
    int right;
    int level;
    int col;
} Node;

int n, column, max_level;
vector<Node> tree;
bool find_root[10001];
int width[2][10001];

void input();
void solve();
void traverse(int idx, int level);
void test_print(int idx);
int main()
{
    input();
    solve();
    return 0;
}

void solve()
{
    column = 1;
    max_level = 0;
    memset(width[0], 20000, sizeof(width) / 2);
    memset(width[1], -1, sizeof(width) / 2);
	int root = -1;
	for (int i = 1; i < n + 1; ++i)
	{
		if (find_root[i] == true)
		{
			root = i;
			break;
		}
	}

    traverse(root, 1);
    int level = -1;
    int max_width = -1;
    for (int i = 1; i < max_level + 1; ++i) {
        int tmp = width[1][i] - width[0][i] + 1;
        if (max_width < tmp)
        {
            level = i;
            max_width = tmp;
        }
    }
    cout << level << " " << max_width << "\n";
}

void traverse(int idx, int level)
{
    tree[idx].level = level;
    if (tree[idx].left != -1)
        traverse(tree[idx].left, level + 1);

    tree[idx].col = column++;
    width[0][level] = min(width[0][level], tree[idx].col);
    width[1][level] = max(width[1][level], tree[idx].col);

    if (tree[idx].right != -1)
        traverse(tree[idx].right, level + 1);

    max_level = max(level, max_level);
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    tree.resize(n + 1);
	memset(find_root, true, sizeof(find_root));
    for (int i = 1; i < n + 1; ++i) {
		int parent, left, right;
        cin >> parent >> left >> right;
		tree[parent].left = left;
		tree[parent].right = right;
		find_root[left] = false;
		find_root[right] = false;
    }
}

// 17
// 14 -1 -1
// 10 -1 -1
// 11 -1 -1
// 12 16 17
// 17 -1 -1
// 7 11 12
// 8 -1 -1
// 9 -1 -1
// 1 7 13
// 4 -1 -1
// 5 3 1
// 2 15 8
// 16 -1 -1
// 6 4 10
// 13 -1 9
// 3 2 6
// 15 13 14

// -> 4 17