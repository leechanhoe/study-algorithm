from itertools import combinations

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
score = [[0] * N for _ in range(N)]
for i in range(N - 1):
    for j in range(i + 1, N):
        score[i][j] = score[j][i] = board[i][j] + board[j][i]

teams = list(combinations(range(N), N // 2))
ans = 1987654321
for team in range(len(teams) // 2):
    team_score1 = team_score2 = 0
    for i in range(N // 2 - 1):
        for j in range(i + 1, N // 2):
            team_score1 += score[teams[team][i]][teams[team][j]]
            team_score2 += score[teams[len(teams)-team-1][i]][teams[len(teams)-team-1][j]]
    ans = min(ans, abs(team_score1 - team_score2))
print(ans)