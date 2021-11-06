from Color import Color
from Point import Point
import math
import time
import random


class Circle:
    def __init__(self):
        self.center = Point(0, 0)
        self.radius = 1
        self.color = Color.red

    def area(self):
        return math.pi * self.radius * self.radius

    def display(self, file):
        file.write("Circle: \n X: " + str(self.center.x) + "\n Y: " +
                   str(self.center.y) + "\n Radius: " + str(self.radius) + "\n Area: " + str(self.area()) + "\n")

    def generate(self):
        random.seed(time.time())
        self.center.x = random.randint(-100, 100)
        self.center.y = random.randint(-100, 100)
        self.radius = random.randint(0, 50)

    def read(self, file):
        line = file.readline()
        split_line = line.split()
        self.center.x = int(split_line[0])
        self.center.y = int(split_line[1])
        self.radius = int(split_line[2])
