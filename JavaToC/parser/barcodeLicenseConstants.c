//
//  barcodeLicenseConstants.c
//  JavaToC
//
//  Created by Fabio Guilherme on 27.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include <string.h>
#include "barcodeLicenseConstants.h"

int getTotalCombinedSizeInBytes() {
    const char *enums[6] = {BLOCK_1, BLOCK_2, BLOCK_3, BLOCK_4, BLOCK_5, BLOCK_6};
    
    int total = 0;
    for (int i = 0; i < 6; i++) {
        total += strlen(enums[i]);
    }
    return total / 2;
}

int getTotalLength() {
    return (684 + getTotalCombinedSizeInBytes()) * 2; //684 bytes + 30 (for headers) = 714 (1428 hex)
}
