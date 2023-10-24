# def levenshtein_distance(a, b):
#     if a == b:
#         return 0
#     if len(a) < len(b):
#         a, b = b, a
#     if not a:
#         return len(b)

#     dp_matrix = []
#     previous_row = list(range(len(b) + 1))
#     dp_matrix.append(previous_row)
    
#     for i, column1 in enumerate(a):
#         current_row = [i + 1]
#         for j, column2 in enumerate(b):
#             insertions = previous_row[j + 1] + 1
#             deletions = current_row[j] + 1       
#             substitutions = previous_row[j] + (column1 != column2)
#             current_row.append(min(insertions, deletions, substitutions))
        
#         previous_row = current_row
#         dp_matrix.append(previous_row)

#     # DP 행렬 출력
#     print("\n".join([" ".join(map(str,row)) for row in dp_matrix]))
    
#     return previous_row[-1]

# print(levenshtein_distance("recognition", "revginaton"))

# def damerau_levenshtein_distance(a, b):
#     len_a = len(a)
#     len_b = len(b)

#     dp_matrix = [[0 for _ in range(len_b + 1)] for _ in range(len_a + 1)]
    
#     for i in range(len_a + 1):
#         dp_matrix[i][0] = i

#     for j in range(len_b + 1):
#         dp_matrix[0][j] = j

#     for i in range(1, len_a + 1):
#         for j in range(1, len_b + 1):
#             cost = int(a[i - 1] != b[j - 1])
#             deletion = dp_matrix[i - 1][j] + 1
#             insertion = dp_matrix[i][j - 1] + 1
#             substitution = dp_matrix[i - 1][j - 1] + cost
#             dp_matrix[i][j] = min(deletion, insertion, substitution)

#             if i > 2 and j >2 and a[i-2]==b[j-2]:
#                 transposition=dp_matrix[i-2][j-2]+cost
#                 if(dp_matrix[i][j]>transposition):
#                     dp_matrix[i][j]=transposition

#     # DP 행렬 출력
#     print("\n".join([" ".join(map(str,row)) for row in dp_matrix]))
    
#     return dp_matrix[-1][-1]

# print(damerau_levenshtein_distance("recognition", "revginaton"))

def damerau_levenshtein_distance(s1, s2):
    """
    Calculate the Damerau–Levenshtein distance between two strings.
    """
    len_s1 = len(s1)
    len_s2 = len(s2)
    d = [[0] * (len_s2 + 1) for _ in range(len_s1 + 1)]

    for i in range(len_s1 + 1):
        d[i][0] = i
    for j in range(len_s2 + 1):
        d[0][j] = j

    for i in range(1, len_s1 + 1):
        for j in range(1, len_s2 + 1):
            cost = 0 if s1[i - 1] == s2[j - 1] else 1
            d[i][j] = min(
                d[i - 1][j] + 1,  # deletion
                d[i][j - 1] + 1,  # insertion
                d[i - 1][j - 1] + cost,  # substitution
            )
            if i > 1 and j > 1 and s1[i - 1] == s2[j - 2] and s1[i - 2] == s2[j - 1]:
                d[i][j] = min(d[i][j], d[i - 2][j - 2] + cost)  # transposition

    print("\n".join([" ".join(map(str,row)) for row in d]))

    return d[len_s1][len_s2]


# Example usage
s1 = "recognition"
s2 = "revginaton"

distance = damerau_levenshtein_distance(s1, s2)
print(f"Damerau–Levenshtein distance between '{s1}' and '{s2}': {distance}")