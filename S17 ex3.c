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

void inDaoNguoc(char *str) {
    if (str == NULL) {
        printf("Chua co chuoi nao duoc nhap!\n");
        return;
    }
    printf("Chuoi dao nguoc: ");
    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int demTu(char *str) {
    if (str == NULL) {
        printf("Chua co chuoi nao de dem!\n");
        return 0;
    }
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

void soSanhChuoi(char *str1) {
    if (str1 == NULL) {
        printf("Chua co chuoi ban dau!\n");
        return;
    }
    char *str2 = NULL;
    nhapChuoi(&str2);

    if (strlen(str2) > strlen(str1)) {
        printf("Chuoi vua nhap dai hon chuoi ban dau.\n");
    } else if (strlen(str2) < strlen(str1)) {
        printf("Chuoi vua nhap ngan hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }

    free(str2);
}

void inHoaChuoi(char *str) {
    if (str == NULL) {
        printf("Chua co chuoi nao de in hoa!\n");
        return;
    }
    printf("Chuoi in hoa: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", toupper(str[i]));
    }
    printf("\n");
}

void themChuoi(char **str1) {
    if (*str1 == NULL) {
        printf("Chua co chuoi ban dau!\n");
        return;
    }
    char *str2 = NULL;
    nhapChuoi(&str2);

    *str1 = (char *)realloc(*str1, (strlen(*str1) + strlen(str2) + 1) * sizeof(char));
    if (*str1 == NULL) {
        printf("Khong the cap phat bo nho!\n");
        free(str2);
        exit(1);
    }
    strcat(*str1, str2);

    printf("Chuoi sau khi them: %s\n", *str1);
    free(str2);
}

int main() {
    char *str = NULL;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                free(str); 
                nhapChuoi(&str);
                break;

            case 2:
                inDaoNguoc(str);
                break;

            case 3: {
                if (str == NULL) {
                    printf("Chua co chuoi de dem tu!\n");
                    break;
                }
                char *temp = strdup(str); 
                printf("So luong tu trong chuoi: %d\n", demTu(temp));
                free(temp);
                break;
            }

            case 4:
                soSanhChuoi(str);
                break;

            case 5:
                inHoaChuoi(str);
                break;

            case 6:
                themChuoi(&str);
                break;

            case 7:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long thu lai!\n");
        }
    } while (choice != 7);

    free(str); 
    return 0;
}

