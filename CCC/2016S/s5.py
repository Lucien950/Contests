from math import floor, log2


length, gens = map(int, input().split())
cells = list(map(int, list(input())))


while gens > 0:
    gens -= 2**floor(log2(gens))
    [cells[(position-gens)%(length)] ^ cells[(position + gens)%(length)] for position in range(length)]