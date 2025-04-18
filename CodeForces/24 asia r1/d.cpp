#include <array>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <variant>

using namespace std;

static array<array<bool, 101>, 101> has_obs{};

enum class Direction { RIGHT, UP, LEFT, DOWN };
static unordered_map<Direction, pair<int16_t, int16_t>> directions = {
    {Direction::RIGHT, {1, 0}}, {Direction::UP, {0, 1}}, {Direction::LEFT, {-1, 0}}, {Direction::DOWN, {0, -1}}};

struct SimResultCycle {
  uint64_t start_cycle_time;
  pair<int16_t, int16_t> start_cycle;
  uint64_t cycle_length;
  Direction start_cycle_direction;
};

struct SimResultDone {
  pair<int16_t, int16_t> final;
};

struct SimResultLeave {
  pair<int16_t, int16_t> final;
  uint64_t left;
  Direction final_direction;
};

using SimResult = variant<SimResultDone, SimResultCycle, SimResultLeave>;

static SimResult simulate(pair<int16_t, int16_t> at, Direction d, const uint64_t max_steps) {
  // visited[x][y][d] represents the earliest time the cell (x, y) has been visited with direction d
  // NOTE: if visited[x][y][d] == 0, then it has not been visited.
  array<array<array<uint64_t, 4>, 101>, 101> visited{};
  for (uint64_t time = 1; time <= max_steps; time++) {
	assert(time <= 100 * 100);
	// check we are in bounds
	if (at.first < 0 || at.first > 100 || at.second < 0 || at.second > 100) {
	  return {SimResultLeave{at, max_steps - time + 1, d}};
	}

	// potentially change direction
	for (int i = 0; has_obs[at.first + directions[d].first][at.second + directions[d].second]; i++) {
	  // turn left
	  d = static_cast<Direction>((static_cast<int>(d) + 1) % 4);
	  assert(i < 4);
	}

	// check if you have been here before
	if (visited[at.first][at.second][static_cast<int>(d)] != 0) {
	  return {SimResultCycle{visited[at.first][at.second][static_cast<int>(d)] - 1, at,
	                         time - visited[at.first][at.second][static_cast<int>(d)], d}};
	}
	// logging
	visited[at.first][at.second][static_cast<int>(d)] = time;

	// step
	at.first += directions[d].first;   // NOLINT(*-narrowing-conversions)
	at.second += directions[d].second; // NOLINT(*-narrowing-conversions)
  }

  // sim result done :)
  return {SimResultDone{at}};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (true) {
	uint64_t n, max_steps;
	pair<int16_t, int16_t> start;
	cin >> n;
	if (n == 0)
	  break;
	cin >> start.first >> start.second >> max_steps;
	memset(has_obs.data(), 0, sizeof(has_obs));
	for (uint64_t i = 0; i < n; i++) {
	  int x, y;
	  cin >> x >> y;
	  has_obs[x][y] = true;
	}

	pair<int64_t, int64_t> out;
	if (const SimResult res = simulate(start, Direction::RIGHT, max_steps); holds_alternative<SimResultDone>(res)) {
	  out = get<SimResultDone>(res).final;
	} else if (holds_alternative<SimResultLeave>(res)) {
	  auto [final, left, final_direction] = get<SimResultLeave>(res);
	  out = final;
	  out.first += directions[final_direction].first * static_cast<int64_t>(left);
	  out.second += directions[final_direction].second * static_cast<int64_t>(left);
	} else if (holds_alternative<SimResultCycle>(res)) {
	  const auto [start_cycle_time, start_cycle, cycle_length, start_cycle_direction] = get<SimResultCycle>(res);
	  max_steps -= start_cycle_time;
	  max_steps %= cycle_length;
	  const auto res_2 = simulate(start_cycle, start_cycle_direction, max_steps);
	  assert(holds_alternative<SimResultDone>(res_2));
	  out = get<SimResultDone>(res_2).final;
	} else {
	  // idk gang like
	  assert(false);
	}
	cout << out.first << " " << out.second << "\n";
  }
}