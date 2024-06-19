#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
vector<int> seq;
vector<pair<int, int> > quest;
int cache[2001][2001];

void input();
void solve();
bool dp(int, int);

int main() {
	input();
	solve();
	return 0;
}

void solve() {
	for (auto q : quest) {
		dp(q.first, q.second);
		cout << cache[q.first][q.second] << "\n";
	}
}

bool dp(int start, int end) {
	int &ret = cache[start][end];
	if (ret != -1 && ret == 0)
		return false;
	else if (ret != -1 && ret == 1)
		return true;

	if (start == end || start > end) {
		ret = 1;
		return true;
	}

	if (seq[start] == seq[end] && dp(start + 1, end - 1)) {
		ret = 1;
		return true;
	}
	ret = 0;
	return false;
}

void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	seq.resize(n + 1, 0);
	for (int i = 1; i < n + 1; ++i)
		cin >> seq[i];
	cin >> m;
	quest.resize(m);
	for (int i = 0; i < m; ++i)
		cin >> quest[i].first >> quest[i].second;
	memset(cache, -1, sizeof(cache));
}