def topTwo(a, first, last):
    top = [0,0] #First index, then value
    second = [0,0] #~~~
    for i in range(first,last+1):
        if a[i] > top[1]:
            second[0] = top[0]
            second[1] = top[1]
            top[0] = i
            top[1] = a[i]
        elif a[i] > second[1] or (abs(top[0]-i) < abs(top[0]-second[0]) and a[i] == second[1]):
            second[0] = i
            second[1] = a[i]
    return [top[0], second[0]]

a = [8,6,9,4,45,9,6,6,1,5,77]
print(topTwo(a, 2, 8))