import numpy as np
import csv
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

class Animation:
    def __init__(self, coo):
        self.fig, self.ax = plt.subplots()
        self.coord = coo

    def DrawCircle(self, x, y, rad):
        self.ax.set_xlim(x-rad-1, x+rad+1)
        self.ax.set_ylim(y-rad-1, y+rad+1)
        self.ax.set_aspect('equal')
        circle = plt.Circle((x, y), rad, fill=True)
        self.ax.add_patch(circle)
        return circle

    def ClearFrame(self):
        for patch in self.ax.patches:
            patch.remove()

    def do_animate(self, frame):
        self.ClearFrame()
        x, y = coord[frame % len(coord)]
        self.DrawCircle(x, y, 0.05)
        self.ax.set_xlim(-10, 10)
        self.ax.set_ylim(0, coord[0][1])

        return self.ax.patches
    def animate(self):
        animation = FuncAnimation(self.fig, self.do_animate, frames=len(coord), repeat=False, interval=1, blit=True)
        plt.show()

fname = input("Input csv file: ")
file = open(fname, "r")
f = csv.reader(file)
next(f)
coord = []
for row in f:
    coord.append([0, float(row[1])])
print(len(coord))

ani = Animation(coord)
ani.animate()
file.close()