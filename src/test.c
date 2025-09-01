#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/utils/array.h"
#include "headers/utils/strings.h"

int main() {
    char *s = "hello earth";
    char *d = slice(s, 1, 3);

    printf("||%s||\n", d);
}
