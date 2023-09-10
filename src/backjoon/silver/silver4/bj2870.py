import re

N = int(input())
paper = []

for i in range(N):
    for j in list(re.split("\\D", input())):
        if j != "": 
            paper.append(int(j))

paper.sort()
paper = map(str, paper)
print('\n'.join(paper))