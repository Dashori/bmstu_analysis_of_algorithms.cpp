from random import randint


def input_matrix(size):
    """
        Ввод матрицы.
    """

    matrix = []

    print("\nВведите матрицу стоимостей:")
    for i in range(size):
        matrix.append([])

        for j in range(size):
            matrix[i].append(int(input()))

    return matrix


def print_matrix(matrix):
    """
        Печать матрицы.
    """

    for i in range(len(matrix[0])):
        for j in range(len(matrix[0])):
            print(matrix[i][j], end = " ")
        
        print("")


def get_random_matrix(size, low, top):
    """
        Случайная матрица.
    """

    matrix = [[0 for i in range(size)] for j in range(size)]

    for i in range(size):
        for j in range(i + 1, size):
            value = randint(low, top)
            matrix[i][j] = value
            matrix[j][i] = value

    return matrix


def get_file_matrix(file):
    """
        Получить матрицу из файла.
    """

    f = open(file, "r")
    size = int(f.readline())

    matrix = [[0 for i in range(size)] for j in range(size)]

    i = 0

    for row in f.readlines():
        j = 0
        for num in row.split():
            matrix[i][j] = int(num)
            j += 1
        i += 1
    
    f.close()

    return matrix
