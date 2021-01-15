import matplotlib.pyplot as plt

# number of elements by million
list_x = [15, 30, 45, 60, 90, 120]

# slow concurrent list
slow_y = [3.9, 8.5, 12.75, 16.75, 24, 32]
plt.plot(list_x, slow_y, marker='.', label='concurrent list')

# optimized concurrent list
fast_y = [2.5, 5.5, 7.25, 10, 14.5, 20]
plt.plot(list_x, fast_y, marker='.', label='optimized concurrent list')

# single thread (normal) list
norm_y = [1.1, 2.1, 3.1, 4.15, 6.1, 8.2]
plt.plot(list_x, norm_y, marker='.', label='single thread list')

plt.xlabel("no. of nodes (million)")
plt.ylabel("time (seconds)")
plt.title("concurrent linked list with 3 threads")

plt.legend()

plt.show()