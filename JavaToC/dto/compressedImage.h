//
//  compressedImage.h
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef compressedImage_h
#define compressedImage_h

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    signed char *imageData;
    bool isTopDownImage;
} compressedImage;

compressedImage compressedImage_start(
                                      signed char *imageData,
                                      bool isTopDownImage);

#endif /* compressedImage_h */
