N = int(input())
vote = sum([int(input()) for _ in range(N)])
if N - vote > vote:
    print("Junhee is not cute!")
else:
    print("Junhee is cute!")