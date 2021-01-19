fibNum = int(input())

fibList = [0, 1]
def fib(n):
    if n < len(fibList):
        return fibList[n]
    else:
        return fib(n-1) + fib(n-2)

print(fib(fibNum))