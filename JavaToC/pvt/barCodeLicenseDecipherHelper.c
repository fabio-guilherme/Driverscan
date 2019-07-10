//
//  barCodeLicenseDecipherHelper.c
//  JavaToC
//
//  Created by Fabio Guilherme on 25.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include "barCodeLicenseDecipherHelper.h"

signed char *convertFromHexToBytes(char param[], int len);
char *addHexIdentifier(char param[], int len);

signed char *convertFromHexToBytes(char param[], int len) {
    int bigLen = sizeof(char) * len * 2 - 1;
    char string[bigLen];
    
    char *first = strstr(param, "0x");
    char *second = strstr(param + 2, "0x");
    
    if (first == NULL && second == NULL) {
        strcpy(string, addHexIdentifier(param, len));
    } else if (first == param && second == NULL) {
        strcpy(string, addHexIdentifier(param + 2, len));
    } else {
        strcpy(string, param);
    }
    int smallLen = (len - 1) / 2 + 1;
    signed char *bytes = malloc(smallLen);
    
    char *pos = param;
    
    for (size_t count = 0; count < smallLen - 1; count++) {
        sscanf(pos, "%2hhx", &bytes[count]);
        pos += 2;
    }
    
    return bytes;
}


char *addHexIdentifier(char param[], int len) {
    char *buffer = malloc(sizeof(char) * len * 2 - 1);
    
    for (int i = 0; i < len - 1; i += 2) {
        strcat(buffer, "0x");
        char* substr = malloc(2);
        strncpy(substr, param + i, 2);
        strcat(buffer, substr);
    }
    return buffer;
}

char *convertToHexString(unsigned char b[], int len) {
    char *result = malloc(sizeof(char) * len * 2);
    
    for (int i = 0; i < len; i++) {
        sprintf(&result[i*2], "%02x", b[i]);
    }
    return result;
}
