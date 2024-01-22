mbti1 = {'I':'E', 'S':'N', 'T':'F', 'J':'P'}
mbti2 = {value: key for key, value in mbti1.items()}
mbti = mbti1 | mbti2

inpu = input()
for ch in inpu:
    print(mbti[ch], end='')