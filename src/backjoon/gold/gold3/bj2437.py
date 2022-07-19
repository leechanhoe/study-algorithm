import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
weights = [*map(int, input().split())]
weights.sort()
ma = 0  # 현재까지 구한 연속적인 값의 최대 
for w in weights: # 추를 하나씩 더해간다
    temp = ma + w # 현재까지 구한 연속적인 값의 최대 ma 에서 무게가 w 인 추를 더하면
    for i in range(ma + 1, temp): # ma + 1 부터 ma + w 까지 공백없이 연속적으로 값이 있어야함
        if 0 > i - w: # ma + 1 ~ ma + w 에서 w 를 빼서 0보다 작으면 공백이 있다는 뜻
            print(i)
            exit(0)
    ma = temp
print(ma + 1) # 반복문을 통과했으면 추를 모두 더한 ma까지는 만들 수 있으므로 ma + 1이 답