from collections import defaultdict
from math import ceil

def solution(fees, records):
    def convert(s):
        return int(s[:2]) * 60 + int(s[3:])
    
    sum_ = defaultdict(int)
    dic = {}
    for r in records:
        t, num, typ = r.split()
        if typ == 'IN':
            dic[num] = convert(t)
        else:
            sum_[num] += convert(t) - dic[num]
            del dic[num]
            
    for k in dic.keys():
        sum_[k] += convert("23:59") - dic[k]
        
    ans = {}
    for k in sum_.keys():
        if sum_[k] <= fees[0]:
            ans[k] = fees[1]
        else:
            ans[k] = fees[1] + ceil((sum_[k] - fees[0]) / fees[2]) * fees[3]
    
    answer = [ans[k] for k in sorted(ans)]
    return answer