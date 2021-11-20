a = []
# binary search implimentation
def bsearch(array, searchValue):
    leftPointer = 0
    rightPointer = len(array) - 1
    while leftPointer <= rightPointer:
        middle = (leftPointer + rightPointer) // 2
        if array[middle] == searchValue:
            return middle # SUCCESS
        elif array[middle] < searchValue:
            leftPointer = middle + 1
        else:
            rightPointer = middle - 1
    return -1 # not found

