from collections import Counter

case_num = 1
while True:
    original = input().strip()
    if original == 'END':
        break
    scrambled = input().strip()

    if Counter(original) == Counter(scrambled):
        print("Case {}: same".format(case_num))
    else:
        print("Case {}: different".format(case_num))

    case_num += 1