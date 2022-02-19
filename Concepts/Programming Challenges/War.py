import queue

deckOne = queue.Queue(maxsize=20)
deckTwo = queue.Queue(maxsize=20)

deckOneTemp = input().split(" ")
deckTwoTemp = input().split(" ")

for i in deckOneTemp:
    deckOne.put(i)
for i in deckTwoTemp:
    deckTwo.put(i)

moves = 0

while not(deckOne.empty()) and not(deckTwo.empty()):
    def putCard(deck1, deck2, rest=set()):
        card1 = deck1.get()
        card2 = deck2.get()
        print(card1)
        print(card2)
        if card1 > card2:
            return [1, {card1, card2}.union(rest)]
        elif card1 < card2:
            return [2, {card1, card2}.union(rest)]
        elif card1 == card2:
            putCard(deck1,deck2,([card1, card2]))
    results = putCard(deckOne, deckTwo)
    if results[0] == 1:
        for i in results[1]:
            deckOne.put(i)
    elif results[0] == 2:
        for i in results[1]:
            deckTwo.put(i)
    moves += 1
    print(list(deckOne.queue))
    print(list(deckTwo.queue))

if deckOne.empty():
    print("Player 2 Wins")
else:
    print("Player 1 Wins")
print(moves)