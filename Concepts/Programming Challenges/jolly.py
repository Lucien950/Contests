#Input Handling
tempnums = input().split(" ")
length = 0
nums = []
index = 0
for i in tempnums:
    if index == 0:
        length = i
        index += 1
    else:
        nums.append(int(i))


#Set up
jumps = set()
for i in range(1,len(nums)):
    jumps.add(i)

#Computations
for i in range(len(nums)):
    if i == len(nums)-1:
        break
    try:
        jumps.remove(abs(nums[i] - nums [i+1]))
    except:
        pass

#Output Handling
if len(jumps) == 0:
    print("Jolly")
else:
    print("Not Jolly")