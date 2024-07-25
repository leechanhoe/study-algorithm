def hanoi(start, mid, end, n, answer):
    if n != 1:
        hanoi(start, end, mid, n - 1, answer)
    answer.append([start, end])
    if n != 1:
        hanoi(mid, start, end, n - 1, answer)

def solution(n):
    answer = []
    hanoi(1, 2, 3, n, answer)
    return answer