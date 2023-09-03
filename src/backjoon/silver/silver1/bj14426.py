import sys
input = lambda : sys.stdin.readline().rstrip()

class Node(object):
    def __init__(self, key, data=None):
        self.key = key
        self.data = data
        self.children = {}

class Trie(object):
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        curr_node = self.head
        for char in string:
            if char not in curr_node.children.keys():
                curr_node.children[char] = Node(char)
            
            curr_node = curr_node.children[char]
    
    def search(self, string):
        curr_node = self.head

        for char in string:
            if char in curr_node.children:
                curr_node = curr_node.children[char]
            else:
                return False
            
        return True

N, M = map(int, input().split())
word_trie = Trie()

for _ in range(N):
    word = input()
    word_trie.insert(word)

cnt = 0
for _ in range(M):
    word = input()
    if word_trie.search(word):
        cnt += 1

print(cnt)