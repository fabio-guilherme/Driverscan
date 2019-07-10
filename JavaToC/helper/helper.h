//
//  helper.h
//  JavaToC
//
//  Created by Fabio Guilherme on 25.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef helper_h
#define helper_h

#include <stdio.h>
#include <time.h>

typedef signed char BYTE;
BYTE *stringToByteArray(char* input, int len);
char *substring(char *string, int pos, int len);
char **addString(char **array, int *size, const char *string);
struct tm parseDate(char *date);
char *stringdate(struct tm date);
char *stringnum(int num);
char *stringcat(int count, ...);

#endif /* helper_h */
