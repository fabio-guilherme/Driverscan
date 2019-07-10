//
//  person.h
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef person_h
#define person_h

#include <stdio.h>
#include <time.h>

typedef struct {
    char *surname;
    char *initials;
    char **driverRestrictions;
    struct tm dateOfBirth;
    char *preferenceLanguage;
    char *gender;
} person;

person person_start(
                    char *surname,
                    char *initials,
                    char **driverRestrictions,
                    char *dateOfBirth,
                    char *preferenceLanguage,
                    char *gender);

#endif /* person_h */
