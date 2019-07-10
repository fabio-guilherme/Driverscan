//
//  helper.c
//  JavaToC
//
//  Created by Fabio Guilherme on 25.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "helper.h"

BYTE *stringToByteArray(char* input, int len);

//function to convert string to byte array
BYTE *stringToByteArray(char* input, int len)
{
    int i;
    BYTE* output = malloc(sizeof(BYTE) * len);
    
    i = 0;
    while(input[i] != '\0')
    {
        output[i] = input[i];
        i++;
    }
    return output;
}

char *substring(char *string, int pos, int len) {
    char *value = malloc(sizeof(char) * len);
    memcpy(value, &string[pos], len);
    return value;
}

char **addString(char **array, int *size, const char *string) {
    char **newArray = realloc(array, (*size + 1) *sizeof(char*) );
    newArray[*size] = malloc(strlen(string) + 1);
    strcpy(newArray[*size], string);
    *size += 1;
    return newArray;
}

struct tm parseDate(char *date) {
    struct tm str_time;
    str_time.tm_year = (int) (atoi(substring(date, 0, 4)) - 1900);;
    str_time.tm_mon = (int) (atoi(substring(date, 0 + 4, 2)) - 1);;
    str_time.tm_mday = (int) atoi(substring(date, 0 + 4 + 2, 2));
    str_time.tm_hour = 0;
    str_time.tm_min = 0;
    str_time.tm_sec = 0;
    return str_time;
}

char *stringnum(int num) {
    char *str = malloc(sizeof(32));
    sprintf(str, "%d", num);
    return str;
}

char *stringdate(struct tm date) {
    char *str = malloc(sizeof(10));
    str = stringcat(5, stringnum(date.tm_year + 1900), "-", stringnum(date.tm_mon + 1), "-", stringnum(date.tm_mday));
    return str;
}

char *stringcat(int count, ...)
{
    va_list ap;
    size_t  len = 0;
    
    if (count < 1)
        return NULL;
    
    // First, measure the total length required.
    va_start(ap, count);
    for (int i=0; i < count; i++) {
        const char *s = va_arg(ap, char *);
        len += strlen(s);
    }
    va_end(ap);
    
    // Allocate return buffer.
    char *ret = malloc(len + 1);
    if (ret == NULL)
        return NULL;
    
    // Concatenate all the strings into the return buffer.
    char *dst = ret;
    va_start(ap, count);
    for (int i=0; i < count; i++) {
        const char *src = va_arg(ap, char *);
        
        // This loop is a strcpy.
        while ((*dst++ = *src++));
        dst--;
    }
    va_end(ap);
    return ret;
}
