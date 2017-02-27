import numpy as np
import matplotlib.pyplot as plt

inp=np.genfromtxt('output.txt', delimiter=' ')

fig=plt.figure()
ax=plt.axes()
plt.grid()
plt.ylabel(r'Tiempo ($t$)')
plt.xlabel('Oscilador')
#for i in range(len(inp[:,0])):
#    plt.plot(inp[i,:])
plt.imshow(inp)
plt.colorbar()
plt.savefig('oscilador.pdf', format='pdf')
plt.close()
