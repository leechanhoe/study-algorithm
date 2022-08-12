N, K = map(int, input().split())
score = [*map(int, input().split())]
score.sort(reverse=True)
print(score[K-1])