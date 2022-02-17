#Gets Rules Ready
rule = {}
for i in range(3):
    ruleS = input().split()
    rule[ruleS[0]] = ruleS[1]

#Steps, Start and Final
info = input().split()
steps = int(info[0])
start = info[1]
end = info[2]

#Use Apply Rule to Replace
def applyRule(rule, string, instance):
    return string.replace(rule[0], rule[1], instance)

def fRule(rules, maxSteps, start, final, stepList, step, curSting):
    if step == maxSteps:
        return
    ruleNum = 1
    for rule in rules:
        if rule not in curSting:
            pass
        else:
            for i in range(curSting.count(rule)):
                if step == 0:
                    curSting = applyRule([rule,rules[rule]], start, i+1)
                else:
                    curSting = applyRule([rule, rules[rule]], curSting, i + 1)
                stepList.append(ruleNum)
                if fRule(rules, maxSteps, start, final, stepList, step+1, curSting) == None:
                    pass
                else:
                    return stepList
                if curSting == final:
                    return stepList
        ruleNum += 1

print(fRule(rule,steps, start, end, [], 0, start))