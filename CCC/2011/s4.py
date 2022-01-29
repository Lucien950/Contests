import copy
types = ["On", "Op", "An", "Ap", "Bn", "Bp", "ABn", "ABp"]
bank = {i:j for i, j in zip(types, map(int, input().split()))}
demand = {i:j for i, j in zip(types, map(int, input().split()))}
bank2 = copy.deepcopy(bank)
demand2 = copy.deepcopy(demand)

def give(fromType, toType, bank, demand):
	moveAmount = min(bank[fromType], demand[toType])
	bank[fromType] -= moveAmount
	demand[toType] -= moveAmount
	return moveAmount

def positive(bank, demand):
	# distribute
	total = 0
	transfers = [
		("Op", "Op"),
		("On", "Op"),

		("Ap", "Ap"),
		("Op", "Ap"),
		# neg
		("An", "Ap"),
		("On", "Ap"),
		
		("Bp", "Bp"),
		("Op", "Bp"),
		# neg
		("Bn", "Bp"),
		("On", "Bp"),

		("ABp", "ABp"),
		("Ap", "ABp"),
		("Bp", "ABp"),
		("Op", "ABp"),
		# neg
		("ABn", "ABp"),
		("An", "ABp"),
		("Bn", "ABp"),
		("On", "ABp"),
	]
	for a, b in transfers:
		total += give(a, b, bank, demand)
	return total

def negative(bank, demand):
	total = 0
	transfers = [
		("On", "On"),
		
		("An", "An"),
		("On", "An"),

		("Bn", "Bn"),
		("On", "Bn"),

		("ABn", "ABn"),
		("An", "ABn"),
		("Bn", "ABn"),
		("On", "ABn"),
	]
	for a, b in transfers:
		total += give(a, b, bank, demand)
	return total


sol1, sol2 = positive(bank, demand) + negative(bank, demand), negative(bank2, demand2) + positive(bank2, demand2)
print(max(sol1, sol2))