
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
from collections import deque

def check(dq1, dq2, n1):
    op = set(dq2)
    for card in dq1:
        if n1 - card in op:
            dq1.remove(card)
            dq2.remove(n1 - card)
            return True
    return False

def solution(coin, cards):
    n = len(cards)
    hand = cards[: n//3]
    dq = deque(cards[n//3:])
    pending = []
    turn = 1
    while coin >= 0 and dq:
        pending.append(dq.popleft())
        pending.append(dq.popleft())

        if check(hand, hand, n + 1):
            pass
        elif coin >= 1 and check(hand, pending, n + 1):
            coin -= 1
        elif coin >= 2 and check(pending, pending, n + 1):
            coin -= 2
        else:
            break

        turn += 1
    return turn