#ifndef STRINGS_H
#define STRINGS_H

#include "array.h"

char *slice(const char *str, int start, int end);

StringArray split(const char *str, char sep);

char *trim(char *str);

#endif
