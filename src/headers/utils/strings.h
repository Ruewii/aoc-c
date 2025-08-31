#ifndef STRINGS_H
#define STRINGS_H

char *slice(const char *str, int start, int end);

char **split(char *str, char sep);

char *trim(char *str);

#endif
