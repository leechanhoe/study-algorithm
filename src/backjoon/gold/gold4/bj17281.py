import sys
from itertools import permutations
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
inning = []
for _ in range(N):
    inning.append(list(map(int, input().split())))

def game():
    score = 0
    now_inning = 0
    now_order = 0

    while now_inning < N:
        p1 = p2 = p3 = 0
        out = 0
        
        while out < 3:
            if inning[now_inning][order[now_order]] == 0:
                out += 1
            elif inning[now_inning][order[now_order]] == 1: 
                score += p3 
                p1, p2, p3 = 1, p1, p2
            elif inning[now_inning][order[now_order]] == 2: 
                score += p2 + p3 
                p1, p2, p3 = 0, 1, p1
            elif inning[now_inning][order[now_order]] == 3:
                score += p1 + p2 + p3
                p1, p2, p3 = 0, 0, 1
            elif inning[now_inning][order[now_order]] == 4:
                score += p1 + p2 + p3 + 1
                p1, p2, p3 = 0, 0, 0

            now_order = (now_order + 1) % 9
        now_inning += 1
    return score

ans = 0
for o in permutations(list(range(1, 9)), 8):
    o = list(o)
    order = o[:3] + [0] + o[3:]
    ans = max(ans, game())

print(ans)