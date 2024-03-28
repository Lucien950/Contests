#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	int b[n];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	int rest = 2023;
	for (const int& i : b)
	{
		const int div = rest / i;
		if (div * i != rest)
		{
			cout << "NO" << endl;
			return;
		}
		rest = div;
	}

	// find k numbers which multiply to rest
	std::vector<int> outs;
	int              factors_left = k;
	for (int divisor = 2023; divisor >= 2 && rest != 1; divisor--)
	{
		// while the divisor is a factor of rest
		int test_rest = rest / divisor;
		while (test_rest * divisor == rest && rest != 1)
		{
			if (factors_left == 0)
			{
				cout << "NO" << endl;
				return;
			}
			outs.push_back(divisor);
			rest = test_rest;
			factors_left--;

			test_rest = rest / divisor;
		}
	}

	cout << "YES" << endl;
	for (int i = 0; i < k; i++)
	{
		if (i < outs.size())
			cout << outs[i] << " ";
		else
			cout << 1 << " ";
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}