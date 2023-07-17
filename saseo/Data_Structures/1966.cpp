#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	int		testcase;
	deque<int>	idx;
	deque<int>	weight;

	cin >> testcase;

	while (testcase--)
	{
		int	target_idx;
		int	printed_num = 0;
		int	num;
	
		cin >> num >> target_idx;

		// save input
		for (int i = 0; i < num; ++i)
		{
			int tmp = 0;

			cin >> tmp;
			idx.push_back(i);
			weight.push_back(tmp);
		}

		while (weight.size())
		{
			if (weight.front() >= *max_element(weight.begin(), weight.end()))
			{
				weight.pop_front();
				printed_num++;
				if (idx.front() == target_idx)
					break ;
				idx.pop_front();
			}
			else
			{
				weight.push_back(weight.front());
				weight.pop_front();
				idx.push_back(idx.front());
				idx.pop_front();
			}
		}
		cout << printed_num << endl;
		// clear deques
		idx.clear();
		weight.clear();
	}
	return 0;
}
