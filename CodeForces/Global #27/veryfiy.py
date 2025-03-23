while True:
    target = input()
    if target == "":
        break
    target = int(target)
    l = list(map(int, input().split()))
    out = 0
    if len(set(l)) != len(l):
        raise Exception("invalid string")
    print(list(map(bin, l)))
    for i in range(len(l)):
        out = out & l[i] if i % 2 == 0 else out | l[i]

    assert target == out, f"Target {target} and out {out} are not matching"

print("All Tests Passed")
