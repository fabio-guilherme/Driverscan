//
//  crypto.h
//  JavaToC
//
//  Created by Fabio Guilherme on 28.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef crypto_h
#define crypto_h

#include <stdio.h>

unsigned char *encryptChunk(signed char plainText[], char publicKey[], int len);

#endif /* crypto_h */
