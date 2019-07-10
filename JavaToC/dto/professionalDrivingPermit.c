//
//  professionalDrivingPermit.c
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include "professionalDrivingPermit.h"
#include "helper.h"

professionalDrivingPermit professionalDrivingPermit_start(
                                 char *category,
                                 char *dateValidUntil) {
    professionalDrivingPermit pdp;
    pdp.category = category;
    pdp.dateValidUntil = parseDate(dateValidUntil);
    return pdp;
}
/*
public String getCategory() {
    return category;
}

public Date getDateValidUntil() {
    return dateValidUntil;
}

@Override
public String toString() {
    return "ProfessionalDrivingPermit{" +
    "category='" + category + '\'' +
    ", dateValidUntil=" + dateValidUntil +
    '}';
}
*/
