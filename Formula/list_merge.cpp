#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main() {
  // First create an instance of an engine.
  random_device rnd_device;
  // Specify the engine and distribution.
  mt19937 mersenne_engine{rnd_device()}; // Generates random integers
  uniform_int_distribution<int> dist{1, 200};

  auto gen = [&dist, &mersenne_engine]() { return dist(mersenne_engine); };

  for (int test_num = 0; test_num < 100; test_num++) {
	vector<int> a(70 + rand() % 40), b(70 + rand() % 40);
	generate(begin(a), end(a), gen);
	generate(begin(b), end(b), gen);
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	int ai = 0, bi = 0;
	while (ai < a.size() && bi < b.size()) {
	  if (a[ai] == b[bi]) {
		ai++;
		bi++;
	  } else if (a[ai] < b[bi]) {
		a.erase(a.begin() + ai, a.begin() + ai + 1);
	  } else {
		a.insert(a.begin() + ai, b[bi]);
		ai++;
		bi++;
	  }
	}
	if (bi < b.size()) {
	  a.insert(a.end(), b.begin() + bi, b.end());
	} else if (ai < a.size()) {
	  a.erase(a.begin() + ai, a.end());
	}

	// print a, then b
	//	for (int i : a) {
	//	  cout << i << " ";
	//	}
	//	cout << endl;
	//	for (int i : b) {
	//	  cout << i << " ";
	//	}
	//	cout << endl;

	assert(a.size() == b.size());
	for (int i = 0; i < a.size(); i++) {
	  assert(a[i] == b[i]);
	}
	cout << "Test " << test_num << " is passing" << endl;
  }
}