//
//  barcodeLicenseParser.h
//  JavaToC
//
//  Created by Fabio Guilherme on 28.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef barcodeLicenseParser_h
#define barcodeLicenseParser_h

#include <stdio.h>
#include <stdbool.h>
#include "helper.h"
#include "globalBarcodeLicenseDto.h"

void barcodeLicenseParser_start(BYTE *bytes, int len, char *inString);
globalBarcodeLicenseDto barcodeLicenseParser_parse(void);
char *readString(int off, int len);
bool isValidBlockPrefix(char *inBlockPrefix, char *blockPrefixExpected);
int byteStreamAvailable(void);

#endif /* barcodeLicenseParser_h */
