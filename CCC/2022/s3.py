# For the first subtask, it suffices to attempt all possible output arrays, and run a brute force check to determine if it works. 
# For the second subtask, note that any array of length 3 is not good. Also, all arrays of length 1 are good. Thus, the question is simply how many arrays of length 2 are good. We calculate K - N as our required count. Note that we can build it as we go. From the left, if we still need good samples, we can swap to the other pitch, otherwise, keep the same one. Note that all values between N and 2N - 1 inclusive are possible and no others are.
# For the third subtask, we can build on our subtask 2 solution. Let K - N be our required count. Assume we have some current array A. Depending on our remaining required count, we can decide what to append to our array A. For instance, if we no longer need any good samples, we can simply add a value equal to the current last value of the array. If we need 3 more, we can add the note 4 notes back. That way, there are 3 good samples. We can also pick a new number if we want even more good samples. It suffices to greedily choose the number that gives us the most samples up to the remaining amount, because everytime we run this we have a choice of some range [0, k] of integers, so it's not as though we will reach a point where we're missing a number that we need.	
# For an implementation detail, it's a good idea to keep track of the longest suffix of your array A that is valid.
# The last subtask is basically the same, all we do is note that if we would add a new number to the end, we have to instead do a proper check to see if the new number is too large. After that it proceeds as before.

noteCount, maxPitch, sampleCount = map(int, input().split())
result = "1"
if sampleCount < noteCount:
    print("too little samples")
    exit()
sampleCount -= noteCount
i = 2
while sampleCount >= i - 2:
    result += str(i)
    sampleCount -= i

    i += 1
    i %= maxPitch
# tie it up with the last note
sampleCount -= i - 2
result += result[1-i]

# fill rest
result += "1" * (noteCount - len(result))
if len(result) != noteCount:
    print(f"result length mismatch {result} {len(result)} != {noteCount}")
    exit()
print(result)