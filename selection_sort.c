#include <stdio.h>

int main() {
        int n = 7;
        int arr[] = {12, 45, 23, 37, 51, 19, 8};

        for (int i = 0; i < n - 1; i++) {
                for (int j = i; j < n; j++) {
                        if (arr[j] < arr[i]) {
                                int temp = arr[j];
                                arr[j] = arr[i];
                                arr[i] = temp;
                        }
                }
        }
        for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
        }

        return 0;
}