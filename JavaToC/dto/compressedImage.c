//
//  compressedImage.c
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include "compressedImage.h"

compressedImage compressedImage_start(
                       signed char *imageData,
                       bool isTopDownImage) {
    compressedImage ci;
    ci.imageData = imageData;
    ci.isTopDownImage = isTopDownImage;
    return ci;
}
/*
public byte[] getImageData() {
    return imageData;
}

public boolean getIsTopDownImage() {
    return isTopDownImage;
    }
 */
