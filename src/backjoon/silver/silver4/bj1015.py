N = int(input()) # N은 필요없다
A = list(map(int, input().split()))
    
loc = {num : [] for num in A}
for i, num in enumerate(sorted(A)): #정렬한걸 수에따라 인덱스저장
    loc[num].append(i)
for num in A:
    print(loc[num].pop(0), end=" ")