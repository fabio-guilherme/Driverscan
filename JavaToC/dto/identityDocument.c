//
//  identityDocument.c
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include "identityDocument.h"

identityDocument identityDocument_start(
                        char *number,
                        char *type,
                        char *countryOfIssue) {
    identityDocument id;
    id.number = number;
    id.type = type;
    id.countryOfIssue = countryOfIssue;
    return id;
}
/*
public String getNumber() {
    return number;
}

public String getType() {
    return type;
}

public String getCountryOfIssue() {
    return countryOfIssue;
}

@Override
public String toString() {
    return "IdentityDocument{" +
    "number='" + number + '\'' +
    ", type='" + type + '\'' +
    ", countryOfIssue='" + countryOfIssue + '\'' +
    '}';
    }
*/
