#include <stdio.h>
#include <stdlib.h>

void nhapMang(int **arr, int *size) {
    printf("Nhap vao so phan tu: ");
    scanf("%d", size);

    *arr = (int *)malloc((*size) * sizeof(int));
    if (*arr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }

    printf("Nhap cac phan tu: \n");
    for (int i = 0; i < *size; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &((*arr)[i]));
    }
}

void hienThiMang(int *arr, int size) {
    if (size == 0) {
        printf("Mang rong!\n");
        return;
    }
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int tinhTong(int *arr, int size) {
    int tong = 0;
    for (int i = 0; i < size; i++) {
        tong += arr[i];
    }
    return tong;
}

int timMax(int *arr, int size) {
    if (size == 0) {
        printf("Mang rong!\n");
        return -1;
    }
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int *arr = NULL;
    int size = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                free(arr); 
                nhapMang(&arr, &size);
                break;

            case 2:
                hienThiMang(arr, size);
                break;

            case 3:
                printf("Do dai mang: %d\n", size);
                break;

            case 4:
                printf("Tong cac phan tu trong mang: %d\n", tinhTong(arr, size));
                break;

            case 5:
                printf("Phan tu lon nhat: %d\n", timMax(arr, size));
                break;

            case 6:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long thu lai!\n");
        }
    } while (choice != 6);

    free(arr);
    return 0;
}

