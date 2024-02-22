visited = [False] * 1000

def f(x):
    ret = str(int(x[0]) * len(x))
    if ret == x:
        print('FA')
        exit(0)
    if visited[int(ret)]:
        print('NFA')
        exit(0)

    visited[int(ret)] = True
    f(ret)

f(input())