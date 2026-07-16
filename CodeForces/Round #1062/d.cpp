#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <ranges>
using namespace std;

static constexpr size_t MAX_N = 1e5;
static array<uint64_t, MAX_N> a{};

// note the answer has to be one of these numbers
// the product of these 16 numbers is 32589158477190044730>1e18 (see https://oeis.org/A002110/list)
// in particular, any number under 1e18 can have at most 15 of these numbers as factors
// meaning one of these must be coprime to the input numbers, and hence the answer
static array<uint32_t, 16> first_16_primes{{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53}};

int main() {
  int t;
  cin >> t;

  map<uint64_t, uint32_t> prime_counts;
  for (const uint32_t x : first_16_primes) {
	prime_counts[x] = 0;
  }

  while (t--) {
	uint32_t n;
	cin >> n;
	for (uint32_t i = 0; i < n; i++) {
	  cin >> a[i];
	}
	// reset the prime counts
	for (auto& v : prime_counts | views::values) {
	  v = 0;
	}

	// x cannot be composite, as otherwise x = p_1^a_1p_2^a_2...p_n^a_n with p_1 < p_2 < ... < p_n, a_i != 0
	// if gcd(x,a) = 1, then gcd(p_1, a)=1, with p_1 < x, which is a contradiction to minimality of x
	// hence x must be prime

	// inshallah this loop is nsqrtn
	for (uint32_t i = 0; i < n; i++) {
	  // prime factorize a[i]
	  for (const uint32_t j : first_16_primes) {
		if (a[i] % j == 0) {
		  prime_counts[j]++;
		}
	  }
	}
	for (const auto [p, count] : prime_counts) {
	  if (count < n) {
		cout << p << endl;
		break;
	  }
	}
  }
}