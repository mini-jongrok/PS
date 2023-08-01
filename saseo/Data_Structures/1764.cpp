#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string tmp;
	vector<string> lst;
	vector<string> ans;
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		lst.push_back(tmp);
	}

	sort(lst.begin(), lst.end());
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp;
		if (binary_search(lst.begin(), lst.end(), tmp))
			ans.push_back(tmp);
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << "\n";
	return 0;
}
