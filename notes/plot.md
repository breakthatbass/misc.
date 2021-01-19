# matplotlib notes

A basic graph with some notes. Below is a `.png` of what this program would produce.

```Python
import matplotlib.pyplot as plt

# the indicators on the x axis
# we will use this for all the plots on the graph
list_x = [15, 30, 45, 60, 90, 120]

# NOTE: len(list_x) needs to be the same as any of the y lists

# each plot has it's own y axis
slow_y = [3.9, 8.5, 12.75, 16.75, 24, 32]
# after we have the y, we can plot it and give it a label for the legend
plt.plot(list_x, slow_y, marker='.', label='concurrent list')

fast_y = [2.5, 5.5, 7.25, 10, 14.5, 20]
plt.plot(list_x, fast_y, marker='.', label='optimized concurrent list')

norm_y = [1.1, 2.1, 3.1, 4.15, 6.1, 8.2]
plt.plot(list_x, norm_y, marker='.', label='single thread list')

# label the x and y axes
plt.xlabel("no. of nodes (million)")
plt.ylabel("time (seconds)")

# give the graph a title
plt.title("concurrent linked list with 3 threads")

# make the legend
plt.legend()

# get it all together
plt.show()

# that's it!
```

### The above program produces this graph:
![list plot](plot.png)