inList = input().split(" ")
if len(inList) != 10:
    raise Exception("Bad Input")
tempblack = inList[0:5]
tempwhite = inList[5:10]
white = []
black = []

tempnums = "23456789TJQK" #12 numbers
key = {"T": 10,"J": 11, "Q": 12, "K": 13}
nums = {}
for i in range(len(tempnums)):
    nums[tempnums[i]] = i
suits = {"S": 1, "C": 2, "D": 3, "H": 4} #Spaces, Clubs, Diamonds, Hearts

for i in tempblack:
    inOne = nums[i[0]] + suits[i[1]]*12
    black.append(inOne)
for i in tempwhite:
    inOne = nums[i[0]] + suits[i[1]]*12
    white.append(inOne)

#Straight Flush
def sF(a):
    index = 0
    for i in sorted(set(a)):
        if index == 0:
            countUp = i
            index += 1
        else:
            if i - countUp != 1:
                return False
            else:
                countUp = i
    return True

#Four of a Kind
def fOaK(a):
    stand = a[0]%12
    forgives = 1
    index = 0
    for i in a:
        if index == 0:
            index += 1
        elif i%12 != stand:
            if forgives == 0:
                return False
            else:
                forgives -= 1
    return True

#Full House
def fH(a):
    return

#Flush
def flu(a):


print(fOaK(white))
print(white)
print(fOaK(black))
print(black)