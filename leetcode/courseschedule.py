class Solution:
    def root(self,n: int):
        if n == self.union[n]: return n
        self.union[n] = self.root(self.union[n])
        return self.union[n]
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        self.union = [i for i in range(len(edges) + 1)]
        for a, b in edges:
            rootA, rootB = self.root(self.union[a]), self.root(self.union[b])
            if rootA == rootB: # connected
                return [a, b]
            self.union[rootA] = self.union[rootB]