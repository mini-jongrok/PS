#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <utility>
using namespace std;
#define MAX_DIST 1000

int t, n;
pair<int, int> coor[102];
vector<int> graph[102];
bool visit[102];
void input();
void solve();
bool bfs(int start);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}

void solve()
{
	input();
	//cennect nodes
	for (int i = 0; i < n + 1; ++i)
	{
		pair<int, int> cur = coor[i];
		for (int j = i + 1; j < n + 2; ++j)
		{
			pair<int, int> tmp = coor[j];
			int distance = abs(cur.first - tmp.first) + abs(cur.second - tmp.second);
			if (distance <= MAX_DIST)
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	//traverse
	if (bfs(0))
		cout << "happy\n";
	else
		cout << "sad\n";
}

bool bfs(int start)
{
	deque<int> q;
	q.push_back(start);
	visit[start] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop_front();
		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int child = graph[cur][i];
			if (child == n + 1)
				return true;
			if (visit[child] == false)
			{
				visit[child] = true;
				q.push_back(child);
			}
		}
	}
	return false;
}

void input()
{
	//input
	cin >> n;
	for (int i = 0; i < n + 2; ++i)
		cin >> coor[i].first >> coor[i].second;

	//initialize
	for (int i = 0; i < n + 2; ++i)
		graph[i].clear();
	memset(visit, false, sizeof(visit));
}
