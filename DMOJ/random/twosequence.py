seqLen, queryCount = map(int, input().split())
seq1 = list(map(int, input().split()))
seq2 = list(map(int, input().split()))

# inclusive
def rangeQuery(li, start, end):
    return li[end + 1]-li[start]
prefixSeq1 = [0] * (seqLen + 1)
prefixSeq2 = [0] * (seqLen + 1)
for i in range(1, seqLen + 1):
    prefixSeq1[i] = prefixSeq1[i - 1] + seq1[i - 1]
    prefixSeq2[i] = prefixSeq2[i - 1] + seq2[i - 1]

queries = [tuple(map(lambda x: int(x)-1, input().split())) for _ in range(queryCount)]
for query in queries:
    # find optimal k w/binary search
    l, r = query
    while l + 1 < r:
        k = (l+r)//2
        leftSum = rangeQuery(prefixSeq1, query[0], k)
        rightSum = rangeQuery(prefixSeq2, k + 1, query[1])
        if leftSum < rightSum:
            l = k
        else:
            r = k
    # compare k = l and k = r
    possibles = []
    possibles.append(max(rangeQuery(prefixSeq1, query[0], l), rangeQuery(prefixSeq2, l+1, query[1])))
    if r < query[1]:
        possibles.append(max(rangeQuery(prefixSeq1, query[0], r), rangeQuery(prefixSeq2, r+1, query[1])))
    print(min(possibles))