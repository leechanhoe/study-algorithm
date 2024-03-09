def count_unique_cyclic_words(words):
    unique_cyclic_words = set()

    for word in words:
        # 순환 변형 생성
        cyclic_variations = set(word[i:] + word[:i] for i in range(len(word)))
        # 이미 등록된 순환 변형이 있는지 확인
        if not any(cyclic_variation in unique_cyclic_words for cyclic_variation in cyclic_variations):
            unique_cyclic_words.add(word)  # 새로운 순환 단어 집합에 추가

    # 고유 순환 단어 집합의 크기 반환
    return len(unique_cyclic_words)

# 입력 예제
n = int(input())
words = [input() for _ in range(n)]

# 서로 다른 단어의 개수 출력
print(count_unique_cyclic_words(words))