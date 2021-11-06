from Color import Color
from Point import Point
import math
import time
import random


class Triangle:
    def __init__(self):
        self.first = Point(0, 0)
        self.second = Point(1, 0)
        self.third = Point(0, 1)
        self.color = Color.red

    def area(self):
        length_a = math.sqrt((self.second.x - self.first.x) * (self.second.x - self.first.x) +
                             (self.second.y - self.first.y) * (self.second.y - self.first.y))
        length_b = math.sqrt((self.third.x - self.first.x) * (self.third.x - self.first.x) +
                             (self.third.y - self.first.y) * (self.third.y - self.first.y))
        length_c = math.sqrt((self.second.x - self.third.x) * (self.second.x - self.third.x) +
                             (self.second.y - self.third.y) * (self.second.y - self.third.y))
        p = (length_a + length_b + length_c) / 2
        return math.sqrt(p * (p - length_a) * (p - length_b) * (p - length_c))

    def display(self, file):
        file.write("Triangle \n First point X: " + str(self.first.x) + "\n First point Y: " + str(self.first.y) +
                   "\n Second point X: " + str(self.second.x) + "\n Second point Y: " + str(self.second.y) +
                   "\n Third point X: " + str(self.third.x) + "\n Third point Y: " + str(self.third.y) + "\n Area: " +
                   str(self.area()) + "\n")

    def generate(self):
        random.seed(time.time())
        self.first.x = random.randint(-100, 100)
        self.first.y = random.randint(-100, 100)
        self.second.x = random.randint(-100, 100)
        self.second.y = random.randint(-100, 100)
        self.third.x = random.randint(-100, 100)
        self.third.y = random.randint(-100, 100)

    def read(self, file):
        line = file.readline()
        split_line = line.split()
        self.first.x = int(split_line[0])
        self.first.y = int(split_line[1])
        self.second.x = int(split_line[2])
        self.second.y = int(split_line[3])
        self.third.x = int(split_line[4])
        self.third.y = int(split_line[5])
