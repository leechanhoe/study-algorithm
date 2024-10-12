def solution(n, k):
    word = ""
    while n:
        word = str(n % k) + word
        n = n // k
    word = word.split("0")

    cnt = 0
    for w in word:
        if len(w) == 0:
            continue

        w = int(w)
        if w < 2:
            continue

        sosu = True
        for i in range(2, int(w**0.5) + 1):
            if w % i == 0:
                sosu = False

        if sosu:
            cnt += 1
    return cnt
