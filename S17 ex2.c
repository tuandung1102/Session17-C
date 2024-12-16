#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char **str) {
    char buffer[1000];
    printf("Nhap vao chuoi: ");
    getchar(); 
    fgets(buffer, 1000, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; 

    *str = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    if (*str == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    strcpy(*str, buffer);
}

void inChuoi(char *str) {
    if (str == NULL) {
        printf("Chua co chuoi nao duoc nhap!\n");
        return;
    }
    printf("Chuoi hien tai: %s\n", str);
}

void demKyTu(char *str, int *chuCai, int *chuSo, int *kyTuDacBiet) {
    *chuCai = *chuSo = *kyTuDacBiet = 0;
    if (str == NULL) {
        printf("Chua co chuoi nao de dem!\n");
        return;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            (*chuCai)++;
        } else if (isdigit(str[i])) {
            (*chuSo)++;
        } else {
            (*kyTuDacBiet)++;
        }
    }
}

int main() {
    char *str = NULL;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                free(str); 
                nhapChuoi(&str);
                break;

            case 2:
                inChuoi(str);
                break;

            case 3: {
                int chuCai, chuSo, kyTuDacBiet;
                demKyTu(str, &chuCai, &chuSo, &kyTuDacBiet);
                printf("So luong chu cai: %d\n", chuCai);
                break;
            }

            case 4: {
                int chuCai, chuSo, kyTuDacBiet;
                demKyTu(str, &chuCai, &chuSo, &kyTuDacBiet);
                printf("So luong chu so: %d\n", chuSo);
                break;
            }

            case 5: {
                int chuCai, chuSo, kyTuDacBiet;
                demKyTu(str, &chuCai, &chuSo, &kyTuDacBiet);
                printf("So luong ky tu dac biet: %d\n", kyTuDacBiet);
                break;
            }

            case 6:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long thu lai!\n");
        }
    } while (choice != 6);

    free(str);
    return 0;
}

