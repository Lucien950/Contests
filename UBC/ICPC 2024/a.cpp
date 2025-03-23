#include <climits>
#include <cstdint>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

enum class query_type : char { REMOVE = 'X', QUERY = 'Q' };
struct query {
  query_type type;
  int64_t val;
};

constexpr int64_t MAX_DP_LEN = 1e5 + 1;
static std::vector<int64_t> dp(MAX_DP_LEN, -1);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int denom_count, query_count;
  cin >> denom_count >> query_count;

  vector denoms(denom_count, 0);
  for (int i = 0; i < denom_count; i++)
	cin >> denoms[i];

  // copy from populated vector to set
  // represents the denominations which remain at the end
  unordered_set<int64_t> final_denoms{denoms.begin(), denoms.end()};
  int64_t max_query = 0;

  // populate queries
  vector<query> queries(query_count);
  for (int i = 0; i < query_count; i++) {
	char c;
	cin >> c >> queries[i].val;
	switch (c) {
	case 'X':
	  queries[i].type = query_type::REMOVE;
	  final_denoms.erase(queries[i].val);
	  break;
	case 'Q':
	  queries[i].type = query_type::QUERY;
	  max_query = max(max_query, queries[i].val);
	  break;
	default:
	  return EXIT_FAILURE;
	}
  }

  // populate dp with denominations that are not removed
  dp[0] = 0;
  for (int64_t i = 0; i < max_query + 1; i++) {
	for (const int64_t& d : final_denoms) {
	  if (i - d >= 0 && dp[i - d] != -1) {
		dp[i] = min(dp[i] == -1 ? INT64_MAX : dp[i], dp[i - d] + 1);
	  }
	}
  }

  // populate query_answers with dp
  vector<int64_t> query_answers;
  query_answers.reserve(query_count);
  for (auto query = queries.rbegin(); query < queries.rend(); ++query) {
	switch (query->type) {
	case query_type::REMOVE:
	  // add val to list of valid denominations
	  for (int i = 0; i < max_query + 1; i++)
		if (i - query->val >= 0 && dp[i - query->val] >= 0) // in range and previous is reachable
		  dp[i] = min(dp[i] == -1 ? INT64_MAX : dp[i], dp[i - query->val] + 1);
	  break;
	case query_type::QUERY:
	  query_answers.push_back(dp[query->val]);
	  break;
	default:
	  return EXIT_FAILURE;
	}
  }

  // return values
  for (auto a = query_answers.rbegin(); a < query_answers.rend(); ++a) {
	cout << *a << "\n";
  }
  cout << endl;
  return EXIT_SUCCESS;
}