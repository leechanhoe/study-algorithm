# 입력
R, C = map(int, input().split())  # 체스판의 행과 열
A, B = map(int, input().split())  # 각 행의 높이와 각 열의 너비

# 체스판 생성
for r in range(R):
    # 행의 높이만큼 반복
    for a in range(A):
        # 한 줄을 생성
        line = ""
        for c in range(C):
            # 열의 너비만큼 검정('X') 또는 흰색('.') 추가
            if (r + c) % 2 == 0:
                line += 'X' * B
            else:
                line += '.' * B
        # 생성된 줄 출력
        print(line)
