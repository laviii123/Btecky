#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to compare items by their value-to-weight ratio
int compare(const void* a, const void* b) {
    double ratioA = ((struct Item*)a)->value / (double)((struct Item*)a)->weight;
    double ratioB = ((struct Item*)b)->value / (double)((struct Item*)b)->weight;
    return (ratioB > ratioA) - (ratioB < ratioA);
}

// Greedy Knapsack Algorithm
void knapsack(struct Item items[], int n, int capacity) {
    // Sort items by their value-to-weight ratio in descending order
    qsort(items, n, sizeof(struct Item), compare);

    int currentWeight = 0;  // Current weight in the knapsack
    double totalValue = 0.0;  // Total value in the knapsack

    // Loop through the sorted items
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Include the whole item as it fits in the knapsack
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Include a fraction of the item to fill the knapsack
            int remainingCapacity = capacity - currentWeight;
            totalValue += (items[i].value / (double)items[i].weight) * remainingCapacity;
            break; // Knapsack is full
        }
    }

    printf("Maximum value in the knapsack: %.2lf\n", totalValue);
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    struct Item items[n];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    knapsack(items, n, capacity);

    return 0;
}
