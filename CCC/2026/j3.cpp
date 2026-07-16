#include <iostream>
using namespace std;

int score(const char c) {
  switch (c) {
  case 'R':
	return 0;
  case 'G':
	return 1;
  case 'B':
	return 2;
  default:
	throw std::runtime_error("Invalid color");
  }
}

int main() {
  std::string n, m;
  cin >> n >> m;
  auto n_at = n.begin(), m_at = m.begin();
  size_t nn = 0, mm = 0;
  while (n_at != n.end() && m_at != m.end()) {
	if (*n_at == *m_at) {
	  ++n_at;
	  ++m_at;
	  ++nn;
	  ++mm;
	  continue;
	}
	if (score(*m_at) == (score(*n_at) + 1) % 3) {
	  // n wins
	  ++m_at;
	  ++nn;
	} else {
	  // m wins
	  ++n_at;
	  ++mm;
	}
  }
  nn += distance(n_at, n.end());
  mm += distance(m_at, m.end());
  cout << nn << endl << mm << endl;
}