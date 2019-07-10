//
//  drivingLicenseCard.h
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#ifndef drivingLicenseCard_h
#define drivingLicenseCard_h

#include <stdio.h>
#include "compressedImage.h"
#include "identityDocument.h"
#include "person.h"
#include "drivingLicense.h"
#include "card.h"
#include "professionalDrivingPermit.h"
#include "vehicleClass.h"

typedef struct {
    compressedImage photoData;
    identityDocument identityDocument;
    person person;
    drivingLicense drivingLicense;
    card card;
    professionalDrivingPermit professionalDrivingPermit;
    vehicleClass *vehicleClasses;
} drivingLicenseCard;

drivingLicenseCard drivingLicenseCard_start(
                                            identityDocument identityDocument,
                                            person person,
                                            drivingLicense drivingLicense,
                                            card card,
                                            professionalDrivingPermit professionalDrivingPermit,
                                            vehicleClass *vehicleClasses,
                                            compressedImage photoData);

#endif /* drivingLicenseCard_h */
