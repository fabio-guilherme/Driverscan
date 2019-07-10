//
//  barCodeLicenseDecipherHelper.h
//  JavaToC
//
//  Created by Fabio Guilherme on 25.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef barCodeLicenseDecipherHelper_h
#define barCodeLicenseDecipherHelper_h

#include <stdio.h>

char *convertToHexString(unsigned char b[], int len);
signed char *convertFromHexToBytes(char param[], int len);

#endif /* barCodeLicenseDecipherHelper_h */
