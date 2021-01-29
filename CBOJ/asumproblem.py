from itertools import accumulate
from math import floor, ceil

#GAUSS SOLUTION
yay = int(input())
def gauss():
    unit = yay + 1
    final = unit * floor(yay/2)
    if yay % 2 != 0:
        final += ceil(yay/2)
    print('Gauss', final)
#MEMORY KILL
def bad():
    *_, last = accumulate(range(1, 1+yay))
    print('Accumulate', last)

gauss()
bad()