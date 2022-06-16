import sys

N = int(input())
t = {}
for _ in range(N):
    root, le, ri = sys.stdin.readline().rstrip().split()
    t[root] = [le, ri]

def preorder(root): # 전위 순회
    if root != '.':
        print(root, end='')
        preorder(t[root][0])
        preorder(t[root][1])

def inorder(root): # 중위 순회
    if root != '.':
        inorder(t[root][0])
        print(root, end='')
        inorder(t[root][1])

def postorder(root): # 후위 순회
    if root != '.':
        postorder(t[root][0])
        postorder(t[root][1])
        print(root, end='')

preorder('A')
print()
inorder('A')
print()
postorder('A')