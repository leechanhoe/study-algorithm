ab = input()
lenb = ab.count("b")
circleAb = ab + ab[:lenb]
maxCnt = 0
for i in range(len(circleAb)):
    maxCnt = max(maxCnt, circleAb[i:i+lenb].count("b"))

print(lenb - maxCnt)