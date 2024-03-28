#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int c[n];
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        unsigned long long ans = c[0] - 1;
        for (int i = 0; i <= n - 2; i++)
        {
            if (c[i] < c[i + 1])
            {
                ans += c[i + 1] - c[i];
            }
        }
        cout << ans << endl;
    }
}
