from Circle import Circle
from Rectangle import Rectangle
from Triangle import Triangle
import sys
import random
import time


class Container:
    def __init__(self):
        self.figures = []
        self.length = 0

    def inclusion_sort(self):
        for i in range(0, self.length):
            cur = self.figures[i]
            ind = i
            while ind > 0 and self.figures[ind - 1].area() >= cur.area():
                self.figures[ind] = self.figures[ind - 1]
                ind -= 1
            self.figures[ind] = cur

    def fill_container(self):
        argv = sys.argv
        argc = len(sys.argv)
        if argc < 2 or argc > 3:
            print("Incorrect amount of arguments.")
            return 1
        self.length = int(argv[1])
        if argc == 3:
            if self.length < 0 or self.length > 20:
                print("Incorrect amount of figures for this test.")
                return
            file = open(argv[2])
            for i in range(0, self.length):
                type = int(file.readline())
                if type == 1:
                    self.figures.append(Circle())
                    self.figures[-1].read(file)
                elif type == 2:
                    self.figures.append(Rectangle())
                    self.figures[-1].read(file)
                elif type == 3:
                    self.figures.append(Triangle())
                    self.figures[-1].read(file)
                else:
                    print("Wrong type of figure at input file.")
                    return 1
            file.close()
        elif argc == 2:
            if self.length < 20 or self.length > 100000:
                print("Incorrect amount of figures for this test.")
                return 1
            random.seed(time.time())
            for i in range(0, self.length):
                type = random.randint(0, 2)
                if type == 0:
                    self.figures.append(Circle())
                    self.figures[-1].generate()
                elif type == 1:
                    self.figures.append(Rectangle())
                    self.figures[-1].generate()
                elif type == 2:
                    self.figures.append(Triangle())
                    self.figures[-1].generate()
        return 0
