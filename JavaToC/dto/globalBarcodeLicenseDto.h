//
//  globalBarcodeLicenseDto.h
//  JavaToC
//
//  Created by Fabio Guilherme on 29.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef globalBarcodeLicenseDto_h
#define globalBarcodeLicenseDto_h

#include <stdio.h>
#include "drivingLicenseCard.h"

static const int VEHICLE_CODES_LEN = 3;

typedef struct {
    //headers section
    char **headers;
    //strings section
    char **vehicleCodes;
    char *surname;
    char *initials;
    char *prDPCode;
    char *idCountryIssued;
    char *driversCountryIssued;
    char **vehicleRestriction;
    char *licenseNumber;
    char *idNumber;
    //binary data section
    char *zaId;
    char **licenseCodeIssueDates;
    char **driverRestrictionCodes;
    char **prDPExpiryDate;
    char *licenseIssueNumber;
    char **birthDate;
    char **licenseValidFrom;
    char **licenseValidTo;
    char *gender;
    signed char *imageData;
} globalBarcodeLicenseDto;

globalBarcodeLicenseDto globalBarcodeLicenseDto_start(void);
drivingLicenseCard convert(globalBarcodeLicenseDto *dto);

#endif /* globalBarcodeLicenseDto_h */
