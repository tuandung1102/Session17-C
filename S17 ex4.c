#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void inputArray(int **arr, int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);

    *arr = (int *)malloc((*n) * sizeof(int));
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", (*arr) + i);
    }
}

void printEvenNumbers(int *arr, int n) {
    printf("Cac phan tu la so chan: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void printPrimeNumbers(int *arr, int n) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void reverseArray(int *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    printf("Mang da duoc dao nguoc.\n");
}

void sortArray(int *arr, int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang da duoc sap xep.\n");
}

void searchElement(int *arr, int n) {
    int x;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);

    bool found = false;
    printf("Phan tu %d xuat hien tai cac vi tri: ", x);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("%d ", i);
            found = true;
        }
    }
    if (!found) {
        printf("Khong tim thay.");
    }
    printf("\n");
}

int main() {
    int *arr = NULL;
    int n = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("   1) Tang dan\n");
        printf("   2) Giam dan\n");
        printf("6. Tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(&arr, &n);
                break;
            case 2:
                printEvenNumbers(arr, n);
                break;
            case 3:
                printPrimeNumbers(arr, n);
                break;
            case 4:
                reverseArray(arr, n);
                break;
            case 5: {
                int sortChoice;
                printf("1. Tang dan\n2. Giam dan\nLua chon cua ban: ");
                scanf("%d", &sortChoice);
                sortArray(arr, n, sortChoice == 1);
                break;
            }
            case 6:
                searchElement(arr, n);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);

    free(arr);
    return 0;
}

