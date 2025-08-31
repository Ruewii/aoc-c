#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/utils/strings.h"

void solve(char *input) {
    const char *delimeter = "\n";
    char *token = strtok(input, delimeter);
    while (token != NULL) {
        printf("||%s||\n", trim(token));
        token = strtok(NULL, delimeter);
    }
}
