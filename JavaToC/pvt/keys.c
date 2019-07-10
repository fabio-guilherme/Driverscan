//
//  keys.c
//  JavaToC
//
//  Created by Fabio Guilherme on 25.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include "keys.h"

//the two keys given in pkcs#8 format
char b64encoded_original[] = "MIGsMA0GCSqGSIb3DQEBAQUAA4GaADCBlgKBgQDKnxjvbD8/pMWkYf6lSrGUBrpezXRtYKJ0ktyj1047XB0xX3sQODJBgJsCnrvV3k0RYDDMV/fVpsmhbzc7sUpQhSP36ApMdE2QhWY6ShRy168sVq5BtQZffvoCk70yeK1pNUb58WIZt5/0caNjaCTP/NtjqO2AWea5pPDbiVOBywIQGHCS2mRUzrGFPmkV+EZqBQ==";
char b64encodedFinal_original[] = "MHMwDQYJKoZIhvcNAQEBBQADYgAwXwJLALQEoN8R0crP8aGgSNTVc/lTpixYPXSSWSdWGm16HisUBCUmr3C1UFRzkOpux0jTD9uBrbSQ4MNqGYa0BLL19p712htmPllQkTDnAhAwnP7ZcZ/ipeIMm7RHZTgr";

const char b64encoded[]="-----BEGIN PUBLIC KEY-----\n"\
    "MIGsMA0GCSqGSIb3DQEBAQUAA4GaADCBlgKBgQDKnxjvbD8/pMWkYf6lSrGUBrpe\n"\
    "zXRtYKJ0ktyj1047XB0xX3sQODJBgJsCnrvV3k0RYDDMV/fVpsmhbzc7sUpQhSP3\n"\
    "6ApMdE2QhWY6ShRy168sVq5BtQZffvoCk70yeK1pNUb58WIZt5/0caNjaCTP/Ntj\n"\
    "qO2AWea5pPDbiVOBywIQGHCS2mRUzrGFPmkV+EZqBQ==\n"\
    "-----END PUBLIC KEY-----\n";
const char b64encodedFinal[] = "-----BEGIN PUBLIC KEY-----\n"\
    "MHMwDQYJKoZIhvcNAQEBBQADYgAwXwJLALQEoN8R0crP8aGgSNTVc/lTpixYPXSS\n"\
    "WSdWGm16HisUBCUmr3C1UFRzkOpux0jTD9uBrbSQ4MNqGYa0BLL19p712htmPllQ\n"\
    "kTDnAhAwnP7ZcZ/ipeIMm7RHZTgr\n"\
    "-----END PUBLIC KEY-----\n";
