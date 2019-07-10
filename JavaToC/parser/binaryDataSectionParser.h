//
//  binaryDataSectionParser.h
//  JavaToC
//
//  Created by Fabio Guilherme on 30.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef binaryDataSectionParser_h
#define binaryDataSectionParser_h

#include <stdio.h>
#include "globalBarcodeLicenseDto.h"

globalBarcodeLicenseDto *binaryDataSectionParser_parse(globalBarcodeLicenseDto *dto);

#endif /* binaryDataSectionParser_h */
