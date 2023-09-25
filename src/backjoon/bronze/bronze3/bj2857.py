ans = []
for i in range(1, 6):
    if 'FBI' in input():
        ans.append(str(i))

if ans:
    print(' '.join(ans))
else:
    print('HE GOT AWAY!')