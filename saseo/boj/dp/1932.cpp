#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int tri[500][500];
int cache[500][500];

int getMaxRoute(const int& n, int h, int w);
int main()
{
	int n;
	cin >> n;
	memset(tri, 0, sizeof(tri));
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			int tmp;
			cin >> tmp;
			tri[i][j] = tmp;
		}
	}
	cout << getMaxRoute(n, 0, 0) << "\n";
	return 0;
}

int getMaxRoute(const int& n, int h, int w)
{
	// base
	if (h == n - 1) return tri[h][w];

	int& ret = cache[h][w];
	if (ret != -1) return ret;

	ret = max(getMaxRoute(n, h + 1, w), getMaxRoute(n, h + 1, w + 1));
	return ret;
}
