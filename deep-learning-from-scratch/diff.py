import numpy as np
import matplotlib.pylab as plt

def numerical_diff(f, x):
    h = 1e-4
    return (f(x+h)-f(x-h))/(2*h)

def function_1(x):
    return 0.01 * x**2 + 0.1*x

def function_2(x):
    return x[0]**2 + x[1]**2

"""
x = np.arange(0.0, 20.0, 0.1)
y = function_1(x)
plt.xlabel('x')
plt.ylabel('f(x)')
plt.plot(x, y)
plt.show()
"""

def numerical_diff_gradient(f, x):
    h = 1e-4
    grade = np.zeros_like(x)

    for idx in range(x.size):
        # backup x[idx]
        tmp = x[idx]

        x[idx] = tmp + h
        fxh1 = f(x)

        x[idx] = tmp - h
        fxh2 = f(x)

        grade[idx] = (fxh1 -fxh2)/(2*h) 

        # retore x[idx]
        x[idx] = tmp

    return grade

grad = numerical_diff_gradient(function_2, np.array([3.0, 4.0]))
print(grad)

def gradient_descent(f, init_x, lr=0.01, step_num=100):
    x = init_x
    for i in range(step_num):
        grad = numerical_diff_gradient(f, init_x)
        x -= lr * grad

    return x


init_x = np.array([-3.0, 4.0])
print(gradient_descent(function_2, init_x, lr=0.1))