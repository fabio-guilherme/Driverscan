//
//  drivingLicense.h
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef drivingLicense_h
#define drivingLicense_h

#include <stdio.h>
#include "identityDocument.h"

typedef struct {
    char *certificateNumber;
    char *countryOfIssue;
} drivingLicense;

drivingLicense drivingLicense_start(
                                    char *certificateNumber,
                                    char *countryOfIssue);

#endif /* drivingLicense_h */
