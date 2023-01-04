from time import process_time
from matrix import get_random_matrix
from salesman import brute_force, ant_algorithm


def measure_time():
    """
        Проведение временных замеров 
        работы алгоритмов решения  
        задачи коммивояжера.
    """
    
    start = int(input("\n\nВведите начальное число городов: "))
    end = int(input("\n\nВведите конечное число городов: "))
    counts = [i for i in range(start, end + 1)]

    results = [[], []]
    stage = 0

    for count in counts:
        matrix = get_random_matrix(count, 1, 10)

        start = process_time()
        brute_force(count, matrix)
        end = process_time()
        results[0].append(end - start)

        start = process_time()
        ant_algorithm(matrix, count, 0.5, 0.5, 0.5, 100)
        end = process_time()
        results[1].append(end - start)

        stage += 1
        print("Progress: %3d%s" %((stage / len(counts)) * 100, "%"))

    return counts, results

    
def print_time():
    """
        Табличный вывод результатов
        замеров времени.
        Формат для создания таблицы
        в latex.
    """

    counts, results = measure_time()

    print("\n %s | %s | %s" %("Число городов", "Полный перебор", "Муравьиный алгоритм"))
    print("-" * (8 + 1 + 24 + 1 + 29))

    for i in range(len(counts)):
        print(" %6d | %22.6f | %27.6f" %(counts[i], results[0][i], results[1][i]))


    f_latex = open("src/data/latex_table.txt", "w")

    for i in range(len(counts)):
        f_latex.write("%4d & %10.6f & %10.6f \\\\ \\hline\n" %(counts[i], results[0][i], results[1][i]))

    f_latex.close()
