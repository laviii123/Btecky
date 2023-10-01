// repeatedly swap 2 elements if they are in wrong order
// https://www.youtube.com/watch?v=xcPFUCh0jT0&t
#include <stdio.h>

int main() {
        int n = 6;
        int arr[] = {12, 45, 23, 51, 19, 8};
        for (int i = 0; i < n - 1; i++) { // for n sized array, sorting procedure needs to be done n - 1 times
                for (int j = 0; j < n - 1; j++) { // traversing the array until just before the last element
                        if (arr[j] > arr[j + 1]) { // check if adjcent is smaller or not
                                int temp = arr[j + 1]; // swap if not in order: smaller < larger
                                arr[j + 1] = arr[j];
                                arr[j] = temp;
                        }
                }
        }

        for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]); // ascending order
        }

        return 0;
}