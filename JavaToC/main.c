//
//  main.c
//  JavaToC
//
//  Created by Fabio Guilherme on 25.06.19.
//  Copyright © 2019 Fabio Guilherme. All rights reserved.
//

#include <stdio.h>
#include "decipher.h"

int main(int argc, const char * argv[]) {
    char hexInput[] = "019B094500004A4ED27390D1FF21376EDCB5C897EA27DF8D37A2FFE1C0FC6B2D53631CA7730634FF1BB52336981ECA4EBF1367B5EAF0577F067357128D9AE02763757A5E829CBF3BFDD0572D6E0B1585DEFDF6EEE6347759295E1DFEAB22ED32ECC62C903C507F384C4BF907E081BD9AE446602432FFCD7C42EE9498C274105DB739A96F836E6B9471A933E7580DD79FFC1F013C92AA0B967F21A4261BB700E2ED7D631C7A7D1B5B1171403E38D1E01674A8073B0E99E50379A260E3521DC5C245CBA11020D564E1DE4BD22F0D5CA9899AF02641EC6361E889FCB805C43C3A11BC9D14229B4382C3D5BFD044AA2F0EF59B4CAE5AE6C41ADACDE6D1FC1060A6226D4C4DDD19196D729141646BA8B116EC99173A66F0B721BA83AE0E62F30438A1795B8914A3252E0233FDB398D7D03E20DCAA093287B877E4241C1CB9F27A2BC6CEAE0A50033092966282A3B41A0A465E18791B1BBED823E920537912FA6BDBAB75F4484579B5FE9370D1C8C4403C7710E65F1BCCD7692922F3EABABC9FF03FDA72A586AC67F14AF6BE9B40EED0E1079314093816480C60804A6094B664F79CF37150C7B875A2676734F58CFA560CCC7337EDB5C986E48656684CA301B8674C908FE8B61B35E406317D26C57DBF51ECFCEF82DDB72BF91BCFE5AD877A56C44390F3C125A8A73887AADC2D4A58BFDA069F6C156A70C618AD3CD8B623E55435FD4B90A744DE844E15753B851EAE20C513F7A64C636756F11648824C0D47F178CA59CA67EE1DBECBB9FC59539FF05021314B23D2027C4A7D76A905B3B05AD3D208544218B36583C92E747EBC03F1C0F1957E68A97CFC07B7BAFF7D60BD7DB36B0D7E404BB11683CBCD331EB794D0D7A3AB5E2966F6A79109F3F1A5C178B74FAF2A551DCBB570B068442AFAFBE9FF620DAC66C74F81B84BEE0CDFD78EE1B242358ADB6B045D0DDA06B13FDA74CCE0ECCAA7E2233A14AD39A91420D30455D6EBDB0DD218F802AE8B45C5EF69827C8EF71071B7";
    
    drivingLicenseCard dlc = decode(hexInput);
    return 0;
}
