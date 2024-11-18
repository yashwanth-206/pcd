
#include <stdio.h>
#include <string.h>

struct op {
    char l;         // Left operand
    char r[20];    // Right operand
} op[10], pr[10]; // Arrays to hold operations and optimized results

void main() {
    int a, i, k, j, n, z = 0, m, q;
    char *p, *l, *tem, temp, t;
    char nu[] = "\0"; // Null string for empty initialization

    printf("\nEnter the number of values: ");
    scanf("%d", &n);

    // Input operations
    for (i = 0; i < n; i++) {
        printf("\nLeft: ");
        scanf(" %c", &op[i].l); // Read a single character for left operand
        printf("Right: ");
        scanf("%s", op[i].r);    // Read the right operand as a string
    }

    printf("\nIntermediate code:\n");
    for (i = 0; i < n; i++) {
        printf("%c = %s\n", op[i].l, op[i].r); // Print intermediate code
    }

    // Dead code elimination
    for (i = 0; i < n; i++) {
        temp = op[i].l;
        p = NULL;
        for (j = 0; j < n; j++) {
            p = strchr(op[j].r, temp);
            if (p) {
                pr[z].l = op[i].l;
                strcpy(pr[z].r, op[i].r);
                z++;
                break;
            }
        }
    }

    printf("\nAfter dead code elimination:\n");
    for (k = 0; k < z; k++) {
        printf("%c = %s\n", pr[k].l, pr[k].r); // Print after dead code elimination
    }

    // Eliminate common expressions
    for (m = 0; m < z; m++) {
        tem = pr[m].r;
        for (j = m + 1; j < z; j++) {
            p = strstr(tem, pr[j].r);
            if (p) {
                pr[j].l = pr[m].l;
                for (i = 0; i < z; i++) {
                    if (l) {
                        a = l - pr[i].r;
                        pr[i].r[a] = pr[m].l; // Update based on common expression
                    }
                }
            }
        }
    }

    printf("\nEliminate common expression:\n");
    for (i = 0; i < z; i++) {
        printf("%c = %s\n", pr[i].l, pr[i].r); // Print after eliminating common expressions
    }

    // Final optimization
    for (i = 0; i < z; i++) {
        for (j = i + 1; j < z; j++) {
            q = strcmp(pr[i].r, pr[j].r);
            if ((pr[i].l == pr[j].l) && !q) {
                pr[i].l = '\0';          // Mark for elimination
                strcpy(pr[i].r, nu);     // Clear the right operand
            }
        }
    }

    printf("\nOptimized code:\n");
    for (i = 0; i < z; i++) {
        if (pr[i].l != '\0') {
            printf("%c = %s\n", pr[i].l, pr[i].r); // Print the final optimized code
        }
    }
}

/*Enter the number of values: 5

Left: a
Right: 10

Left: b
Right: 20

Left: c
Right: a+b

Left: d
Right: a+b

Left: e
Right: a+d*/