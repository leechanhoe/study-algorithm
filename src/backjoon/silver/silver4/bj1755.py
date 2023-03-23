M, N = map(int, input().split())

nums = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
strNum = []
for i in range(M, N + 1):
    s = ""    
    if(i >= 10):
        s = nums[i//10]
    s += nums[i%10]
    strNum.append([s, i])

strNum.sort()
for i in range(len(strNum)):
    print(strNum[i][1], end=" ")
    if(i % 10 == 9):
        print()