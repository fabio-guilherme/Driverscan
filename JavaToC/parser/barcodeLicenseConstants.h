//
//  barcodeLicenseConstants.h
//  JavaToC
//
//  Created by Fabio Guilherme on 27.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef barcodeLicenseConstants_h
#define barcodeLicenseConstants_h

#include <stdio.h>

//working with hex string so lengths will be hex length
static const char *STRINGS_DELIMITER_BASIC = "e0";
static const char *STRINGS_DELIMITER_NEXT_EMPTY = "e1";
static const int HEADER_LENGTH = 20; //10 bytes

static const char *BLOCK_1 = "0102030405";
static const char *BLOCK_2 = "020406080a";
static const char *BLOCK_3 = "04080c1014";
static const char *BLOCK_4 = "0810182028";
static const char *BLOCK_5 = "1020304050";
static const char *BLOCK_6 = "2040600020";

int getTotalLength(void);

#endif /* barcodeLicenseConstants_h */
