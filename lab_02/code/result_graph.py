import matplotlib.pyplot as plot

file = open("result.txt", "r") 

index = []
basic = []
grape = []
grapePro = []

while True:
    line = file.readline()

    if not line:
        break

    numbers = [int(x) for x in line.split()]

    index.append(numbers[0])
    basic.append(numbers[1])
    grape.append(numbers[2])
    grapePro.append(numbers[3])


plot.ylabel("Время(микросекунды)")
plot.xlabel("Размер массива")
plot.grid(True)

plot.plot(index, basic, color = "red", label = "Стандартный")
plot.plot(index, grape, color = "yellow", label = "Виноград")
plot.plot(index, grapePro, color = "green", label = "Оптимизированный Виноград")

plot.legend(loc="upper left")

plot.savefig("result.png")

