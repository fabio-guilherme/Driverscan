//
//  barCodeLicenseDecipher.c
//  JavaToC
//
//  Created by Fabio Guilherme on 25.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include "keys.h"
#include "barCodeLicenseDecipher.h"
#include "barCodeLicenseDecipherHelper.h"
#include "crypto.h"

char *encipherAsHexString(char dataHex[], int len);
unsigned char *encipherAsRawBytes(char dataHex[], int len);
signed char *cipherByChunkSize(signed char inBytes[], int len);

const unsigned char SKIP = 6;

char *encipherAsHexString(char dataHex[], int len) {
    unsigned char *rb = encipherAsRawBytes(dataHex, len + 1);
    return convertToHexString(rb, (len / 2) - SKIP);
}

unsigned char *encipherAsRawBytes(char dataHex[], int len) {
    signed char *data = convertFromHexToBytes(dataHex, len);
    return cipherByChunkSize(data, (len - 1) / 2);
}

signed char *cipherByChunkSize(signed char inBytes[], int len) {
    int chunkSize = 128;
    int remainder = len;
    int posRead = 0;
    int posWrite = 0;
    int tmpLength;
    
    signed char *tmp;
    unsigned char *encoded;
    signed char *output = malloc(sizeof(char) * (len - 6));
    
    if (remainder > SKIP) {
        posRead += sizeof(signed char) * SKIP;
        remainder -= SKIP;
    }
    while (remainder > 0) {
        tmpLength = (remainder > chunkSize ? chunkSize : remainder);
        tmp = inBytes + posRead;
        if (tmpLength == 74) {
            encoded = encryptChunk(tmp, b64encodedFinal, tmpLength);

        } else {
            encoded = encryptChunk(tmp, b64encoded, tmpLength);
        }
        remainder -= tmpLength;
        memcpy(output + posWrite, encoded, tmpLength);
        posWrite += sizeof(signed char) * tmpLength;
        posRead += sizeof(signed char) * tmpLength;
    }
    return output;
}


