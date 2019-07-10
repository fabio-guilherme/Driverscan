//
//  drivingLicense.c
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include "drivingLicense.h"

drivingLicense drivingLicense_start(
                      char *certificateNumber,
                      char *countryOfIssue) {
    drivingLicense dl;
    dl.certificateNumber = certificateNumber;
    dl.countryOfIssue = countryOfIssue;
    return dl;
}
/*
public String getCertificateNumber() {
    return certificateNumber;
}

public String getCountryOfIssue() {
    return countryOfIssue;
}

@Override
public String toString() {
    return "DrivingLicense{" +
    "certificateNumber='" + certificateNumber + '\'' +
    ", countryOfIssue='" + countryOfIssue + '\'' +
    '}';
}
*/
