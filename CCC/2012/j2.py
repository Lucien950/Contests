recordings = [int(input()) for _ in range(4)]
sortRecordings = sorted(recordings)
allUnique = len(set(recordings)) == 4
if recordings == sortRecordings and allUnique:
    print("Fish Rising")
elif recordings == list(reversed(sortRecordings)) and allUnique:
    print("Fish Diving")
elif len(set(recordings)) == 1:
    print("Fish At Constant Depth")
else:
    print("No Fish")