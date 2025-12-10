#include <chrono>
#include <iostream>

int main() {
  const auto start = std::chrono::high_resolution_clock::now();
  double out = 0;
  for (int n = 0; std::chrono::high_resolution_clock::now() - start <= std::chrono::seconds(1); n++) {
	out += (n % 2 == 0 ? 1 : -1) / (2.0 * n + 1);
  }
  out *= 4;

  constexpr auto max_precision{std::numeric_limits<long double>::digits10 + 1};
  std::cout << std::setprecision(max_precision) << out << std::endl;
}