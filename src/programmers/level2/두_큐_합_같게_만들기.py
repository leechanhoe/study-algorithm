from collections import deque

def solution(queue1, queue2):
    q1 = deque(queue1)
    q2 = deque(queue2)
    s1 = sum(q1)
    s2 = sum(q2)
    limit = len(q1) * 3
    ans = 0
    
    while s1 != s2:
        if s1 > s2:
            x = q1.popleft()
            q2.append(x)
            s1 -= x
            s2 += x
        elif s1 < s2:
            x = q2.popleft()
            q1.append(x)
            s1 += x
            s2 -= x
            
        ans += 1
        
        if ans == limit:
            return -1
        
    return ans