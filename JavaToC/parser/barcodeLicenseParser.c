//
//  barcodeLicenseParser.c
//  JavaToC
//
//  Created by Fabio Guilherme on 28.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include "barcodeLicenseParser.h"
#include "barcodeLicenseConstants.h"
#include "headersSectionParser.h"
#include "stringsSectionParser.h"
#include "binaryDataSectionParser.h"

bool isValid(char *inString);
globalBarcodeLicenseDto applyParsers(globalBarcodeLicenseDto dto);

static BYTE *byteStream;
static int byteStreamRead;
static int byteStreamLen;

void barcodeLicenseParser_start(BYTE *bytes, int len, char *inString) {
    if (!isValid(inString)) {
        printf("\nWARNING : NOT VALID INPUT\n");
    }
    byteStream = bytes;
    byteStreamRead = 0;
    byteStreamLen = len;
}


bool isValidBlockPrefix(char *inBlockPrefix, char *blockPrefixExpected) {
    return (inBlockPrefix != NULL && strcasecmp(inBlockPrefix, blockPrefixExpected) == 0);
}

 char *readString(int off, int len) {
     signed char *b = malloc(sizeof(signed char) * len);
     if (byteStreamRead + len > byteStreamLen) {
         return "";
     }
     memcpy(b, byteStream + byteStreamRead + off, len);
     byteStreamRead += len;
     b[len] = '\0';
     return (char*) b;
 }

globalBarcodeLicenseDto barcodeLicenseParser_parse() {
    globalBarcodeLicenseDto dto = globalBarcodeLicenseDto_start();
    return applyParsers(dto);
}

bool isValid(char *inString) {
    return inString != NULL && strlen(inString) == getTotalLength();
}

globalBarcodeLicenseDto applyParsers(globalBarcodeLicenseDto dto) {
    headersSectionParser_parse(&dto, byteStream);
    stringsSectionParser_start(get_stringLength());
    stringsSectionParser_parse(&dto);
    binaryDataSectionParser_parse(&dto);
    return dto;
}

int byteStreamAvailable() {
    return byteStreamLen - byteStreamRead;
}
