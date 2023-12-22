score = [int(input()) for _ in range(6)]
print(sum(score) - min(score[:4]) - min(score[4:]))