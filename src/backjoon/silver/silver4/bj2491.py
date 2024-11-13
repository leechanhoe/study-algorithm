def longest_sequence(N, arr):
    # 증가 구간의 길이와 감소 구간의 길이를 추적하는 변수
    inc_len = 1
    dec_len = 1
    max_len = 1  # 최소 길이는 1

    for i in range(1, N):
        if arr[i] >= arr[i - 1]:
            inc_len += 1
        else:
            max_len = max(max_len, inc_len)
            inc_len = 1  # 증가가 끊기면 다시 1로 초기화

        if arr[i] <= arr[i - 1]:
            dec_len += 1
        else:
            max_len = max(max_len, dec_len)
            dec_len = 1  # 감소가 끊기면 다시 1로 초기화

    max_len = max(max_len, inc_len, dec_len)
    return max_len


N = int(input())
arr = list(map(int, input().split()))
print(longest_sequence(N, arr))
