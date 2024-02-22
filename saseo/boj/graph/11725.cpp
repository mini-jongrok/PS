#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<int> graph[100001];
vector<int> tree;
bool visit[100001];

void input();
void solve();
void traverse(int parent);
int main()
{
    input();
    solve();
    return 0;
}

void solve()
{
    visit[1] = true;
    traverse(1);
    for (int i = 2; i < n + 1; ++i)
        cout << tree[i] << "\n";
}

void traverse(int parent)
{
    for (int & child : graph[parent]) {
        if (visit[child] == false) {
            tree[child] = parent;
            visit[child] = true;
            traverse(child);
        }
    }
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(visit, false, sizeof(visit));
    tree.resize(n + 1);
}