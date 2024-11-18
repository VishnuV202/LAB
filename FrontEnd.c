#include <stdio.h>
#include <ctype.h>
#include <string.h>

int ag = 0, z = 1;

void main() {
    char a[50], b[50];
    int ti = 0;
    int i, j, k, count;

    printf("\nEnter the code: ");
    scanf("%s", a);
    strcpy(b, a);
    
    // Handle multiplication and division first
    for (i = 0; i < strlen(b); i++) {
        if (b[i] == '*' || b[i] == '/') {
            for (j = i - 1; j >= 0 && b[j] != '+' && b[j] != '-' && b[j] != '='; j--);
            k = j + 1;
            count = 0;
            printf("\nt%d = ", ti++);
            for (j = j + 1; count < 2 && b[j] != '\0'; j++) {
                if (b[j + 1] == '+' || b[j + 1] == '-' || b[j + 1] == '*' || b[j + 1] == '/') {
                    count++;
                }
                printf("%c", b[j]);
            }
            b[k++] = 't';
            b[k++] = ti - 1 + '0';
            for (j = j, k = k; k < strlen(b); k++, j++) {
                b[k] = b[j];
            }
            b[k] = '\0'; // Null terminate the new string
            i = 0; // Restart the loop
        }
    }

    // Handle addition and subtraction
    for (i = 0; i < strlen(b); i++) {
        if (b[i] == '+' || b[i] == '-') {
            for (j = i - 1; j >= 0 && b[j] != '+' && b[j] != '-' && b[j] != '='; j--);
            k = j + 1;
            count = 0;
            printf("\nt%d = ", ti++);
            for (j = j + 1; count < 2 && b[j] != '\0'; j++) {
                if (b[j + 1] == '+' || b[j + 1] == '-') {
                    count++;
                }
                printf("%c", b[j]);
            }
            b[k++] = 't';
            b[k++] = ti - 1 + '0';
            for (j = j, k = k; k < strlen(b); k++, j++) {
                b[k] = b[j];
            }
            b[k] = '\0';
            i = 0;
        }
    }

    printf("\nFinal output: %s\n", b);
}

/*
    d=(a-b)+(a+c)+b*c
*/