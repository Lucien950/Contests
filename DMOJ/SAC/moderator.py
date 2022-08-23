import sys
input = sys.stdin.readline

bannedWordCount, messageCount = map(int, input().split())
bannedWords = {input().rstrip().lower() for _ in range(bannedWordCount)}
messages = [input().rstrip().lower() for _ in range(messageCount)]
minLenWord, maxLenWord = min(map(len, bannedWords)), max(map(len, bannedWords))

for message in messages:
    badWordCount = 0
    foundBannedWords = set()
    for substringLength in range(minLenWord, maxLenWord + 1):
        for startIndex in range(len(message) - substringLength + 1):
            lookmessage = message[startIndex:startIndex + substringLength]
            if lookmessage in bannedWords and lookmessage not in foundBannedWords:
                foundBannedWords.add(lookmessage)
                badWordCount += 1
    print(badWordCount)