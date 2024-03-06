N = int(input())
for _ in range(N):
    num = input()
    sum_ = 0
    for i in range(len(num)):
        if i % 2 == 0:
            for j in str(int(num[i]) * 2):
                sum_ += int(j)
        else:
            sum_ += int(num[i])
    
    if sum_ % 10 == 0:
        print('T')
    else:
        print('F')