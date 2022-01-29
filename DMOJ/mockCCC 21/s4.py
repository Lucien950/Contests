from collections import Counter
studentCount, questionCount = map(int, input().split())
scores = list(map(int, input().split()))


def tle():
    # TLE SOLUTION
    # find the most common score between l and r in scores, in case of tie choose largest value, and print it
    # use counter to find all the scores between l and r which are equal to the most common score
    c = Counter(scores[l-1:r])
    print(max(filter(lambda x: x[1] == c.most_common()[0][1], c.most_common()), key=lambda x: x[0])[0])


answers = [0 for _ in range(questionCount)]
queries = [(tuple(map(lambda x: int(x) - 1, input().split())), i) for i in range(questionCount)]
queries.sort(key=lambda x: x[0])

c = Counter()
curr = -1
for (l, r), originalIndex in queries:
    while curr < r:
        curr += 1
        c[scores[curr]] += 1
    while curr > r:
        curr -= 1
        c[scores[curr]] -= 1
    while curr < l:
        curr += 1
        c[scores[curr]] -= 1
    while curr > l:
        curr -= 1
        c[scores[curr]] += 1
    
    mostCommonList = c.most_common()
    tieFirst = list(filter(lambda x: x[1] == mostCommonList[0][1], mostCommonList))
    tieFirst.sort(reverse=True)
    answers[originalIndex] = tieFirst[0][0]

print("\n".join(map(str, answers)))