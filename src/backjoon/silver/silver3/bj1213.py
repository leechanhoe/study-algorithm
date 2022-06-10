from collections import Counter

alpha_cnt = Counter(input())
if sum(cnt % 2 for cnt in alpha_cnt.values()) > 1:
    print("I'm Sorry Hansoo")
else:
    half = odd = ""
    for ch in sorted(alpha_cnt):
        if alpha_cnt[ch] > 1: # 일단 왼쪽 반부터 채우기
            half += ch * (alpha_cnt[ch] // 2)
        if alpha_cnt[ch] & 1: # 개수가 홀수이면 따로저장했다가 중간에 더함
            odd = ch

    ans = half + odd + ''.join(reversed(list(half)))
    print(ans)