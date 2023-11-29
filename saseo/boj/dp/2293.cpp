#include <iostream>
#include <cstring>

using namespace std;

int n, k;
int coin[1000];
int cache[10001];
void dp();

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> coin[i];
	dp();
	cout << cache[k] << "\n";
	return 0;
}

void dp()
{
	cout << "* cache[j] = cache[j] + cache[j - coin[i]]\n";
	cache[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = coin[i]; j <= k; ++j)
		{
			cout << "(" << i << ", " << j << ") " << " coin[" << i << "] " << coin[i] << ", ";
			cout << "cache[" << j << "] " << cache[j] << ", cache[" << j - coin[i] << "] : " << cache[j - coin[i]] << " = ";
			cache[j] = cache[j] + cache[j - coin[i]];
			cout << cache[j] << "\n";
		}
		cout << "\n";
	}
}
