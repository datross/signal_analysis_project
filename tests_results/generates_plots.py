#!/usr/bin/python3

import matplotlib.pyplot as plt
import glob

paths = glob.glob("*.txt")

def load_file(path):
	f = open(path)
	lines = f.readlines()
	f.close()
	return [float(l) for l in lines]

def write_plots(name, v):
	plt.figure()
	plt.plot(v)
	plt.title(name)
	plt.savefig(name + ".png")

for p in paths:
	print(p)
	v = load_file(p)
	write_plots(p, v)
