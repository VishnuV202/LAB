
#include <stdio.h>
#include <string.h>

struct op {
    char l;         
    char r[20];    
} op[10], pr[10]; 

void main() {
    int a, i, k, j, n, z = 0, m, q;
    char *p;
    char nu[] = "\0"; 
    printf("\nEnter the number of values: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nLeft: ");
        scanf(" %c", &op[i].l); 
        printf("Right: ");
        scanf("%s", op[i].r);   
    }

    printf("\nIntermediate code:\n");
    for (i = 0; i < n; i++) {
        printf("%c = %s\n", op[i].l, op[i].r); 
    }


    for (i = 0; i < n; i++) {
        char temp = op[i].l;
        int is_used = 0;
        for (j = i + 1; j < n; j++) {
            if (strchr(op[j].r, temp)) {
                is_used = 1;
                break;
            }
        }
        if (is_used || i == n - 1) {
            pr[z++] = op[i];
        }
    }

    printf("\nAfter dead code elimination:\n");
    for (k = 0; k < z; k++) {
        printf("%c = %s\n", pr[k].l, pr[k].r); 
    }

    for (m = 0; m < z; m++) {
        for (j = m + 1; j < z; j++) {
            if (strcmp(pr[m].r, pr[j].r) == 0) {
                char replace = pr[m].l;
                char target = pr[j].l;
                pr[j].l = replace;
                
                for (i = 0; i < z; i++) {
                    p = strchr(pr[i].r, target);
                    if (p) {
                        *p = replace;
                    }
                }
            }
        }
    }

    printf("\nEliminate common expression:\n");
    for (i = 0; i < z; i++) {
        printf("%c = %s\n", pr[i].l, pr[i].r); 
    }

    for (i = 0; i < z; i++) {
        for (j = i + 1; j < z; j++) {
            if (pr[i].l == pr[j].l && strcmp(pr[i].r, pr[j].r) == 0) {
                pr[j].l = '\0';         
                strcpy(pr[j].r, nu);     
            }
        }
    }

    printf("\nOptimized code:\n");
    for (i = 0; i < z; i++) {
        if (pr[i].l != '\0') {
            printf("%c = %s\n", pr[i].l, pr[i].r);
        }
    }
}


