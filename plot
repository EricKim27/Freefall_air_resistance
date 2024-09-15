#!/usr/bin/env python

import matplotlib.pyplot as plt
import csv

fname = input("Input the csv filename: ")
title = fname.split(".")[0].split("/")[-1].strip("Fall_")
y = []
with open(fname, "r") as f:
    data = csv.reader(f)
    next(data)
    for row in data:
        y.append(float(row[1]))

plt.plot(y)
plt.title(f"Free fall of an object falling from {title}")
plt.show()
