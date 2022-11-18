import matplotlib.pyplot as plot

file = open("result.txt", "r") 

size = []
simple = []
parallel = []

while True:
    line = file.readline()

    if not line:
        break

    numbers = [int(x) for x in line.split()]

    size.append(numbers[0])
    simple.append(numbers[1])
    parallel.append(numbers[2])

plot.ylabel("Время(в микросекундах)")
plot.xlabel("Количество потоков")
plot.grid(True)

plot.plot(size, simple, color = "blue", label = "Без потоков")
plot.plot(size, parallel, color = "green", label = "С потоками")

plot.legend(loc="upper left")

plot.savefig("resultParallel.png")

