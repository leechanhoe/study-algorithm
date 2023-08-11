import sys
input = lambda : sys.stdin.readline().rstrip()

S, P = map(int, input().split())
dna = input()
acgt = list(map(int, input().split()))
aim = {'A' : acgt[0], 'C' : acgt[1], 'G' : acgt[2],'T' : acgt[3]}
now = {'A' : 0, 'C' : 0, 'G' : 0, 'T' : 0}

le = 0
ri = P - 1
ans = 0
for ch in dna[:P]:
    now[ch] += 1

if aim['A'] <= now['A'] and aim['C'] <= now['C'] and aim['G'] <= now['G'] and aim['T'] <= now['T']:
    ans += 1

for i in range(P, S):
    now[dna[le]] -= 1
    le += 1
    ri += 1
    now[dna[ri]] += 1

    if aim['A'] <= now['A'] and aim['C'] <= now['C'] and aim['G'] <= now['G'] and aim['T'] <= now['T']:
        ans += 1

print(ans)