def solution(friends, gifts):
    give_get = {friend : {f : 0 for f in friends} for friend in friends}
    point = {friend : 0 for friend in friends}
    ans = {friend : 0 for friend in friends}
    answer = 0
    
    for g in gifts:
        a, b = g.split()
        give_get[a][b] += 1
        point[a] += 1
        point[b] -= 1
    
    for a in friends:
        for b in friends:
            if a == b:
                continue
            
            if give_get[a][b] > give_get[b][a] or (give_get[a][b] == give_get[b][a] and point[a] > point[b]):
                ans[a] += 1
                answer = max(ans[a], answer)
    
    return answer