nums = [i for i in [n * (n + 1) // 2 for n in range(1, 45)]]

def is_answer(case):
    for i in nums:
        for j in nums:
            for k in nums:
                if(i + j + k == case):
                    return 1
    return 0

for t in range(int(input())):
    print(is_answer(int(input())))