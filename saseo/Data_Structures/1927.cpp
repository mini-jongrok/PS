#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int> > min_q;

	int num = 0;
	int	tmp = 0;

	cin >> num;
	while (num--)
	{
		int pop_num;

		cin >> tmp;
		if (tmp == 0 && min_q.size() > 0)
		{
			pop_num = min_q.top();
			min_q.pop();
		}
		else
			pop_num = 0;

		if (tmp != 0)
			min_q.push(tmp);
		else
			cout << pop_num << "\n";
	}
	return 0;
}
