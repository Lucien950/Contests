#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // nums1 and nums2 are permutations of 0 to n-1 where n is the size of nums1/nums2
  // we want to find the number of triplets (i, j, k) such that:
  // the positions of i,j,k in nums1 and nums2 are increasing
  static long long goodTriplets(const vector<int>& nums1, const vector<int>& nums2) {
	long long out = 0;

	return out;
  }
};

int main() { cout << Solution::goodTriplets({4, 0, 1, 3, 2}, {4, 1, 0, 2, 3}) << endl; }