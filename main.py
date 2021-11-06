from Container import Container

container = Container()
if container.fill_container():
    exit(1)
file = open(".\outputs\output.txt", "w")
for i in range(0, container.length):
    container.figures[i].display(file)
file.write("\n\n" + str(container.length) + "\n\n\n")
container.inclusion_sort()
for i in range(0, container.length):
    container.figures[i].display(file)
file.close()