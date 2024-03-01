P = int(input())
for _ in range(P):
    cnt = {"TTT": 0, "TTH": 0, "THT": 0, "THH": 0, "HTT": 0, "HTH": 0, "HHT": 0, "HHH": 0}
    arr = input()
    for i in range(38):
        cnt[arr[i:i+3]] += 1

    for k, v in cnt.items():
        print(v, end=' ')