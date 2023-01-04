def get_cost(matrix, route):
    now_cost = 0

    for num in range(len(route) - 1):
        start_city = route[num]
        end_city = route[num + 1]

        now_cost += matrix[start_city][end_city]
    
    return now_cost


def get_all_routes(cities):
    routes = []

    for route in itertools.permutations(cities, len(cities)):
        route = list(route)
        route.append(route[0])
        routes.append(route)
    
    return routes


def brute_force(count, matrix):
    cities = [city for city in range(count)]
    routes = get_all_routes(cities)

    min_cost = inf

    for route in routes:
        now_cost = get_cost(matrix, route)

        if now_cost < min_cost:
            min_cost = now_cost
            min_rout = route
    
    return min_rout, min_cost