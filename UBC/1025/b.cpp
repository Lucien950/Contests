#include <iostream>

using namespace std;

int main() {
    int tCases;
    cin >> tCases;
    for (int caseNum = 0; caseNum < tCases; caseNum++) {
        int elementCount, composite;
        cin >> elementCount >> composite;

        int a[elementCount], minDistToComposite = INT_MAX;
        int smallestDistTo2 = INT_MAX, secondSmallestDistTo2 = INT_MAX;
        for (int i = 0; i < elementCount; i++) {
            cin >> a[i];
        }

        for (int i = 0; (i < elementCount && minDistToComposite != 0); i++) {
            int nearestFactor = (1 + ((a[i] - 1) / composite)) * composite; // ceil divison by composite, * composite
            int distToComposite = nearestFactor - a[i];
            minDistToComposite = min(minDistToComposite, distToComposite);

            if (composite == 4) {
                int nearestFactor2 = (1 + ((a[i] - 1) / 2)) * 2; // ceil divison by composite, * composite
                int distTo2Factor = nearestFactor2 - a[i];
                if (distTo2Factor < smallestDistTo2) {
                    secondSmallestDistTo2 = smallestDistTo2;
                    smallestDistTo2 = distTo2Factor;
                } else if (distTo2Factor < secondSmallestDistTo2) {
                    secondSmallestDistTo2 = distTo2Factor;
                }
            }
        }

        if (composite == 4) {
            minDistToComposite = min(minDistToComposite, smallestDistTo2 + secondSmallestDistTo2);
        }
        cout << minDistToComposite << endl;
    }
}