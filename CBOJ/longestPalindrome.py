inString = input()
left = 0
right = len(inString) - 1

if inString[left] == inString[right]:
    left += 1
    right -= 1