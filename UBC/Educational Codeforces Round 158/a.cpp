#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int gasStationCount, dist;
        cin >> gasStationCount >> dist;
        int gasStations[gasStationCount];
        for (int i = 0; i < gasStationCount; i++)
        {
            cin >> gasStations[i];
        }

        int maxGap = gasStations[0];
        for (int i = 1; i < gasStationCount; i++)
        {
            maxGap = max(maxGap, gasStations[i] - gasStations[i - 1]);
        }

        maxGap = max(maxGap, 2 * (dist - gasStations[gasStationCount - 1]));

        cout << maxGap << endl;
    }
}
