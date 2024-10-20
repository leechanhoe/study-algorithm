def solution(K, A):
    N = len(A)
    M = len(A[0])

    uple = set()
    upri = set()
    dole = set()
    dori = set()

    # 가장 안쪽 대각선들 구하기
    for i in range(N):
        for j in range(M):
            if A[i][j]:
                up = i - K
                # / 대각선은 i + j 로 정의 - 값이 클수록 우측아래므로 가장 큰값 구하기
                uple.add(up + j)
                # \ 대각선을 i - j 로 정의 - 값이 클수록 좌측아래므로 가장 큰값 구하기
                upri.add(up - j)

                down = i + K
                # 값이 작을수록 우측위므로 가장 작은값 구하기
                dole.add(down - j)
                # 값이 작을수록 좌측위므로 가장 작은값 구하기
                dori.add(down + j)

    uple = max(uple)
    upri = max(upri)
    dole = min(dole)
    dori = min(dori)

    ans = 0
    for i in range(N):
        for j in range(M):
            if not A[i][j]:
                ans += 1

    return ans
