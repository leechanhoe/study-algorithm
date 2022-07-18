import sys
import heapq
input = lambda : sys.stdin.readline().rstrip()

for _ in range(int(input())):
    visited = [False] * 1000001
    min_heap = []
    max_heap = []
    for i in range(int(input())):
        com, n = input().split()
        if com == 'I':
            heapq.heappush(min_heap, (int(n), i))
            heapq.heappush(max_heap, (-int(n), i))
            visited[i] = True
        else:
            if n =='1':
                while max_heap and not visited[max_heap[0][1]]:
                    heapq.heappop(max_heap)
                if max_heap:
                    visited[max_heap[0][1]] = False
                    heapq.heappop(max_heap)
            else:
                while min_heap and not visited[min_heap[0][1]]:
                    heapq.heappop(min_heap)
                if min_heap:
                    visited[min_heap[0][1]] = False
                    heapq.heappop(min_heap)

    while min_heap and not visited[min_heap[0][1]]:heapq.heappop(min_heap)
    while max_heap and not visited[max_heap[0][1]]:heapq.heappop(max_heap)

    if min_heap and max_heap:
        print(-max_heap[0][0], min_heap[0][0])
    else:
        print("EMPTY")