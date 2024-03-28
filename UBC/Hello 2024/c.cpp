#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		vector<int> tops;
		for (int i = 1; i < n; i++)
		{
			if (a[i - 1] < a[i])
				tops.push_back(i);
		}

		int pen = tops.size() - 1;

		for (int i = 2; i < tops.size(); i++)
		{
			if (tops[i] < tops[i - 2])
				pen--;
		}

		cout << max(0, pen) << endl;
	}
}
