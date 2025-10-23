#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int inputSet(int set[]);
int isInSet(int element, int set[], int size);
int setUnion(int a[], int sizeA, int b[], int sizeB, int result[]);
int setIntersection(int a[], int sizeA, int b[], int sizeB, int result[]);
int setDifference(int a[], int sizeA, int b[], int sizeB, int result[]);
void printSet(int set[], int size);


int inputSet(int set[]) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    return n;
}


int isInSet(int element, int set[], int size) {
    for (int i = 0; i < size; i++) {
        if (set[i] == element)
            return 1;
    }
    return 0;
}


int setUnion(int a[], int sizeA, int b[], int sizeB, int result[]) {
    int k = 0;
    for (int i = 0; i < sizeA; i++) {
        result[k++] = a[i];
    }
    for (int i = 0; i < sizeB; i++) {
        if (!isInSet(b[i], a, sizeA)) {
            result[k++] = b[i];
        }
    }
    return k;
}

/
int setIntersection(int a[], int sizeA, int b[], int sizeB, int result[]) {
    int k = 0;
    for (int i = 0; i < sizeA; i++) {
        if (isInSet(a[i], b, sizeB)) {
            result[k++] = a[i];
        }
    }
    return k;
}


int setDifference(int a[], int sizeA, int b[], int sizeB, int result[]) {
    int k = 0;
    for (int i = 0; i < sizeA; i++) {
        if (!isInSet(a[i], b, sizeB)) {
            result[k++] = a[i];
        }
    }
    return k;
}


void printSet(int set[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}


int main() {
    int A[MAX], B[MAX], result[MAX];
    int sizeA = 0, sizeB = 0, sizeResult;
    int choice;

    printf("Input Set A:\n");
    sizeA = inputSet(A);

    printf("Input Set B:\n");
    sizeB = inputSet(B);

    do {
        printf("\n--- Menu ---\n");
        printf("1. Union\n");
        printf("2. Intersection\n");
        printf("3. Difference (A - B)\n");
        printf("4. Difference (B - A)\n");
        printf("5. Print Sets\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sizeResult = setUnion(A, sizeA, B, sizeB, result);
                printf("Union: ");
                printSet(result, sizeResult);
                break;
            case 2:
                sizeResult = setIntersection(A, sizeA, B, sizeB, result);
                printf("Intersection: ");
                printSet(result, sizeResult);
                break;
            case 3:
                sizeResult = setDifference(A, sizeA, B, sizeB, result);
                printf("Difference (A - B): ");
                printSet(result, sizeResult);
                break;
            case 4:
                sizeResult = setDifference(B, sizeB, A, sizeA, result);
                printf("Difference (B - A): ");
                printSet(result, sizeResult);
                break;
            case 5:
                printf("Set A: ");
                printSet(A, sizeA);
                printf("Set B: ");
                printSet(B, sizeB);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    return 0;
}
