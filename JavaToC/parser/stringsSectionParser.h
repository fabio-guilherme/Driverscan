//
//  stringsSectionParser.h
//  JavaToC
//
//  Created by Fabio Guilherme on 30.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef stringsSectionParser_h
#define stringsSectionParser_h

#include <stdio.h>
#include "globalBarcodeLicenseDto.h"

void stringsSectionParser_start(int sectionLength);
globalBarcodeLicenseDto *stringsSectionParser_parse(globalBarcodeLicenseDto *dto);

#endif /* stringsSectionParser_h */
