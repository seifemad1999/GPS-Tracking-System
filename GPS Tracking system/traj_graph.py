import numpy as np
import sys
import matplotlib.pyplot as plt

np.set_printoptions(threshold=sys.maxsize)

read_file=input('Please enter file name to read: ')

test2_file=open(read_file, 'r', encoding = 'utf-8')

matrix_data = np.genfromtxt(test2_file)

x = matrix_data[:,3]

y = matrix_data[:,-2]

plt.plot(x,y)
plt.show()