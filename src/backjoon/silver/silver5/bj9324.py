T = int(input())
for _ in range(T):
    m = input()
    cnt = {i : 0 for i in range(65, 100)}
    fake = False
    for i in range(len(m)):
        cnt[ord(m[i])] += 1
        if cnt[ord(m[i])] == 3:
            if i == len(m) - 1 or m[i] != m[i+1]:
                fake = True
                break
            cnt[ord(m[i])] = -1
    
    if fake:
        print("FAKE")
    else:
        print("OK")