L, C = map(int, input().split())
char = sorted(input().split())
vo = ['a', 'e', 'i', 'o', 'u']

def solve(li, idx, vowel):
    size = len(li)
    if size == L:
        if 1 <= vowel and L - vowel >= 2:
            print(''.join(li))
        return

    for i in range(idx, C):
        if char[i] in vo:
            solve(li + [char[i]], i + 1, vowel + 1)
        else:
            solve(li + [char[i]], i + 1, vowel)

solve([], 0, 0)