//
//  card.c
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include "card.h"
#include "helper.h"

card card_start(
            char *issueNumber,
            char *validFrom,
            char *validUntil) {
    card c;
    c.issueNumber = issueNumber;
    c.validFrom = parseDate(validFrom);
    c.validUntil = parseDate(validUntil);
    return c;
}

char *card_toString(card c) {
    return stringcat(9, "Card{",
                    "issueNumber='", c.issueNumber, "\'",
                    ", validFrom=", stringdate(c.validFrom),
                    ", validUntil=", stringdate(c.validUntil),
                    "}\n");
}

/*
public String getIssueNumber() {
    return issueNumber;
}

public Date getValidFrom() {
    return validFrom;
}

public Date getValidUntil() {
    return validUntil;
}
*/
