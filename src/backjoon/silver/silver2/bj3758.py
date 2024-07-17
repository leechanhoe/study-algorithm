import sys
input = lambda : sys.stdin.readline().rstrip()

T = int(input())
for _ in range(T):
    n, k, t, m = map(int, input().split())
    score = [[0] * (k + 1) for _ in range((n + 1))]
    cnt = [0] * (n + 1)
    last = [0] * (n + 1)
    for time in range(m):
        i, j, s = map(int, input().split())
        score[i][j] = max(score[i][j], s)
        cnt[i] += 1
        last[i] = time

    rank = []
    for team in range(1, n+1):
        rank.append([sum(score[team]), cnt[team], last[team], team])
    rank.sort(key=lambda x : (-x[0], x[1], x[2]))

    for team in range(n):
        if rank[team][3] == t:
            print(team + 1)
            break