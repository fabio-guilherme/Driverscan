//
//  card.h
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef card_h
#define card_h

#include <stdio.h>
#include <time.h>

typedef struct {
    char *issueNumber;
    struct tm validFrom;
    struct tm validUntil;
} card;

card card_start(
                char *issueNumber,
                char *validFrom,
                char *validUntil);

char *card_toString(card c);

#endif /* card_h */
