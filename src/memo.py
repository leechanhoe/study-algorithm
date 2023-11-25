import numpy as np

def calculate_variances(data):
    # 주어진 데이터에서 x와 y를 분리합니다.
    x = data[:, 0]
    y = data[:, 1]

    # x와 y의 평균을 계산합니다.
    mean_x = np.mean(x)
    mean_y = np.mean(y)

    # x와 y의 분산을 계산합니다.
    var_x = np.var(x)
    var_y = np.var(y)

    # x와 y의 혼합분산을 계산합니다.
    cov_xy = np.mean((x - mean_x) * (y - mean_y))

    return var_x, var_y, cov_xy

# 샘플 데이터를 정의하고 함수를 호출합니다.
samples = np.array([[21,1], [21,5], [3,6], [4,1], [5,2], [5,4], [5,6]])
var_x, var_y, cov_xy = calculate_variances(samples)

print("Variance of x: ", var_x)
print("Variance of y: ", var_y)
print("Covariance of x and y: ", cov_xy)