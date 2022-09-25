from collections import deque
import sys
import heapq
from copy import deepcopy


def bfs():  # 너비 우선 탐색 - 완전탐색이므로 최적해를 구한다
    print("목표 상태를 입력하세요.\n예시\n1 2 3\n4 5 6\n7 8 0")
    goal = []  # 1차원 배열로 저장
    for i in range(3):
        goal += input().split()

    print("처음 상태를 입력하세요.")
    board = []  # 1차원 배열로 저장
    for i in range(3):
        board += input().split()

    dq = deque()
    dq.append([board, board.index("0"), 0])
    visit = {}
    visit["".join(board)] = True

    while dq:
        now, blank, cnt = dq.popleft()
        if now == goal:
            print(f"최소 이동 횟수 : {cnt}")
            exit(0)

        for dir in [1, -1, 3, -3]:  # 우, 좌, 하, 상
            nBlank = dir + blank

            if 0 <= nBlank < 9:
                next = deepcopy(now)
                next[blank], next[nBlank] = next[nBlank], next[blank]

                conv = "".join(next)  # 방문체크를 하기위해 현재 상태를 문자열로 변환
                if conv not in visit:  # 공간복잡도를 줄이기 위해 딕셔너리로 방문체크
                    visit[conv] = True
                    dq.append([next, nBlank, cnt + 1])
    print("도달할 수 없는 목표입니다.")


def h(board, goal):  # 휴리스틱 함수 -> 목표와 다른 칸의 개수를 반환
    ret = 0
    for i in range(9):
        if(board[i] != goal[i]):
            ret += 1
    return ret


def dfs(visit, now, goal, blank, cnt):  # 깊이 우선 탐색 dfs(방문체크, 현재상태, 목표상태, 0의 위치, 현재까지의 비용)
    if now == goal:
        print(f"최소 이동 횟수 : {cnt}")

    if cnt > 2987:  # 스택오버플로우 한계 - 최대 깊이를 탐색해도 정답이 없으면
        print("도달할 수 없는 목표입니다.")
        exit(0)

    hq = []
    for dir in [1, -1, 3, -3]:  # 우, 좌, 하, 상
        nBlank = blank + dir

        if 0 <= nBlank < 9:
            next = deepcopy(now)
            next[blank], next[nBlank] = next[nBlank], next[blank]

            convert = "".join(next)  # 방문체크를 하기위해 현재 상태를 문자열로 변환
            if convert not in visit:  # 공간복잡도를 줄이기 위해 딕셔너리로 방문체크
                visit[convert] = True
                # 우선순위 큐(최소힙)를 활용해 f(n)의 최솟값부터 탐색
                # cnt + h(next, goal) = g(n) + h(n)
                heapq.heappush(hq, (cnt + h(next, goal), next, nBlank))

    while hq:
        fn, next, nBlank = heapq.heappop(hq)  # 작은 값부터 꺼내 dfs
        dfs(visit, next, goal, nBlank, cnt + 1)


def aStar():  # A* 알고리즘
    sys.setrecursionlimit(10 ** 7)
    print("목표 상태를 입력하세요.\n예시\n1 2 3\n4 5 6\n7 8 0")
    goal = []  # 1차원 배열로 저장
    for i in range(3):
        goal += input().split()

    print("처음 상태를 입력하세요.")
    board = []  # 1차원 배열로 저장
    for i in range(3):
        board += input().split()

    visit = {}  # 방문체크
    visit["".join(board)] = True  # 공간복잡도를 줄이기 위해 문자열로 변환 후 딕셔너리에 저장

    dfs(visit, board, goal, board.index("0"), 0)
    print("도달할 수 없는 목표입니다.")


print("최적해를 구하는 BFS알고리즘 : 0입력\n근사해를 구하는 A*알고리즘 : 1입력")
mode = int(input())

if(mode == 0):
    bfs()
else:
    aStar()