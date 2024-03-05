S = input().strip()
K = input().strip()

# 숫자를 제거한 교과서 문자열 생성
S_alpha = ''.join([c for c in S if not c.isdigit()])

# K가 S_alpha에 포함되는지 확인
if K in S_alpha:
    print(1)
else:
    print(0)