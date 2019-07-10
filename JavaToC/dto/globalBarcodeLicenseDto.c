//
//  globalBarcodeLicenseDto.c
//  JavaToC
//
//  Created by Fabio Guilherme on 29.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include "globalBarcodeLicenseDto.h"
#include "barcodeLicenseConstants.h"
#import <stdlib.h>

vehicleClass *getVehicleClasses(globalBarcodeLicenseDto *dto);

globalBarcodeLicenseDto globalBarcodeLicenseDto_start() {
    globalBarcodeLicenseDto dto;
    dto.headers = NULL;
    dto.vehicleCodes = NULL;
    dto.surname = NULL;
    dto.initials = NULL;
    dto.prDPCode = NULL;
    dto.idCountryIssued = NULL;
    dto.driversCountryIssued = NULL;
    dto.vehicleRestriction = NULL;
    dto.licenseNumber = NULL;
    dto.idNumber = NULL;
    dto.zaId = NULL;
    dto.licenseCodeIssueDates = NULL;
    dto.driverRestrictionCodes = NULL;
    dto.prDPExpiryDate = NULL;
    dto.licenseIssueNumber = NULL;
    dto.birthDate = NULL;
    dto.licenseValidFrom = NULL;
    dto.licenseValidTo = NULL;
    dto.gender = NULL;
    dto.imageData = NULL;
    return dto;
}

drivingLicenseCard convert(globalBarcodeLicenseDto *dto) {
    identityDocument identityDocument = identityDocument_start(dto->idNumber, dto->zaId, dto->idCountryIssued);

    char *preferenceLanguage = "";
    
    person person = person_start(dto->surname, dto->initials, dto->driverRestrictionCodes, dto->birthDate[0], preferenceLanguage, dto->gender);
    
    drivingLicense drivingLicense = drivingLicense_start(dto->licenseNumber, dto->driversCountryIssued);
    
    card card = card_start(dto->licenseIssueNumber, dto->licenseValidFrom[0], dto->licenseValidTo[0]);
    
    professionalDrivingPermit professionalDrivingPermit = professionalDrivingPermit_start(dto->prDPCode, dto->prDPExpiryDate[0]);
    
    vehicleClass *vehicleClasses = getVehicleClasses(dto);
    
    compressedImage photoData = compressedImage_start(dto->imageData, true);
        
    drivingLicenseCard dlc = drivingLicenseCard_start(identityDocument, person, drivingLicense, card, professionalDrivingPermit, vehicleClasses, photoData);
    return dlc;
}

vehicleClass *getVehicleClasses(globalBarcodeLicenseDto *dto) {
    vehicleClass *vehicleClasses = malloc(sizeof(vehicleClass) * VEHICLE_CODES_LEN);
    
    for (int i = 0; i < VEHICLE_CODES_LEN; i++) {
        vehicleClasses[i] = vehicleClass_start(dto->vehicleCodes[i], dto->vehicleRestriction[i], dto->licenseCodeIssueDates[i]);
    }
    return vehicleClasses;
}
/*
char *globalBarcodeLicenseDtoToString() {
    return "GlobalBarcodeLicenseDto{" +
    "\nheaders=" + Arrays.toString(headers) +
    ", \nvehicleCodes=" + Arrays.toString(vehicleCodes) +
    ", \nsurname='" + surname + '\'' +
    ", \ninitials='" + initials + '\'' +
    ", \nprDPCode='" + prDPCode + '\'' +
    ", \nidCountryIssued='" + idCountryIssued + '\'' +
    ", \ndriversCountryIssued='" + driversCountryIssued + '\'' +
    ", \nvehicleRestriction=" + Arrays.toString(vehicleRestriction) +
    ", \nlicenseNumber='" + licenseNumber + '\'' +
    ", \nidNumber='" + idNumber + '\'' +
    ", \nzaId='" + zaId + '\'' +
    ", \nlicenseCodeIssueDates=" + Arrays.toString(licenseCodeIssueDates) +
    ", \ndriverRestrictionCodes='" + Arrays.toString(driverRestrictionCodes) + '\'' +
    ", \nprDPExpiryDate=" + Arrays.toString(prDPExpiryDate) +
    ", \nlicenseIssueNumber='" + licenseIssueNumber + '\'' +
    ", \nbirthDate=" + Arrays.toString(birthDate) +
    ", \nlicenseValidFrom=" + Arrays.toString(licenseValidFrom) +
    ", \nlicenseValidTo=" + Arrays.toString(licenseValidTo) +
    ", \ngender='" + gender + '\'' +
    '}';
}
*/
