#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int		ans;
	string		tmp;
	char		top;

	getline(cin, tmp);
	while (tmp.compare(".") != 0)
	{
		stack<char>	pairs;
		ans = 1;
	
		for (int i = 0; i < tmp.length(); ++i)
		{
			if (tmp[i] == '(' || tmp[i] == '[')
				pairs.push(tmp[i]);
			if (tmp[i] == ')' || tmp[i] == ']')
			{
				if (pairs.size() < 1)
				{
					ans = 0;
					break;
				}
				top = pairs.top();
				pairs.pop();
				if ((tmp[i] == ')' && top == '[') ||\
				(tmp[i] == ']' && top == '('))
				{
					ans = 0;
					break;
				}
			}
		}
		if (pairs.size() != 0)
			ans = 0;
		if (ans)
			cout << "yes\n";
		else
			cout << "no\n";
		getline(cin, tmp);
	}

	return 0;
}
