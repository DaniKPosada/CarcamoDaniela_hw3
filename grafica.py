import numpy as np
import matplotlib.pyplot as plt

archivo=np.genfromtxt("tiempocero.txt",delimiter="",skip_header=0)
from mpl_toolkits.mplot3d import Axes3D

fig = plt.figure()
ax = Axes3D(fig)
X = np.arange(0, 1, 0.01)
Y = np.arange(0, 1, 0.01)
X, Y = np.meshgrid(X, Y)
contador=0
R=np.ones((100,100))
for i in range(100):
	for j in range(100):
		R[i,j]=archivo[contador];
		contador=contador+1;

ax.plot_surface(X, Y, R, rstride=1, cstride=1, cmap='cool')
plt.savefig("tiempocero.pdf")

archivo1=np.genfromtxt("tiempo60.txt",delimiter="",skip_header=0)
fig1 = plt.figure()
ax = Axes3D(fig1)
X = np.arange(0, 1, 0.01)
Y = np.arange(0, 1, 0.01)
X, Y = np.meshgrid(X, Y)
contador=0
R=np.ones((100,100))
for i in range(100):
	for j in range(100):
		R[i,j]=archivo1[contador];
		contador=contador+1;

ax.plot_surface(X, Y, R, rstride=1, cstride=1, cmap='cool')
plt.savefig("tiempo60.pdf")
