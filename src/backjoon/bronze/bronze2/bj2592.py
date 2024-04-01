from collections import Counter

numbers = [int(input()) for _ in range(10)]
average = sum(numbers) // len(numbers)

counts = Counter(numbers)
most_common_number = counts.most_common(1)[0][0]

print(average, most_common_number)