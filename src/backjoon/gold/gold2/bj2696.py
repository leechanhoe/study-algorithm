import heapq
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    lhq = [] # 중앙값 이하들 최대힙
    rhq = [] # 중앙값 초과들 최소힙
    ans = []
    for i in range((int(input()) - 1) // 10 + 1):
        for j, num in enumerate(map(int, input().split())):
            if not lhq: # 맨첫값은 그냥 푸쉬
                heapq.heappush(lhq, -num)
                ans.append(num)
                continue

            if -lhq[0] >= num: #중앙값보다 작을시 최대힙에 추가
                if len(lhq) > len(rhq):
                    heapq.heappush(rhq, -heapq.heappop(lhq)) # 왼쪽크기 <= 오른쪽크기 < 왼쪽크기 + 1 을 유지
                heapq.heappush(lhq, -num) # 주의할점 !!! 나중에 푸쉬를 해야함 

            else: #크면 최소힙에 추가
                heapq.heappush(rhq, num) # 주의할점 !!! 먼저 푸쉬를 해야한다. 이거 찾느라 30분걸렸다
                if len(lhq) <= len(rhq):
                    heapq.heappush(lhq, -heapq.heappop(rhq))

            if not j & 1: # 짝수번째만 출력
                ans.append(-lhq[0])
                
    print(len(ans))
    for i, val in enumerate(ans):
        if not i % 10 and i > 0:
            print()
        print(val, end = " ")
    print()