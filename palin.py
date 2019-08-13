#Input Handling
cases = int(input())
palin = []
for i in range(cases):
    palin.append(input())

#Definitions
def closest(n, a):
    out = 0
    dist = 0
    for i in a:
        if abs(n-i) < dist or a.index(i) == 0:
            out = i
            dist = n-i
    return out
def reverse(s):
    return s[::-1]
def isPalin(s):
    # Calling reverse function
    rev = reverse(s)

    # Checking if both string are equal or not
    if (s == rev):
        return True
    return False

for string in palin:
    if isPalin(string):
        print(string)
    else:
        #Generate and Index closest to the center where the front = back
        palinIndex = []
        index = 1
        for char in string:
            if index == len(string): #If the character is the last in the string
                pass
            else:
                if index <= len(string)-index:
                    frontHalf = string[0:index]
                    backHalf = string[index:index * 2]
                else:
                    frontHalf = string[(2*index)-len(string):index]
                    backHalf = string[index:len(string)]

                if frontHalf == reverse(backHalf):
                    palinIndex.append(index)
                index += 1
        if len(palinIndex) == 0:#Check if there is no efficent way to add characters and make Palindrome
            print(string + reverse(string[:-1]))
        else:
            closeIndex = closest(round(len(string)/2), palinIndex)
            if closeIndex <= round(len(string)/2):#If the cut is fronthalf, copy backhalf over
                backHalf = string[closeIndex:len(string)]
                print(reverse(backHalf)+backHalf)
            else:#If the cut is backhalf, copy fronthalf over
                frontHalf = string[0:closeIndex]
                print(frontHalf + reverse(frontHalf))