#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <queue>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#define INF 1000000
using namespace std;

int v, e, src;
map<int, int> graph[20001];
vector<int> dist(20001, INF);

void input();
void output();
void solve();
int main()
{
    input();
    solve();
    output();
    return 0;
}

void output() {
    char *w = (char*) malloc(sizeof(char) * (v+1) *8);
    if (!w)
        exit(1);

    char *q = w;
    auto WriteInt = [&](int n) {
    int sz = 1, t = n;
    for (; t >= 10; t /= 10) sz++;
    for (int i = sz; i --> 0; n /= 10) q[i] = n % 10 | 48;
    q += sz;
    };

    for (int i = 1; i < v + 1; ++i) {
        if (dist[i] < INF) WriteInt(dist[i]), *q++ = '\n';
        else *q++ = 'I', *q++ = 'N', *q++ = 'F', *q++ = '\n';
    }
    write(1, w, q-w);
}

void solve() {
    //dijkstra
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
}

void input() {
    // FastIO
    struct stat _st; fstat(0, &_st);
    char *p = (char*)mmap(0, _st.st_size, PROT_READ, MAP_SHARED, 0, 0);
	auto ReadInt = [&]() {
		int ret = 0;
		for (char c = *p++; c & 16; ret = 10 * ret + (c & 15), c = *p++);
		return ret;
	};
	char w[1 << 17], *q = w;
    auto WriteInt = [&](int n) {
        int sz = 1, t = n;
        for (; t >= 10; t /= 10) sz++;
        for (int i = sz; i --> 0; n /= 10) q[i] = n % 10 | 48;
        q += sz;
    };
	v = ReadInt(), e = ReadInt(), src = ReadInt();
	int start, end, weight;
	for (int i = 0; i < e; ++i) {
		start = ReadInt(), end = ReadInt(), weight = ReadInt();
		map<int, int>::iterator itr = graph[start].find(end);
		if (itr == graph[start].end() || (itr != graph[start].end() && itr->second > weight))
			graph[start][end] = weight;
	}
}
