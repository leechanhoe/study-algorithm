def is_surprising(s):
    n = len(s)

    # D는 0부터 N-2까지
    for D in range(n - 1):
        seen_pairs = set()

        # D-쌍을 만들고, 쌍이 중복되면 놀라운 문자열이 아니므로 False
        for i in range(n - D - 1):
            pair = s[i] + s[i + D + 1]
            if pair in seen_pairs:
                return False
            seen_pairs.add(pair)

    return True


def check_surprising_strings():
    while True:
        s = input().strip()
        if s == "*":
            break

        if is_surprising(s):
            print(f"{s} is surprising.")
        else:
            print(f"{s} is NOT surprising.")


check_surprising_strings()
