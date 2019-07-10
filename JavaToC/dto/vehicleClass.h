//
//  vehicleClass.h
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef vehicleClass_h
#define vehicleClass_h

#include <stdio.h>
#include <time.h>

typedef struct {
    char *code;
    char *vehicleRestriction;
    struct tm firstIssueDate;
} vehicleClass;

vehicleClass vehicleClass_start(
                                char *code,
                                char *vehicleRestriction,
                                char *firstIssueDate);

#endif /* vehicleClass_h */
