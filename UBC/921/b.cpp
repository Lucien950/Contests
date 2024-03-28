#include <iostream>

using namespace std;

int main()
{
	int n, m, query_count;
	cin >> n >> m >> query_count;

	for (int query_num = 0; query_num < query_count; query_num++)
	{
		int query_type;
		cin >> query_type;
		if (query_type == 1)
		{
			int new_harbour_loc, new_harbour_value;
			cin >> new_harbour_loc >> new_harbour_value;
		}
		else
		{
			int left, right;
			cin >> left >> right;
		}
	}
}