N, B = map(int, input().split())
ch = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
ans = ""

while N != 0:
    ans += ch[N % B]
    N //= B
print(ans[::-1])