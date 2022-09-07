'''
	random_walk.py

	this is a program to visualize the random walk hypothesis.
	
	from wikipedia:
		The random walk hypothesis is a financial theory stating that 
		stock market prices evolve according to a random walk (so price 
		changes are random) and thus cannot be predicted.
'''

import matplotlib.pyplot as plt
import numpy as np

class randomwalk:
	def __init__(self, steps):
		self.steps = steps
		self.trading_days = []
	
	def walk(self):
		step_options = [-1, 0, 1]
		last_price = 0

		for i in range(0, self.steps):
			n = np.random.randint(0, len(step_options))
			last_price += step_options[n]
			self.trading_days.append(last_price)

	def make_plot(self, filename='plot.png', show=False):
		thold_x = np.arange(1, self.steps+1)
		plt.plot(thold_x, self.trading_days)

		plt.xlabel("Trading Days")
		plt.ylabel("Price")

		# give the graph a title
		plt.title("Random Walk Theory")
		plt.savefig(filename, dpi=1000)
		if show:
			plt.show()

	
if __name__ == '__main__':
	for i in range(0, 4):
		r = randomwalk(1000)
		r.walk()
		fp = f'plot_{i+1}.png'
		r.make_plot('plot.png')
