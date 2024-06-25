#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int t, n, m;
int cache[10001];
vector<int> coin;
stringstream strstream;

void init();
void input();
void solve();
void print() {
	for (int i = 0; i < m + 1; ++i) {
		cout << cache[i] << " ";
	}
	cout << "\n";
}

int main() {
	init();
	for (int i = 0; i < t; ++i) {
		input();
		solve();
		strstream << cache[m] << "\n";
	}
	cout << strstream.str();
}

void solve() {
	for (int i = 0; i < n; ++i) {
		int x = 1;
		for (int money = coin[i]; money <= m; ++money) {
			cache[money] += cache[money - coin[i]];
			x++;
		}
	}
}

void input() {
	cin >> n;
	int tmp;
	coin.resize(0);
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		coin.push_back(tmp);
	}
	cin >> m;
	sort(coin.begin(), coin.end());
	memset(cache, 0, sizeof(cache));
	cache[0] = 1;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
}