import sys
input = sys.stdin.readline

a = [""] + list(input().rstrip())
b = [""] + list(input().rstrip())
lcs = [[""]*len(b) for _ in range(len(a))]

# lcs[i][j]는 A의 i번째까지의 문자열과
# B의 j번째까지의 문자열의 lcs 길이 값을 의미함
# lcs[i][j]에서, 만약 A[i] == B[j]라면
# 그 두 문자를 제외한 i-1개, j-1개의 lcs
# 만약 다르다면, i-1개, j개와 i개, j-1개
# 일 때의 lcs 중 큰 값 취하기. i-1개, j-1개
# 는 어차피 저 두 케이스보다 반드시 작거나 같으므로
# 두 케이스만 고려.
# 그런데 lcs 리스트 원소 값이 lcs 길이 값을 의미하므로,
# 원소를 lcs 문자열 자체로 둬도 됨. 그럼 길이 값도 갖고
# 최단 경로도 갖고 있게 됨.
for i in range(1, len(a)):
    for j in range(1, len(b)):
        if a[i] == b[j]:
            lcs[i][j] = lcs[i-1][j-1] + a[i]
        else:
            if len(lcs[i-1][j]) >= len(lcs[i][j-1]):
                lcs[i][j] = lcs[i-1][j]
            else:
                lcs[i][j] = lcs[i][j-1]

result = lcs[-1][-1]
print(len(result), result, sep="\n")