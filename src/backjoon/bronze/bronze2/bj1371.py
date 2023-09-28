import sys
from collections import Counter

# Counter 객체 생성
counter = Counter(sys.stdin.read().replace("\n","").replace(" ",""))

# 가장 많이 등장한 문자의 횟수 찾기
max_count = max(counter.values())

# 가장 많이 등장한 문자들 찾기 (알파벳 순서대로)
most_common_chars = sorted([char for char, count in counter.items() if count == max_count])

# 결과 출력 (공백 없이 모든 글자를 연결)
print(''.join(most_common_chars))