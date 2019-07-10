//
//  stringsSectionParser.c
//  JavaToC
//
//  Created by Fabio Guilherme on 30.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include "stringsSectionParser.h"
#include "barcodeLicenseParser.h"
#include "BarCodeLicenseDecipherHelper.h"

static char *data;

void stringsSectionParser_start(int sectionLength) {
    data = readString(0, sectionLength);
}

char *scan(int len) {
    char *value = substring(data, 0, len);
    data += len;
    return value;
}

bool isDelimeter(char *value) {
    return (strcasecmp(value, "e0") == 0 || strcasecmp(value, "e1") == 0);
}

char *readNext() {
    char *value = "";
    char *toRet = NULL;
    int len = 0;
    char *ptr;
    while (!isDelimeter(value)) {
        value = scan(2);
        if (!isDelimeter(value)) {
            int hex = (int) strtol(value, &ptr, 16);
            toRet = (char*) realloc(toRet, ++len);
            if (toRet == NULL) {
                printf( "Failed to read next");
                return NULL;
            }
            toRet[len - 1] = (char) hex;
        }
    }
    return (toRet == NULL ? "" : toRet);
}

globalBarcodeLicenseDto *stringsSectionParser_parse(globalBarcodeLicenseDto *dto) {
    int size;
    
    char **vehicleCodes = NULL; //up to 4 vehicle codes
    size = 0;
    for (int i = 0; i < VEHICLE_CODES_LEN; i++) {
        vehicleCodes = addString(vehicleCodes, &size, readNext());
    }

    char *surname = readNext();
    char *initials = readNext();
    char *prDPCode = readNext();
    char *idCountryIssued;

    if (strstr(prDPCode, ",") != NULL) {
        idCountryIssued = readNext();
    } else {
        idCountryIssued = prDPCode;
        prDPCode = "";
    }
    
    char *driversCountryIssued = readNext();

    char **vehicleRestriction = NULL;
    size = 0;
    for (int i = 0; i < VEHICLE_CODES_LEN; i++) {
        vehicleRestriction = addString(vehicleRestriction, &size, readNext());
    }
    
    char *licenseNumber = readNext();
    if (strcasecmp(licenseNumber, "") == 0) {
        licenseNumber = readNext();
    }
    
    int idNumberLen = 13 * 2; //idNumber 13 long
    char *idNumber = (char*) convertFromHexToBytes(scan(idNumberLen), idNumberLen + 1);
    
    dto->vehicleCodes = vehicleCodes;
    dto->surname = surname;
    dto->initials = initials;
    dto->prDPCode = prDPCode;
    dto->idCountryIssued = idCountryIssued;
    dto->driversCountryIssued = driversCountryIssued;
    dto->vehicleRestriction = vehicleRestriction;
    dto->licenseNumber = licenseNumber;
    dto->idNumber = idNumber;
    
    return dto;
}
