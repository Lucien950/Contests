#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  static bool makeable(const string& item, const unordered_map<string, vector<string>>& recipe_map,
                       const set<string>& supplies, unordered_map<string, bool>& memo) {
	// is a raw supply (super base case)
	if (supplies.contains(item))
	  return true;

	// is not a raw supply

	if (const auto find_r = memo.find(item); find_r != memo.end())
	  return find_r->second;
	// assume that it is not possible (in case there is a loop, it should not be possible to form)
	memo[item] = false;

	// is not a raw supply...
	const auto find_r_i = recipe_map.find(item);
	if (find_r_i == recipe_map.end()) { // ... and cannot be formed with a recipe
	  // aka this is just a random thing that never gets mentioned anywhere
	  return false;
	}

	for (const string& s : find_r_i->second) {
	  if (!makeable(s, recipe_map, supplies, memo))
		return false;
	}
	// all sub ingredients are makeable, thus the item is makeable
	memo[item] = true;
	return true;
  }

public:
  static vector<string> findAllRecipes(const vector<string>& recipes, const vector<vector<string>>& ingredients,
                                       const vector<string>& supplies) {
	// make ing map
	unordered_map<string, vector<string>> recipe_map;
	set<string> supplies_set;
	for (const string& s : supplies)
	  supplies_set.insert(s);
	for (int i = 0; i < recipes.size(); i++)
	  recipe_map[recipes[i]] = ingredients[i];

	unordered_map<string, bool> memo;
	// filter recipe by makeable
	vector<string> out;
	ranges::copy_if(recipes, std::back_inserter(out),
	                [&](const string& recipe) { return makeable(recipe, recipe_map, supplies_set, memo); });
	return out;
  }
};

int main() {
  for (const string& s : Solution::findAllRecipes({"bread"}, {{"yeast", "flour"}}, {"yeast"}))
	cout << s << endl;
}