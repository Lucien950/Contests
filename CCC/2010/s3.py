houseCount = int(input())
addresses = [int(input()) for _ in range(houseCount)]
hydrants = int(input())
spaceCount = 10 # CHANGE LATER TO 1000000


# public static int getNumOfHydrants(int[] houses, int hose){
#     int diameter = hose * 2;
#     int minHydrants = houses.length;
#     int numHouses = houses.length;

#     for(int start = 0; start < numHouses && houses[start] <= houses[0] + diameter; start++){

#         int count = 1;
#         int curEnd = houses[start];

#         for(int j = start + 1; houses[start] > (houses[j % numHouses] + diameter - 1000000); j++){
#             if(houses[j % numHouses] > curEnd){
#                 count++;
#                 curEnd = houses[j % numHouses] + diameter;
#             }
#         }

#         minHydrants = Math.min(minHydrants, count);
#     }

#     return minHydrants;
# }
def minimumHydrants(hoseLength):
    pass

left = 0
right = spaceCount - 1
while left < right:
    mid = (left + right) // 2

    hydrantsNeeded = minimumHydrants(mid)
    if hydrantsNeeded <= hydrants:
        right = mid
    else:
        left = mid + 1

# left
print(left)