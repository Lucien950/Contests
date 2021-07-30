from collections import namedtuple


eventsCount = int(input())

events = []
event = namedtuple('event', ['start', 'end'])
for i in range(eventsCount):
    start, end = map(int, input().split())
    events.append(event(start, end))

#find events that end as early as possible
events.sort(key=lambda x: x.end)
events.reverse()

numItems = 1
nextTime = events.pop().end
while events:
    pop = events.pop()
    if pop.start <= nextTime:
        continue
    nextTime = pop.end
    numItems += 1

print(numItems)