#include <iostream>
#include <queue>
#include <unordered_map>

struct node_weight {
  int node;
  int weight_to_arrive;
};

/**
 * Identifies the furthest node in the connected component from start
 * @param start uh
 * @param explored whether or not you've explored a node
 * @param neighbours neighbour lists
 * @note This algorithm will (in explored) mark all elements in the connected component
 * @return
 */
std::pair<int, std::vector<int>> furthest_node(const int at, std::vector<bool>& explored,
                                               const std::unordered_map<int, std::vector<node_weight>>& neighbours) {
  // explored = added to queue
  for (const node_weight& neighbour : neighbours.at(at)) {
  }
}

std::pair<int, std::vector<int>> furthest_node(const int start, const size_t N,
                                               const std::unordered_map<int, std::vector<node_weight>>& neighbours) {
  std::vector explored(N, false);
  return furthest_node(start, explored, neighbours);
}

int get_diameter(const int at, std::vector<bool>& explored,
                 const std::unordered_map<int, std::vector<node_weight>>& neighbours) {
  const auto [start, _weights_to_start] = furthest_node(at, explored, neighbours);
  const auto [end, weights] = furthest_node(start, explored.size(), neighbours);
  const int a = 0, x = 0, b = 0; // a is the

  return a + x;
}

/**
 * @param N: number of billabongs
 * @param M: number of trails that already exist
 * @param L: Time in days that it takes serpent to travel along a new trail
 * @param A, B: trail joined from A[i] to B[i] (of length M)
 * @param T: takes T[i] days to travel (of length M)
 * @returns greatest time between any pair of billabongs
 */
int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
  std::unordered_map<int, std::vector<node_weight>> neighbours;
  for (int i = 0; i < M; i++) {
	neighbours[A[i]].push_back({B[i], T[i]});
	neighbours[B[i]].push_back({A[i], T[i]});
  }

  std::vector explored(N, false);
  std::priority_queue<int, std::vector<int>, std::greater<>> top_3_diameters; // smallest item at the top of queue
  for (int i = 0; i < N; i++) {
	if (explored[i])
	  continue;
	explored[i] = true;
	int diameter_of_disjoint = get_diameter(i, explored, neighbours);
	top_3_diameters.push(diameter_of_disjoint);
	if (top_3_diameters.size() > 3) {
	  top_3_diameters.pop(); // pops top (smallest item)
	}
  }

  int out = 0;
  for (int i = 0; i < 2 && !top_3_diameters.empty(); i++) { // all you can take, limit 2
	out += top_3_diameters.top();
	top_3_diameters.pop();
  }
  return out + 2 * L;
}

int main() {
  std::cout << "got: "
            << travelTime(12, 8, 2, new int[]{0, 8, 2, 5, 5, 1, 1, 10}, new int[]{8, 2, 7, 11, 1, 3, 9, 6},
                          new int[]{4, 2, 4, 3, 7, 1, 5, 3})
            << std::endl;
  std::cout << "expected: 18" << std::endl;
}