//
//  professionalDrivingPermit.h
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef professionalDrivingPermit_h
#define professionalDrivingPermit_h

#include <stdio.h>
#include <time.h>

typedef struct {
    char *category;
    struct tm dateValidUntil;
} professionalDrivingPermit;

professionalDrivingPermit professionalDrivingPermit_start(
                                                    char *category,
                                                    char *dateValidUntil);

#endif /* professionalDrivingPermit_h */
