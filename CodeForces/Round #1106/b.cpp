#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;

	uint64_t out = 0;
	// fix some b, which must divide both c and a, namely b | gcd(c,a) \iff (condition in question)
	for (int b = 1; b <= n; b++) {
	  // c must be a multiple of b, hence c = b * k, where k is an integer
	  // a must be a multiple of b, hence a = b * m, where m is an integer
	  // we need to count the number of pairs (k, m) such that 1 <= b*k <= n and 1 <= b*m <= n
	  // this means 1 <= k <= n/b and 1 <= m <= n/b
	  out += static_cast<uint64_t>(n / b) * static_cast<uint64_t>(n / b);
	}
	cout << out << endl;
  }
}

// "solve(unsigned int n)":
//   mov ecx, 1        // ecx := b = 1
//   xor esi, esi      // esi := out = 0
// .LOOP:
//   mov eax, edi      // eax := edi (== n)
//   xor edx, edx      // clear the top bits?
//   div ecx           // eax = (edx:eax == n) / b (== ecx)
//   add ecx, 1        // ecx = b += 1
//   imul rax, rax     // rax = (n / b) * (n / b)
//   add rsi, rax      // rsi = out += (n / b) * (n / b)
//   cmp edi, ecx      // compare n and b, loop if b <= n
//   jnb .LOOP
// .DONE:
//   mov rax, rsi      // return rsi
//   ret