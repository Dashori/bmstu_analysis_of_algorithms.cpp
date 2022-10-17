import matplotlib.pyplot as plot

file = open("resultDegree.txt", "r") 

index = []
merge = []
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


plot.ylabel("Время(в тиках)")
plot.xlabel("Размер массива")
plot.grid(True)

plot.plot(index, merge, color = "red", label = "Слиянием")
plot.plot(index, couting, color = "yellow", label = "Подсчетом")
plot.plot(index, bitton, color = "green", label = "Битонная")

plot.legend(loc="upper left")

plot.savefig("resultDegree.png")

