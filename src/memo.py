import numpy as np
from scipy.spatial.distance import cdist

# 데이터 정의
c1 = np.array([[1,1], [2,2], [2,3]])
c2 = np.array([[4,1], [4,2], [5,4]])

# cdist 함수를 사용해 유클리디안 거리 계산
distances = cdist(c1, c2, 'euclidean')

# 결과 출력
print(distances)
