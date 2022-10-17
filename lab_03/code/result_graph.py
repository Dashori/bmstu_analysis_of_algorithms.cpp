import matplotlib.pyplot as plot
import math
import numpy as np

file = open("result.txt", "r") 

index = []
merge = []
merge2 = []
couting = []
bitton = []


while True:
    line = file.readline()

    if not line:
        break

    numbers = [int(x) for x in line.split()]

    index.append(numbers[0])
    merge.append(numbers[1])
    couting.append(numbers[2])
    bitton.append(numbers[3])
    merge2.append(numbers[4])


plot.ylabel("Время(в тиках)")
plot.xlabel("Размер массива")
plot.grid(True)

plot.plot(index, merge, color = "red", label = "Слиянием")
plot.plot(index, merge2, color = "orange", label = "Слиянием2")
plot.plot(index, couting, color = "yellow", label = "Подсчетом")

plot.plot(index, bitton, color = "green", label = "Битонная")

plot.legend(loc="upper left")

plot.savefig("result3.png")


