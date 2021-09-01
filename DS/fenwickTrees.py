class fenwickTree(object):
    #pain
    def __init__(self, arr):
        self.tree = list.copy(arr)

        for i in range(1, len(arr)):
            j = i + self.LSB(i)
            if j < len(arr):
                self.tree[j] += self.tree[i]

    def LSB(self, i):
        return i & -i

    #INTERESTING Functions
    def prefixSum(self, i):
        sum = 0
        while i != 0:
            # Query from the master array
            sum += self.tree[i]
            # SHIFT I
            i &= ~self.LSB(i)
        return sum

    def sum(self, i, j):
        return self.prefixSum(j) - self.prefixSum(i-1)

    def add(self, i, x):
        while i < len(self.tree):
            self.tree[i] = self.tree[i] + x
            i += self.LSB(i)

a = fenwickTree([1, 2, 3, 4, 5])

print(a.tree)
print(a.sum(1 , 2))