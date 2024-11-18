#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_VARIABLES 25
#define MAX_LENGTH 100
#define DEFAULT_VALUE "garbage"

struct SymbolTable {
    int lineNo;
    char variable[25];
    char dataType[25];
    char value[25];
} symbols[MAX_VARIABLES];

int main() {
    int symbolCount = 0, lineNo = 0;
    char input[MAX_LENGTH], currentType[25];

    while (1) {
        printf("Enter a declaration (or 'exit' to finish): ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Exit condition
        if (strcmp(input, "exit") == 0)
            break;

        // Extract datatype
        char *token = strtok(input, " ");
        if (token == NULL || (strcmp(token, "int") != 0 && strcmp(token, "float") != 0 && strcmp(token, "char") != 0)) {
            printf("Invalid declaration. Please try again.\n");
            continue;
        }

        strcpy(currentType, token); // Store the datatype
        lineNo++; // Increment line number for new declaration

        // Process variables
        while ((token = strtok(NULL, ",;")) != NULL) {
            // Skip leading whitespace
            while (isspace(*token))
                token++;

            if (symbolCount >= MAX_VARIABLES) {
                printf("Symbol table limit reached.\n");
                break;
            }

            symbols[symbolCount].lineNo = lineNo;
            strcpy(symbols[symbolCount].dataType, currentType);

            // Check for assignment
            char *equalsSign = strchr(token, '=');
            if (equalsSign != NULL) {
                *equalsSign = '\0'; // Split at '='
                strcpy(symbols[symbolCount].variable, token); // Variable name
                strcpy(symbols[symbolCount].value, equalsSign + 1); // Value
            } else {
                strcpy(symbols[symbolCount].variable, token); // Variable name
                strcpy(symbols[symbolCount].value, DEFAULT_VALUE); // Default value
            }
            symbolCount++;
        }
    }

    // Display the symbol table
    printf("\nSYMBOL TABLE MANAGEMENT\n");
    printf("Variable\tDatatype\tLine No.\tValue\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < symbolCount; i++) {
        printf("%s\t\t%s\t\t%d\t\t%s\n",
               symbols[i].variable,
               symbols[i].dataType,
               symbols[i].lineNo,
               symbols[i].value);
    }

    return 0;
}

/*
Example Inputs:
int a, b = 5;
float c;
char d = 'a';
exit
*/

