//
//  identityDocument.h
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef identityDocument_h
#define identityDocument_h

#include <stdio.h>

typedef struct {
    char *number;
    char *type;
    char *countryOfIssue;
} identityDocument;

identityDocument identityDocument_start(
                                        char *number,
                                        char *type,
                                        char *countryOfIssue);

#endif /* identityDocument_h */
