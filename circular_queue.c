#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 3

void insert(int*, int*, int*, int*);
void delete(int*, int*, int*);
void disp(int*, int*, int*);

int main() {
        int queue[MAXSIZE], f = -1, r = -1, c, val;
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        while (1) {
                printf("Enter choice: ");
                scanf("%d", &c);

                switch (c) {
                        case 1: printf("Enter value to insert: ");
                                scanf("%d", &val);
                                insert(queue, &f, &r, &val); break;
                        case 2: delete(queue, &f, &r); break;
                        case 3: disp(queue, &f, &r); break;
                        case 4: exit(1);
                        default: printf("Invalid option\n");
                }
        }

        return 0;
}

void insert(int* queue, int* f, int* r, int* val) {
        if ((*f == 0 && *r == MAXSIZE - 1) || (*f == *r + 1)) {
                printf("Queue Overflow\n");
        } else {
                if (*r == -1) {
                        *f = *r = 0;
                } else if (*r == MAXSIZE - 1) {
                        *r = 0;
                } else {
                        (*r)++;
                }
                queue[*r] = *val;
        }
}

void delete(int* queue, int* f, int* r) {
        if (*f == -1) {
                printf("Queue Underflow\n");
        } else {
                printf("%d\n", queue[*f]);
                if (*f == *r) {
                        *f = *r = -1;
                } else if (*f == MAXSIZE - 1) {
                        *f = 0;
                } else {
                        (*f)++;
                }
        }
}

void disp(int* queue, int* f, int* r) {
        if (*f == -1) {
                printf("Queue Underflow\n");
        } else {
                printf("Queue Elements: ");
                if (*f <= *r) {
                        for (int i = *f; i <= *r; i++) {
                                printf("%d ", queue[i]);
                        }
                } else {
                        for (int i = 0; i <= *r; i++) {
                                printf("%d ", queue[i]);
                        }
                        for (int i = *f; i <= MAXSIZE - 1; i++) {
                                printf("%d ", queue[i]);
                        }
                }
                printf("\n");
        }
}