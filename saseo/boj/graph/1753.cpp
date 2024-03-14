#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define INF 1000000
using namespace std;

int v, e, src;
map<int, int> graph[20001];

void input();
void solve();
int main()
{
    input();
    solve();
    return 0;
}

void solve() {
    //dijkstra
    vector<int> dist(v + 1, INF);
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, src));
    dist[src] = 0;

    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();

        int here = p.second;
        int cost = -(p.first);
        if (dist[here] < cost)
            continue;

        for (auto & edge : graph[here]) {
            int there = edge.first;
            int cur_cost = cost + edge.second;
            dist[there] = min(dist[there], cur_cost);
            q.push(make_pair(-cur_cost, there));
        }
    }

    for (int i = 1; i < v + 1; ++i) {
        if (dist[i] < INF) cout << dist[i] << "\n";
        else cout << "INF\n";
    }
}

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> v >> e >> src;
    int start, end, weight;
    for (int i = 0; i < e; ++i) {
        cin >> start >> end >> weight;
        map<int, int>::iterator itr = graph[start].find(end);
        if (itr == graph[start].end() || (itr != graph[start].end() && itr->second > weight))
            graph[start][end] = weight;
    }
}
