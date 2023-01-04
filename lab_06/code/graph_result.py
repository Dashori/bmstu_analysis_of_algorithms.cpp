import matplotlib.pyplot as plt
from time_test import measure_time


def get_graph_result():
    """
        Графический вывод результатов
        замеров времени.
    """

    counts, results = measure_time()

    fig = plt.figure(figsize=(10, 7))
    plot = fig.add_subplot()
    plot.plot(counts, results[0], label = "Полный перебор")
    plot.plot(counts, results[1], label = "Муравьиный алгоритм")
    plt.legend()
    plt.grid()
    plt.title("Сравнение временных характеристик: задача коммивояжера")
    plt.ylabel("Время работы(c)")
    plt.xlabel("Число городов")

    plt.show()

