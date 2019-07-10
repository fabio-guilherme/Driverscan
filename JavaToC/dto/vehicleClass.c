//
//  vehicleClass.c
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include "vehicleClass.h"
#include "helper.h"

vehicleClass vehicleClass_start(
                     char *code,
                     char *vehicleRestriction,
                     char *firstIssueDate) {
    vehicleClass vc;
    vc.code = code;
    vc.vehicleRestriction = vehicleRestriction;
    vc.firstIssueDate = parseDate(firstIssueDate);
    return vc;
 }
/*
 public String getCode() {
 return code;
 }
 
 public String getVehicleRestriction() {
 return vehicleRestriction;
 }
 
 public Date getFirstIssueDate() {
 return firstIssueDate;
 }
 
 @Override
 public String toString() {
 return "VehicleClass{" +
 "code='" + code + '\'' +
 ", vehicleRestriction='" + vehicleRestriction + '\'' +
 ", firstIssueDate=" + firstIssueDate +
 '}';
 }
*/
