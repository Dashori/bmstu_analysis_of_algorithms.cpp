import matplotlib.pyplot as plot

# file = open("result.txt", "r") 

size = [10, 20, 30, 40, 50]
simple = [102686, 110647, 126516, 137995, 151877]
parallel = [57213, 60790, 64714, 69191, 91153]

# while True:
#     line = file.readline()

#     if not line:
#         break

#     numbers = [int(x) for x in line.split()]

#     size.append(numbers[0])
#     simple.append(numbers[1])
#     parallel.append(numbers[2])

plot.ylabel("Время (в наносекундах)")
plot.xlabel("Количество карт")
plot.grid(True)

plot.plot(size, simple, color = "blue", label = "Линейный алгоритм")
plot.plot(size, parallel, color = "green", label = "Параллельный алгоритм")

plot.legend(loc="upper left")

plot.savefig("result.png")