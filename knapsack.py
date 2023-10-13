def knapsack(values, weights, capacity):
    n = len(values)
    table = [[0] * (capacity + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                table[i][w] = max(values[i - 1] + table[i - 1][w - weights[i - 1]], table[i - 1][w])
            else:
                table[i][w] = table[i - 1][w]

    selected_items = []
    w = capacity
    for i in range(n, 0, -1):
        if table[i][w] != table[i - 1][w]:
            selected_items.append(i - 1)
            w -= weights[i - 1]

    return table[n][capacity], selected_items

def main():
    n = int(input("Enter the number of items: "))
    values = []
    weights = []

    for i in range(n):
        value, weight = map(int, input(f"Enter value and weight for item {i + 1} (e.g., 60 10): ").split())
        values.append(value)
        weights.append(weight)

    capacity = int(input("Enter the knapsack capacity: "))

    max_value, selected_items = knapsack(values, weights, capacity)
    print("Maximum Value:", max_value)
    print("Selected Items:", selected_items)

if __name__ == '__main__':
    main()
