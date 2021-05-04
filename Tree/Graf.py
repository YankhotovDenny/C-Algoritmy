import numpy as np
import matplotlib.pyplot as plt

f = open('D:\TreeSearchTrue.txt', 'r')
m = []
omega_precession = []

for i in f:
    m.append(float(i.split('-')[0]))
    omega_precession.append(float(i.split('-')[1]))

m = np.array(m)
omega_precession = np.array(omega_precession)

# мнк
p, v = np.polyfit(m, omega_precession, deg=1, cov=True)
x = np.arange(0, max(m)+10, .0001)
p_f = np.poly1d(p)


plt.grid(True)

plt.axis([0, max(m), 0, max(omega_precession)+1])
plt.plot(m[0:], omega_precession[0:], 'bs')
print(p[0])
print(v[0][0] ** 0.5)
plt.xlabel('N элементов')
plt.ylabel('время в мс')
plt.show()