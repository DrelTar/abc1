from Color import Color
from Point import Point
import time
import random


class Rectangle:
    def __init__(self):
        self.leftTop = Point(1, 0)
        self.rightBottom = Point(0, 1)
        self.color = Color.red

    def area(self):
        return abs(self.leftTop.x - self.rightBottom.x) * abs(self.leftTop.y - self.rightBottom.y)

    def display(self, file):
        file.write("Rectangle: \n Left Top X: " + str(self.leftTop.x) + "\n Left Top Y: " + str(self.leftTop.y) +
                   "\n Right Bottom X: " + str(self.rightBottom.x) + "\n Right Bottom Y: " + str(self.rightBottom.y) +
                   "\n Area: " + str(self.area()) + "\n")

    def generate(self):
        random.seed(time.time())
        self.leftTop.x = random.randint(-100, 100)
        self.leftTop.y = random.randint(-100, 100)
        self.rightBottom.x = random.randint(-100, 100)
        self.rightBottom.y = random.randint(-100, 100)

    def read(self, file):
        line = file.readline()
        split_line = line.split()
        self.leftTop.x = int(split_line[0])
        self.leftTop.y = int(split_line[1])
        self.rightBottom.x = int(split_line[2])
        self.rightBottom.y = int(split_line[3])
