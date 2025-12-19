from collections import defaultdict

def topsort(start: str, adj: dict[str, list[str]]) -> list[str]:
	topsorted: list[str] = []
	explored: defaultdict[str, bool] = defaultdict(bool)
	def _topsort(at: str) -> None:
		explored[at] = True
		for child in adj[at]:
			if explored[child]: continue
			_topsort(child)
		topsorted.append(at)
	_topsort(start)
	topsorted.reverse()
	return topsorted


def get_paths_between(adj: dict[str, list[str]], start: str, end: str):
	topsorted = topsort(start, adj)
	assert topsorted[0] == start, f"topsort must start with {start}"
	if end not in topsorted: return 0

	visited_times: defaultdict[str, int] = defaultdict(int)
	visited_times[start] = 1
	for node in topsorted:
		v = visited_times[node]
		for child in adj[node]:
			visited_times[child] += v
	return visited_times[end]

adj: dict[str, list[str]] = {}
for line in open("11.in").readlines():
	line = line.strip()
	node, *outs = line.split()
	node = node[:-1]
	for out in outs:
		if node not in adj:
			adj[node] = []
		adj[node].append(out)
adj["out"] = []

a = get_paths_between(adj, "svr", "dac") * \
	get_paths_between(adj, "dac", "fft") * \
	get_paths_between(adj, "fft", "out")
b = get_paths_between(adj, "svr", "fft") *\
	get_paths_between(adj, "fft", "dac") * \
	get_paths_between(adj, "dac", "out")
print(a + b)