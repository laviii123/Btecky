import numpy as np

def initialize_pheromone(n_ants, n_citys):
    return 0.1 * np.ones((n_ants, n_citys))

def calculate_visibility(distance_matrix):
    visibility = 1 / distance_matrix
    visibility[visibility == np.inf] = 0
    return visibility

def ant_colony_optimization(iteration, n_ants, n_citys, distance_matrix):
    m = n_ants
    n = n_citys
    e = 0.5
    alpha = 1
    beta = 2

    visibility = calculate_visibility(distance_matrix)
    pheromone = initialize_pheromone(m, n)

    best_route = None
    best_distance = np.inf

    for ite in range(iteration):
        routes = np.ones((m, n + 1), dtype=int)

        for i in range(m):
            routes[i, 0] = 1
            temp_visibility = np.array(visibility)

            for j in range(n - 1):
                cur_city = routes[i, j] - 1
                temp_visibility[:, cur_city] = 0

                p_feature = np.power(pheromone[cur_city, :], beta)
                v_feature = np.power(temp_visibility[cur_city, :], alpha)

                p_feature = p_feature[:, np.newaxis]
                v_feature = v_feature[:, np.newaxis]

                combine_feature = np.multiply(p_feature, v_feature)
                total = np.sum(combine_feature)
                probs = combine_feature / total

                cum_prob = np.cumsum(probs)
                rand_val = np.random.random()
                next_city = np.nonzero(cum_prob > rand_val)[0][0] + 1

                routes[i, j + 1] = next_city

            remaining_city = list(set(range(1, n + 1)) - set(routes[i, :-2]))[0]
            routes[i, -2] = remaining_city

        dist_costs = np.zeros((m, 1))

        for i in range(m):
            dist_costs[i] = np.sum(
                [distance_matrix[int(routes[i, j]) - 1, int(routes[i, j + 1]) - 1] for j in range(n - 1)])

        min_loc = np.argmin(dist_costs)
        min_cost = dist_costs[min_loc]

        if min_cost < best_distance:
            best_route = routes[min_loc, :]
            best_distance = min_cost

        pheromone = (1 - e) * pheromone

        for i in range(m):
            for j in range(n - 1):
                dt = 1 / dist_costs[i]
                pheromone[int(routes[i, j]) - 1, int(routes[i, j + 1]) - 1] += dt

    return best_route, best_distance

if __name__ == "__main__":
    distance_matrix = np.array([[0, 10, 12, 11, 14],
                                [10, 0, 13, 15, 8],
                                [12, 13, 0, 9, 14],
                                [11, 15, 9, 0, 16],
                                [14, 8, 14, 16, 0]])

    iterations = int(input("Enter the number of iterations:"))
    num_ants = int(input("Enter the number of ants:"))
    num_cities = int(input("Enter the number of cities:"))

    best_path, best_cost = ant_colony_optimization(iterations, num_ants, num_cities, distance_matrix)

    print('Best path:', best_path)
    print('Cost of the best path:', int(best_cost) + distance_matrix[int(best_path[-2]) - 1, 0])


