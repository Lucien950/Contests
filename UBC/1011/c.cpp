#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

int main() {
    ull q;
    cin >> q;
    ull pf1 = -1, pf2 = -1; // smallest and second smallest prime factors
    bool hasThreePlusPrimeFactors = false;
    for (ull i = 2; i <= (ull) floor(sqrt(q)); i++) {
        ull k = q;
        while (k != i && k % i == 0) {
            if (pf1 == -1ULL) {
                pf1 = i;
            } else if (pf2 == -1ULL) {
                pf2 = i;
            } else {
                hasThreePlusPrimeFactors = true;
                break;
            }
            k /= i;
        }
    }

    int primeFactorCount = (pf1 != -1ULL) + (pf2 != -1ULL) + hasThreePlusPrimeFactors;
    if (primeFactorCount == 0) {
        cout << 1 << endl << 0 << endl;
    } else if (primeFactorCount == 1) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl << pf1 * pf2 << endl;
    }
}