//
// Created by uartman on 9/3/21.
//

#ifndef KERNEL_BDA_H
#define KERNEL_BDA_H

#include <stdint.h>

struct BDA_COM_Table {
    uint16_t COM1;
    uint16_t COM2;
    uint16_t COM3;
    uint16_t COM4;
};

struct BDA_LPT_Table {
    uint16_t LPT1;
    uint16_t LPT2;
    uint16_t LPT3;
};

struct BDA_COM_Table *bda_com_table();
struct BDA_LPT_Table *bda_lpt_table();


#endif //KERNEL_BDA_H
