import numpy as np
import matplotlib.pyplot as plt
from math import sin, cos

x = np.linspace(-1 * np.pi, 0, 1000)
x = np.append(x, -1 * np.pi)
# print(x)
y = np.sin(x)
# np.append(x, np.linspace(-1 * np.pi, 0, 1000))
# np.append(y, np.linspace(0, 0, 1000))

plt.figure(figsize=[5, 3])
plt.plot(x, y)
plt.xticks([])
plt.yticks([])
plt.show()

