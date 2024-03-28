#include <cmath>
#include <iostream>

using namespace std;

constexpr long long m = 1e9 + 7;

#define MOD(x) (((x) % m + m) % m)

template <typename T> T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
	if (exp & 1)
	  result = (result * base) % modulus;
	base = (base * base) % modulus;
	exp >>= 1;
  }
  return result;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	long long arrLen, opCount;
	cin >> arrLen >> opCount;

	long long a[arrLen], psa[arrLen], arrSum = 0;
	for (int i = 0; i < arrLen; i++) {
	  cin >> a[i];
	  arrSum += a[i];
	}
	psa[0] = a[0];
	for (int i = 1; i < arrLen; i++)
	  psa[i] = psa[i - 1] + a[i];

	long long largestSubArraySum = 0;
	long long min_agg = 0;
	for (int i = 0; i < arrLen; i++) {
	  largestSubArraySum = max(largestSubArraySum, psa[i] - min_agg);
	  min_agg = min(min_agg, psa[i]);
	}

	// true value : (arrSum + largestSubArraySum * (2^opCount - 1)) % m
	// step 1: (arrSum % m + largestSubArraySum * (2^opCount - 1) % m) % m
	// step 2: (arrSum % m + largestSubArraySum % m * (2^opCount - 1) % m) % m
	// step 2: (arrSum % m + largestSubArraySum % m * ((2^opCount % m) - 1) % m) % m
	const long long addComponent = MOD(MOD(largestSubArraySum) * MOD(modpow(2ll, opCount, m) - 1));
	cout << MOD(MOD(arrSum) + addComponent) << endl;
  }
}