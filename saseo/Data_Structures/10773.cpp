#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;

int main()
{
	int	n;
	int	sum = 0;
	int	tmp;
	vector<int>	stack;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		if (tmp == 0)
		{
			sum -= stack.back();
			stack.pop_back();
		}
		else
		{
			sum += tmp;
			stack.push_back(tmp);
		}
	}
	cout << sum << endl;
	return 0;
}
