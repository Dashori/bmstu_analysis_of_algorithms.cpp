import matplotlib.pyplot as plot
import math
import numpy as np

file = open("result.txt", "r") 

index = []
lev = []
dam = []
damRC = []
damR =[]

numbers = []

while True:
    line = file.readline()

    if not line:
        break

    numbers = [int(x) for x in line.split()]

    index.append(numbers[0])
    lev.append(numbers[1])
    dam.append(numbers[2])
    damRC.append(numbers[3])
    damR.append(numbers[4])

plot.ylabel("Время(в тиках)")
plot.xlabel("Длина слова")
plot.grid(True)

plot.plot(index, lev, color = "red", label = "Итеративный (Левенштейн)")
plot.plot(index, dam, color = "yellow", label = "Итеративный (Дамерау - Левенштейн)")

# plot.plot(index, damR, color = "green", label = "Рекурсивный (Дамерау - Левенштейн)")
plot.plot(index, damRC, color = "blue", label = "Рекурсивный  с кэшем (Дамерау - Левенштейн)")

plot.legend(loc="upper left")

plot.savefig("result.png")


