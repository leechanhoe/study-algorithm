N = int(input())
bird = N
k = 1
time = 0

while(bird > 0):
    if(bird < k):
        k = 1
    bird -= k
    k += 1
    time += 1
print(time)