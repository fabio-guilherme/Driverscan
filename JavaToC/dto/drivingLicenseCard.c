//
//  drivingLicenseCard.c
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include "drivingLicenseCard.h"

drivingLicenseCard drivingLicenseCard_start(
                                            identityDocument identityDocument,
                                            person person,
                                            drivingLicense drivingLicense,
                                            card card,
                                            professionalDrivingPermit professionalDrivingPermit,
                                            vehicleClass *vehicleClasses,
                                            compressedImage photoData) {
    drivingLicenseCard dlc;
    dlc.identityDocument = identityDocument;
    dlc.person = person;
    dlc.drivingLicense = drivingLicense;
    dlc.card = card;
    dlc.professionalDrivingPermit = professionalDrivingPermit;
    dlc.vehicleClasses = vehicleClasses;
    dlc.photoData = photoData;
    return dlc;
}
/*
 public IdentityDocument getIdentityDocument() {
 return identityDocument;
 }
 
 public Person getPerson() {
 return person;
 }
 
 public DrivingLicense getDrivingLicense() {
 return drivingLicense;
 }
 
 public Card getCard() {
 return card;
 }
 
 public ProfessionalDrivingPermit getProfessionalDrivingPermit() {
 return professionalDrivingPermit;
 }
 
 public VehicleClass[] getVehicleClasses() {
 return vehicleClasses;
 }
 
 public CompressedImage getPhotoData() throws Exception {
 return photoData;
 }
 */
