//
//  person.c
//  JavaToC
//
//  Created by Fabio Guilherme on 01.07.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include "person.h"
#include "helper.h"

 person person_start(
                 char *surname,
                 char *initials,
                 char **driverRestrictions,
                 char *dateOfBirth,
                 char *preferenceLanguage,
                 char *gender) {
     person p;
     p.surname = surname;
     p.initials = initials;
     p.driverRestrictions = driverRestrictions;
     p.dateOfBirth = parseDate(dateOfBirth);
     p.preferenceLanguage = preferenceLanguage;
     p.gender = gender;
     return p;
 }
/*
 public String getSurname() {
 return surname;
 }
 
 public String getInitials() {
 return initials;
 }
 
 public String[] getDriverRestrictions() {
 return driverRestrictions;
 }
 
 public Date getDateOfBirth() {
 return dateOfBirth;
 }
 
 public String getPreferenceLanguage() {
 return preferenceLanguage;
 }
 
 public String getGender() {
 return gender;
 }
 
 @Override
 public String toString() {
 return "Person{" +
 "surname='" + surname + '\'' +
 ", initials='" + initials + '\'' +
 ", driverRestrictions=" + Arrays.toString(driverRestrictions) +
 ", dateOfBirth=" + dateOfBirth +
 ", preferenceLanguage='" + preferenceLanguage + '\'' +
 ", gender='" + gender + '\'' +
 '}';
 }
*/
