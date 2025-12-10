#include <vector>
using namespace std;

class Solution {
  /* note that
   * is_slope_equal(a,b,c,d) == is_slope_equal(c,d,a,b)
   * is_slope_equal(a,b,c,d) == is_slope_equal(b,a,c,d) == is_slope_equal(a,b,d,c) == is_slope_equal(b,a,d,c)
   */
  static bool is_slope_equal(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3,
                             const vector<int>& p4) {
	return (p2[1] - p1[1]) * (p4[0] - p3[0]) == (p4[1] - p3[1]) * (p2[0] - p1[0]);
  }

  static bool is_trapezoid(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3, const vector<int>& p4) {
	if (const bool could_be = is_slope_equal(p1, p2, p3, p4); !could_be)
	  return false;
	return !is_slope_equal(p1, p4, p2, p3) || !is_slope_equal(p1, p3, p2, p4);
  }

public:
  static int countTrapezoids(const vector<vector<int>>& points) {
	int out = 0;
	for (int a = 0; a < points.size(); a++) {
	  for (int b = a + 1; b < points.size(); b++) {
		for (int c = b + 1; c < points.size(); c++) {
		  for (int d = c + 1; d < points.size(); d++) {
			const vector<int>&p1 = points[a], &p2 = points[b], &p3 = points[c], &p4 = points[d];
			out += is_trapezoid(p1, p2, p3, p4) || is_trapezoid(p1, p3, p2, p4) || is_trapezoid(p1, p4, p2, p3);
		  }
		}
	  }
	}
	return out;
  }
};