#include <iostream>

using namespace std;

int main() {
  int need_r, need_g, need_b;
  cin >> need_r >> need_g >> need_b;

  int has_r, has_g, has_b;
  cin >> has_r >> has_g >> has_b;

  need_r = max(0, need_r - has_r);
  need_g = max(0, need_g - has_g);
  need_b = max(0, need_b - has_b);

  int rg, gb;
  cin >> rg >> gb;

  if (need_r > rg) {
	goto fail;
  }
  rg -= need_r;
  // need_r = 0;
  if (need_b > gb) {
	goto fail;
  }
  gb -= need_b;
  // need_b = 0;
  if (need_g > rg + gb) {
	goto fail;
  }

  cout << need_r + need_g + need_b << endl;
  return EXIT_SUCCESS;
fail:
  cout << -1 << endl;
  return EXIT_SUCCESS;
}