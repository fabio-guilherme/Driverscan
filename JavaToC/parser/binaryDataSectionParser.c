//
//  binaryDataSectionParser.c
//  JavaToC
//
//  Created by Fabio Guilherme on 30.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#import <string.h>
#import <stdlib.h>
#include "binaryDataSectionParser.h"
#include "barcodeLicenseParser.h"
#include "barCodeLicenseDecipherHelper.h"

char **readNextBinaryDataDates(char **outArr, int len);
signed char *parseImageData(void);

globalBarcodeLicenseDto *binaryDataSectionParser_parse(globalBarcodeLicenseDto *dto) {
    char *zaId = readString(0, 2);
    
    char **licenseCodeIssueDates = NULL;
    licenseCodeIssueDates = readNextBinaryDataDates(licenseCodeIssueDates, 4);
    
    char **driverRestrictionCodes = malloc(sizeof(char) * 2);
    driverRestrictionCodes[0] = readString(0, 2);
    
    char **prDPExpiryDate = NULL;
    prDPExpiryDate = readNextBinaryDataDates(prDPExpiryDate, 1);
    
    char *licenseIssueNumber = readString(0, 2);
    
    char **birthDate = NULL;
    birthDate = readNextBinaryDataDates(birthDate, 1);
    
    char **licenseValidFrom = NULL;
    licenseValidFrom = readNextBinaryDataDates(licenseValidFrom, 1);
    
    char **licenseValidTo = NULL;
    licenseValidTo = readNextBinaryDataDates(licenseValidTo, 1);
    
    char *gender = readString(0, 2);
    
    signed char *imageData = parseImageData();
    
    dto->zaId = zaId;
    dto->licenseCodeIssueDates = licenseCodeIssueDates;
    dto->driverRestrictionCodes = driverRestrictionCodes;
    dto->prDPExpiryDate = prDPExpiryDate;
    dto->licenseIssueNumber = licenseIssueNumber;
    dto->birthDate = birthDate;
    dto->licenseValidFrom = licenseValidFrom;
    dto->licenseValidTo = licenseValidTo;
    dto->gender = gender;
    dto->imageData = imageData;
    
    return dto;
}

signed char *parseImageData() {
    int length = byteStreamAvailable();
    char *byteString = readString(0, length);
    if (length % 2 != 0) {
        byteString++; //drop first character
        length--;
    }
    return convertFromHexToBytes(byteString, length + 1);
}

//4x License code issue date. Each date either 8 nibbles, or a single a nibble.
char **readNextBinaryDataDates(char **outArr, int len) {
    char *b = "";
    int i = 0;
    while (i < len) {
        char *value = readString(0, 1);
        if (strcasecmp(value, "a") != 0) {
            b = (char*) malloc(sizeof(char) * 8);
            strcat(b, value);
            strcat(b, readString(0, 7));
        }
        //outArr[i] = b;
        outArr = addString(outArr, &i, b);
        b = "";
    }
    
    return outArr;
}
