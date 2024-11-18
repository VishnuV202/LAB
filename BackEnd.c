#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 100;
int ag = 0, z = 1;

void main() {
    char a[50], id[50], mov[] = "MOVF", mul[] = "MULF", div[] = "DIVF", add[] = "ADDF", sub[] = "SUBF";
    int i = 0, j = 0, len = 0, s = 0, e = 0, r = 1;

    printf("\nEnter the code: ");
    fgets(a,sizeof(a),stdin); // Note: 'gets' is unsafe; consider using 'fgets' in production code.
    len = strlen(a);

    for (i = 0; i < len; i++) {
        if (a[i] == '=') {
            for (j = i + 1; j < len; j++) {
                if (a[j] == 'i') { // Assuming 'i' is part of an identifier (e.g., 'id1')
                    printf("\n%s ", mov);
                    printf("%c%c%c, R%d", a[j], a[j + 1], a[j + 2], r++);
                }
            }
        } else if (isdigit(a[i])) {
            if (isdigit(a[i + 1])) {
                printf("\n%s #%c%c, R%d", mov, a[i], a[i + 1], r++);
            }
        }
    }

    // Traverse in reverse to handle operations
    for (i = len - 1; i >= 0; i--) {
        if (a[i] == '+') {
            printf("\n%s ", add);
            e = a[i - 1];
            e--;
            s = e;
            if (a[i + 1] == 'i') {
                printf("R%c, R%d", e, r - 1);
            }
        } else if (a[i] == '-') {
            printf("\n%s ", sub);
            e = a[i - 1];
            e--;
            s = e;
            if (a[i + 1] == 'i') {
                printf("R%c, R%c", (a[i + 3] - 1), s);
            } else {
                printf("R%c, R%d", e, r - 1);
            }
        } else if (a[i] == '*') {
            printf("\n%s ", mul);
            e = a[i - 1];
            e--;
            s = e;
            if (a[i + 1] == 'i') {
                printf("R%c, R%c", (a[i + 3] - 1), s);
            } else {
                printf("R%c, R%d", e, r - 1);
            }
        } else if (a[i] == '/') {
            printf("\n%s ", div);
            e = a[i - 1];
            e--;
            s = e;
            if (a[i + 1] == 'i') {
                printf("R%c, R%c", (a[i + 3] - 1), s);
            } else {
                printf("R%c, R%d", e, r - 1);
            }
        }
    }
    
    printf("\n%s R1, id1", mov);
}

/*
    id1=id2*id3+id4
*/