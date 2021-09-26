//
// Created by uartman on 9/3/21.
//

#include "bda.h"

struct BDA_COM_Table *bda_com_table() {
    return (struct BDA_COM_Table *) 0x0400;
}

struct BDA_LPT_Table *bda_lpt_table() {
    return (struct BDA_LPT_Table *) 0x0408;
}
