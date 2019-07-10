//
//  decipher.c
//  JavaToC
//
//  Created by Fabio Guilherme on 25.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include <string.h>
#include "decipher.h"
#include "keys.h"
#include "helper.h"
#include "crypto.h"
#include "barCodeLicenseDecipher.h"
#include "barcodeLicenseParser.h"

drivingLicenseCard decode(char hexInput[]) {
    int len = (int) strlen(hexInput);
    char *output = encipherAsHexString(hexInput, len);
    //printf("output = %s\n", output);
    int outputLen = (len / 2 - 6) * 2;
    BYTE *bytes = stringToByteArray(output, outputLen);
    barcodeLicenseParser_start(bytes, outputLen, output);
    globalBarcodeLicenseDto dto = barcodeLicenseParser_parse();
    
    //to convert to DrivingLicenseCard
    return convert(&dto);
}
