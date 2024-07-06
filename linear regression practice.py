import numpy as np

def simple_linear_regression(x, y):
    n = len(x)
    mean_x, mean_y = np.mean(x), np.mean(y)
    b1 = sum((x[i] - mean_x) * (y[i] - mean_y) for i in range(n)) / sum((x[i] - mean_x) ** 2 for i in range(n))
    b0 = mean_y - b1 * mean_x
    return b0, b1

def predict(x_new, b0, b1):
    return b0 + b1 * x_new

x = [4, 7, 9, 12, 8]
y = [5, 6, 10, 13, 11]
b0, b1 = simple_linear_regression(x, y)
print(predict(6, b0, b1)) 
