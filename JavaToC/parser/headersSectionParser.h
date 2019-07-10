//
//  headersSectionParser.h
//  JavaToC
//
//  Created by Fabio Guilherme on 30.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef headersSectionParser_h
#define headersSectionParser_h

#include <stdio.h>
#include "helper.h"
#include "globalBarcodeLicenseDto.h"

globalBarcodeLicenseDto *headersSectionParser_parse(globalBarcodeLicenseDto *dto, BYTE *byteStream);
int get_stringLength(void);
int get_binaryLength(void);

#endif /* headersSectionParser_h */
