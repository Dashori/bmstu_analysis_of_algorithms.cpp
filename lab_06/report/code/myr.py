def ant_algorithm(matrix, size, a, b, p, count_days):
    min_cost = inf
    q = get_q(matrix, size)
    proximity = get_proximity(matrix, size)
    pheromones = [[START_PHEROMON 
    for i in range(size)] for j in range(size)]
    count_ants = size

    for _ in range(count_days):
        cities = [city for city in range(size)]
        visited = get_visited_cities(cities, count_ants)

        for ant in range(count_ants):
            while len(visited[ant]) != count_ants:
                pk = get_probability(pheromones, proximity,
                                     visited, a, b, ant, size)
                next_city = choose_city(pk)
                visited[ant].append(next_city)
            visited[ant].append(visited[ant][0])

            now_cost = get_cost(matrix, visited[ant])

            if now_cost < min_cost:
                min_cost = now_cost
                min_route = visited[ant]

        pheromones = update_pheromon(visited,
        matrix, pheromones, size, p, q)

    return min_route, min_cost
