p1, r1 = input().split()
p2, r2 = input().split()
p3, r3 = input().split()
swaps = list(zip([p1, p2,p3], [r1, r2, r3]))

totalSteps, initial, target = input().split()
totalSteps = int(totalSteps)

visited = set()
def solve(state, moves=None, steps = 0):
    #ONLY ON INITIAL RUN
    if moves is None:
        moves = []

    #bc1
    if steps == totalSteps:
        return moves if state == target else False
    #bc2
    if (state, steps) in visited:
        return False
    visited.add((state, steps))

    #rc
    for i, (swap, swapTo) in enumerate(swaps):
        pos = -1
        while True:
            pos = state.find(swap, pos+1)
            if pos == -1: break
            newState = state[:pos] + swapTo + state[pos + len(swap):]
            answer = solve(newState, moves + [(i, pos, newState)] , steps + 1)
            if answer: return answer


final = solve(initial)
for a, b, c in final:
    print(a+1, b+1, c)