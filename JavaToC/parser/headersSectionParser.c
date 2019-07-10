//
//  headersSectionParser.c
//  JavaToC
//
//  Created by Fabio Guilherme on 30.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include "headersSectionParser.h"
#include "barcodeLicenseParser.h"
#include "barcodeLicenseConstants.h"

static int stringLength;
static int binaryLength;

globalBarcodeLicenseDto *headersSectionParser_parse(globalBarcodeLicenseDto *dto, BYTE *byteStream) {
    char *headerPrefix = readString(0, (int) strlen(BLOCK_1));
    
    if (!isValidBlockPrefix(headerPrefix, BLOCK_1)) {
        byteStream += HEADER_LENGTH; //skip if not valid
        return dto;
    } else {
        char **headers = malloc(sizeof(char[HEADER_LENGTH]));
        char *header = readString(0, HEADER_LENGTH);
        headers[0] = malloc(sizeof(char) * HEADER_LENGTH);
        strcpy(headers[0], header);
        sscanf(header + 10, "%2x", &stringLength);
        stringLength *= 2;
        sscanf(header + 14, "%2x", &binaryLength);
        binaryLength *= 2;
        dto->headers = headers;
        return dto;
    }
}

int get_stringLength() {
    return stringLength;
}

int get_binaryLength() {
    return binaryLength;
}
