import itertools
from math import inf
from random import random

from matrix import get_random_matrix, print_matrix, get_file_matrix, input_matrix

FULL = 1
ANT = 2
BOTH = 3
MIN_PHEROMON = 0.001
START_PHEROMON = 1


def get_cost(matrix, route):
    """
        Найти стоимость маршрута.
    """

    now_cost = 0

    for num in range(len(route) - 1):
        start_city = route[num]
        end_city = route[num + 1]

        now_cost += matrix[start_city][end_city]
    
    return now_cost


def get_all_routes(cities):
    """
        Получить все
        возможные маршруты.
    """

    routes = []

    for route in itertools.permutations(cities, len(cities)):
        route = list(route)
        route.append(route[0])
        routes.append(route)
    
    return routes


def brute_force(count, matrix):
    """
        Полный перебор.
    """

    cities = [city for city in range(count)]
    routes = get_all_routes(cities)

    min_cost = inf

    for route in routes:
        now_cost = get_cost(matrix, route)

        if now_cost < min_cost:
            min_cost = now_cost
            min_rout = route
    
    return min_rout, min_cost


def get_q(matrix, size):
    """
        Получить длину оптимального пути.
    """

    q = 0
    count = 0

    for i in range(size):
        for j in range(i + 1, size):
            q += matrix[i][j] * 2
            count += 2

    return q / count


def get_proximity(matrix, size):
    """
        Получить матрицу видимостей городов.

        Видимость города j из города i
        обратно пропорциональна расстоянию
        между этими городами.
    """

    proximity = [[0 for i in range(size)] for j in range(size)]

    for i in range(size):
        for j in range(i):
            proximity[i][j] = 1 / matrix[i][j]
            proximity[j][i] = proximity[i][j]
    
    return proximity


def get_visited_cities(cities, count_ants):
    """
        Получить посещенные города.

        Не те, которые надо посетить,
        чтобы все муравьи пошли по 
        разным путям.
    """

    visited = [[] for _ in range(count_ants)]

    for ant in range(count_ants):
        visited[ant].append(cities[ant])

    return visited


def get_probability(pheromones, proximity, visited, a, b, ant, city_count):
    """
        Определить вероятность
        перехода k-ого муравья
        из города i в город j.
    """

    # Вероятности того, что муравей перейдет в город city
    probabilities = [0] * city_count

    # Муравей находится в последнем посещенном городе
    now_city = visited[ant][-1]

    for city in range(city_count):
        if city not in visited[ant]:

            # Желание муравья перейти в город city 
            p = ( pheromones[now_city][city] ** a ) * \
                ( proximity[now_city][city] ** b )
            
            probabilities[city] = p
        else:
            probabilities[city] = 0
    
    # Cумма желаний муравья перейти из текущего города
    # ко всем другим еще не посещенным городам
    sum_p = sum(probabilities)

    for city in range(city_count):
        probabilities[city] /= sum_p
    
    return probabilities


def choose_city(probabilities):
    """
        Выбор города
        случайным образом.
    """

    num = random()
    value = 0

    for i in range(len(probabilities)):
        value += probabilities[i]

        if value > num:
            return i


def check_route(i, j, route):
    """
        Проверка принадлежности
        дороги (i,j) маршруту.
    """

    if i in route:
        index_i = route.index(i)

        if j == route[index_i + 1]:
            return True
    
    return False


def update_pheromon(visited, matrix, pheromones, city_count, p, q):
    """
        Обновление следов феромона.
    """

    for i in range(city_count):
        for j in range(city_count):
            add = 0

            for ant in range(city_count):
                if check_route(i, j, visited[ant]):
                    cost = get_cost(matrix, visited[ant])
                    add += q / cost
            
            pheromones[i][j] *= (1 - p) 
            pheromones[i][j] += add

            if pheromones[i][j] < MIN_PHEROMON:
                pheromones[i][j] = MIN_PHEROMON

    return pheromones


def ant_algorithm(matrix, size, a, b, p, count_days):
    """
        Муравьиный алгоритм.
    """

    min_cost = inf

    # Длина оптимального пути
    q = get_q(matrix, size)

    # Матрица видимости всех городов
    proximity = get_proximity(matrix, size)
    # Матрица феромонов
    pheromones = [[START_PHEROMON for i in range(size)] for j in range(size)]
    count_ants = size

    for _ in range(count_days):
        # Номера всех городов
        cities = [city for city in range(size)]
        # Начальные города, из которых муравьи начнут путь
        visited = get_visited_cities(cities, count_ants)

        for ant in range(count_ants):
            while len(visited[ant]) != count_ants:
                # Вероятности перехода муравья для каждого города
                pk = get_probability(pheromones, proximity,
                                     visited, a, b, ant, size)

                # Выбор следующего города
                next_city = choose_city(pk)
                visited[ant].append(next_city)
            # Замкнуть маршрут
            visited[ant].append(visited[ant][0])

            # Получить стоимость полученного маршрута
            now_cost = get_cost(matrix, visited[ant])

            if now_cost < min_cost:
                min_cost = now_cost
                min_route = visited[ant]
        
        # Обновить значения феромона на всех путях
        pheromones = update_pheromon(visited, matrix, pheromones, size, p, q)

    return min_route, min_cost


def print_route(route, cost):
    """
        Печать маршрута и его стоимости.
    """

    for num in range(len(route)):
        if num != len(route) - 1:
            print(route[num] + 1, "->", end = " ")
    
    print(route[0] + 1)

    print("Его стоимость : ", cost)


def help_salesman(alg_type):
    """
        Решение задачи
        коммивояжера.
    """

    try:
        count = int(input("\nВведите число городов: "))
    except:
        print("\nНеверно введено число городов.\n")
        return

    input_type = int(input(
"""
Выберите способ ввода матрицы стоимостей:
    1. Ручной ввод
    2. Случайная матрица
    3. Загрузить из файла
Выбор: """))

    if input_type == 1:
        matrix = input_matrix(count)
    elif input_type == 2:
        low = int(input("\nВведите нижнюю границу стоимостей: "))
        top = int(input("Введите верхнюю границу стоимостей: "))

        matrix = get_random_matrix(count, low, top)
    elif input_type == 3:
        file = input("Введите название файла: ")
        matrix = get_file_matrix(file)

    print("\nИсходная матрица стоимостей:")
    print_matrix(matrix)

    if alg_type == FULL or alg_type == BOTH:
        route1, cost1 = brute_force(count, matrix)

        print("\n\n=== Полный перебор === ")
        print("Самый короткий маршрут: ")
        print_route(route1, cost1)
    if alg_type == ANT or alg_type == BOTH:
        a = float(input("\nВведите параметр α: "))
        b = 1 - a
        p = float(input("Введите коэффициент испарения: "))
        count_day = int(input("Введите число дней: "))

        route2, cost2 = ant_algorithm(matrix, count, a, b, p, count_day)

        print("\n\n=== Муравьиный алгоритм === ")
        print("Самый короткий маршрут: ")
        print_route(route2, cost2)


def parameterization():
    """
        Параметризация.
    """

    alpha = [k / 10 for k in range(1, 10)]
    evaporation = [k / 10 for k in range(1, 10)]
    days = [10, 25, 50, 100, 200, 300, 400, 500]

    matrix1 = get_file_matrix("src/data/class1.txt")
    matrix2 = get_file_matrix("src/data/class2.txt")
    count = len(matrix1)

    _, ideal1  = brute_force(count, matrix1)
    _, ideal2 = brute_force(count, matrix2)

    result1 = open("src/data/class1_result.txt", "w")
    result2 = open("src/data/class2_result.txt", "w")

    sep = " & "
    ender = " \\\\"

    stage = 0
    count_all = len(alpha) * len(evaporation)

    for a in alpha:
        b = 1- a
        for p in evaporation:
            stage += 1
            for day in days:
                _, first = ant_algorithm(matrix1, count, a, b, p, day)
                _, second = ant_algorithm(matrix2, count, a, b, p, day)

                str1 = "%4.1f%s%4.1f%s%4d%s%5d%s%5d%s\n" \
                    % (a, sep, p, sep, day, sep, ideal1, sep, first - ideal1, ender)

                str2 = "%4.1f%s%4.1f%s%4d%s%5d%s%5d%s\n" \
                    % (a, sep, p, sep, day, sep, ideal2, sep, second - ideal2, ender)

                result1.write(str1)
                result2.write(str2)
            
            print("Progress: %3d%s" %((stage / count_all) * 100, "%"))

    result1.close()
    result2.close()
