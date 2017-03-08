import numpy as np
import matplotlib.pyplot as plt

inp=np.genfromtxt('posiciones.txt', delimiter=' ')
eners=np.genfromtxt('energias.txt', delimiter=' ')

fig=plt.figure()
ax=plt.axes()
plt.grid()
plt.ylabel(r'Tiempo ($t$)')
plt.xlabel('Oscilador')
plt.imshow(inp, extent=[0,64,0,len(inp[:,0])])
plt.colorbar()
plt.savefig('oscilador.pdf', format='pdf')
plt.close()

fig=plt.figure()
ax=plt.axes()
plt.grid()
plt.xlabel('Tiempo')
plt.ylabel('Energias')
plt.xlim((0, eners[-1,-1]))
plt.title(r'Energias para modos fundamentales ($E_k$)')
for i in range(len(eners[0,:])-1):
    plt.plot(eners[:,-1], eners[:,i], label=r'$k=$'+str(i+1))
plt.legend(framealpha=0.5)
plt.savefig('energias.pdf', format='pdf')
plt.close()
