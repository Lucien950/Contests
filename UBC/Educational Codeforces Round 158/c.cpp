#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

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

        const int maxA = *max_element(a, a + n), minA = *min_element(a, a + n),
                  gapA = maxA - minA;

        const int operations = ceil(log2(gapA + 1));
        cout << operations << endl;
        if (operations != 0 && operations <= n)
        {
            // cout << "DEBUG: ";
            const ull closestCeilPlateauStart = pow(2, operations) * ceil(minA / pow(2, operations)),
                      shifts = closestCeilPlateauStart - minA;
            cout << shifts;
            for (int i = 0; i < operations - 1; i++) cout << " " << 0;
            cout << endl;
        }
    }
}
