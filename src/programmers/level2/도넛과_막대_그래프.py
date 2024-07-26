
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
def solution(edges):
    in_ = [[] for _ in range(1000001)]
    out = [[] for _ in range(1000001)]
    n = 0
    for a, b in edges:
        out[a].append(b)
        in_[b].append(a)
        n = max(n, a)
        n = max(n, b)

    start = 0
    answer = [0, 0, 0, 0]
    for i in range(1, n + 1):
        if len(in_[i]) == 0 and len(out[i]) >= 2:
            start = i
            answer[0] = i

    for s in out[start]:
        now = s
        visit = {}
        while 1:
            if not out[now]:
                answer[2] += 1
                break
            if 1 < len(out[now]):
                answer[3] += 1
                break
            if now in visit:
                answer[1] += 1
                break

            visit[now] = True
            now = out[now][0]

    return answer