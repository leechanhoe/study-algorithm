inpu = input()
N = (len(inpu) - 9) // 2 + 9 if len(inpu) > 9 else len(inpu)
check = [False] * (N + 1)
find_ans = False

def bt(i, arr):
    global find_ans
    if i >= len(inpu): # 숫자를 다 썼으면 정답
        find_ans = True
        print(*arr)
        return
    
    n = int(inpu[i])
    if n <= N and not check[n]: # 일단 안쓴숫자면 끼워맞춰보고
        check[n] = True
        narr = arr[:]
        narr.append(n)
        bt(i + 1, narr) # DFS 돌려봐서
        if find_ans: 
            return    
        check[n] = False # 이숫자로 답안나오면 취소하고

    if i + 1 < len(inpu):
        n = int(inpu[i:i+2]) # 두자리숫자로 해보기.  결국엔 두가지 경우중 하나다
        if n <= N and not check[n]:
            check[n] = True
            narr = arr[:]
            narr.append(n)
            bt(i + 2, narr)
            if find_ans:
                return
            check[n] = False

bt(0, [])