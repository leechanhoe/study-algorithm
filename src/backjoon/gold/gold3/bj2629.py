N = int(input())
weights = [*map(int, input().split())] 
M = int(input())
beads = [*map(int, input().split())]
dp = [[False] * ((i+1)*500+1) for i in range(N+1)]
# 추의 무게는 최대 500이므로 [[추의 개수*500]*추의 개수]로 배열을 구성한다.
# 아래 함수의 탐색으로 잴 수 있는 구슬은 dp = True
def f(num, weight):
    if num > N or dp[num][weight]:
        return
    
    dp[num][weight] = True

    f(num + 1, weight)
    f(num + 1, weight + weights[num-1])
    f(num + 1, abs(weight - weights[num-1]))

f(0, 0)
ans = []
for bead in beads:
    if bead > 30 * 500:
        ans.append('N')
        continue
    if dp[N][bead]:
        ans.append('Y')
    else:
        ans.append('N')
print(*ans)