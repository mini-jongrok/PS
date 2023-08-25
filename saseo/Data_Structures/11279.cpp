#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int> > Q;

	int num = 0;
	int	tmp = 0;

	cin >> num;
	while (num--)
	{
		int pop_num;

		cin >> tmp;
		if (tmp == 0 && Q.size() > 0)
		{
			pop_num = Q.top();
			Q.pop();
		}
		else
			pop_num = 0;

		if (tmp != 0)
			Q.push(tmp);
		else
			cout << pop_num << "\n";
	}
	return 0;
}
